import subprocess
import BeautifulSoup
import urllib2
import re

bases = [
    "abstract",
    "allocation",
    "arg",
    "bool",
    "buffer",
    "bytearray",
    "capsule",
    "cell",
    "class",
    "cobject",
    "codec",
    "code",
    "complex",
    "concrete",
    "conversion",
    "datetime",
    "descriptor",
    "dict",
    "exceptions",
    "file",
    "float",
    "function",
    "gcsupport",
    "gen",
    "import",
    "index",
#    "init",
    "intro",
    "int",
    "iterator",
    "iter",
    "list",
    "long",
    "mapping",
    "marshal",
    "memory",
    "method",
    "module",
    "none",
    "number",
    "objbuffer",
    "object",
    "objimpl",
    "refcounting",
    "reflection",
    "sequence",
    "set",
    "slice",
    "string",
    "structures",
    "sys",
    "tuple",
    "typeobj",
    "type",
    "unicode",
    "utilities",
    "veryhigh",
    "weakref",
]

main_file_template="""\

#ifndef PYTHONWRAPPER_{FILE}__H
#define PYTHONWRAPPER_{FILE}__H

#include <datetime.h>
#include <marshal.h>
#include <frameobject.h>
#include <pythonrun.h>
#include <unicodeobject.h>

{CONTENTS}

#endif // PYTHONWRAPPER_API_{FILE}__H

"""

file_template="""

#ifndef PYTHONWRAPPER_{FILE}__H
#define PYTHONWRAPPER_{FILE}__H

namespace py
{{

{CONTENTS}

}}

#endif // PYTHONWRAPPER_API_{FILE}__H

"""


safe_noref_template = """\
static inline {RETURNTYPE} {FUNC}({PARMS})
{{
    return safe_noref( {ORIG}({ARGS}) );
}}\
"""

safe_ref_template = """\
static inline {REF}<{REFTYPE}> {FUNC}({PARMS})
{{
    return safe_{REF}( {ORIG}({ARGS}) );
}}\
"""

void_template = """\
static inline void {FUNC}({PARMS})
{{
    {ORIG}({ARGS});
    exception::check();
}}\
"""

proto_exceptions = {
    'Py_VISIT': None,
    'PyCodec_KnownEncoding': None,
    'PyRun_SimpleFileFlags': None,
    'PyParser_SimpleParseStringFlagsFilename':None,
    'PyOS_stricmp': 'int PyOS_stricmp(char *s1, char *s2)',
    'PyOS_strnicmp': 'int PyOS_strnicmp(char *s1, char *s2, Py_ssize_t n)',
    'PyCode_GetNumFree': 'Py_ssize_t PyCode_GetNumFree(PyCodeObject* o)',
    'PyCode_NewEmpty': 'PyCodeObject *PyCode_NewEmpty(const char *filename, const char *funcname, int firstlineno)',
    'PyFile_SetBufSize': 'void PyFile_SetBufSize(PyObject *f, int bufsize)',
    'PyGILState_GetThisThreadState' : 'PyThreadState* PyGILState_GetThisThreadState(void)',
    'PyUnicode_EncodeRawUnicodeEscape': 'PyObject* PyUnicode_EncodeRawUnicodeEscape(const Py_UNICODE *data, Py_ssize_t length)',
    'PyUnicode_RichCompare': 'PyObject* PyUnicode_RichCompare(PyObject *left, PyObject *right, int op)',
    'PyType_IS_GC': 'int PyType_IS_GC(PyTypeObject *o)',
    'PyType_HasFeature': 'int PyType_HasFeature(PyTypeObject *o, int feature)',
    'PyFile_SetEncoding':'int PyFile_SetEncoding(PyObject *p, const char *enc)',
    'PyFile_SetEncodingAndErrors':'int PyFile_SetEncodingAndErrors(PyObject *p, const char *enc, char *errors)',
    'PySeqIter_Check':'int PySeqIter_Check(PyObject* op)',
    'PyCallIter_Check':'int PyCallIter_Check(PyObject* op)',
    'PyModule_AddIntMacro':None,
    'PyModule_AddStringMacro':None,
    'PyOS_CheckStack':None,
    'PyUnicode_DecodeMBCS':None,
    'PyUnicode_DecodeMBCSStateful':None,
    'PyUnicode_EncodeMBCS':None,
    'PyUnicode_AsMBCSString':None,
    
    'PyGen_New':'PyObject* PyGen_New(stolen_ref<PyFrameObject> frame)',
    'PyList_SetItem':'int PyList_SetItem(PyObject *list, Py_ssize_t index, stolen_ref<PyObject> item)',
    'PyList_SET_ITEM':'void PyList_SET_ITEM(PyObject *list, Py_ssize_t index, stolen_ref<PyObject> item)',
    'PyModule_AddObject':'int PyModule_AddObject(PyObject *module, const char *name, stolen_ref<PyObject> value)',
    'PyTuple_SetItem':'int PyTuple_SetItem(PyObject *p, Py_ssize_t pos, stolen_ref<PyObject> o)',
    'PyTuple_SET_ITEM':'void PyTuple_SET_ITEM(PyObject *p, Py_ssize_t pos, stolen_ref<PyObject> o)',
    
    'PyString_Concat':'void PyString_Concat(replace_ref<PyObject> string, PyObject *newpart)',
    'PyString_ConcatAndDel':'void PyString_ConcatAndDel(replace_ref<PyObject> string, stolen_ref<PyObject> newpart)',
    
}

def download(base):
    f = open('/usr/share/doc/python/html/c-api/%s.html'%base, 'r')
    soup = BeautifulSoup.BeautifulSoup(f.read())
    
    return soup.findAll( 'dl', attrs={'class':'function'} )

def safe_split(s):
    paren = 0
    
    res = []
    cur = []
    
    for c in s:
        if c == ',' and paren==0:
            res.append(''.join(cur))
            cur = []
            continue

        if c=='(':
            paren += 1
            
        elif c==')':
            paren -= 1
        
        cur.append(c)
    
    if cur:
        res.append(''.join(cur).strip())
        
    return res

def split_parm(parm):
    parm = parm.strip()
    
    if parm=='ob':
        return "PyObject* ob", 'ob'
    
    if parm=='...':
        return '...', None
        
    if '(' in parm:
        m = re.match(r'[^(]*\(\*([a-zA-Z0-9_]+)', parm)
        if m:
            return parm, m.group(1)

    m = re.match(r'^(.*[^a-zA-Z0-9_])([a-zA-Z0-9_]+)(\[\])?$', parm)
    if m:
        return parm, m.group(2)

    return parm, None

def split_parms(parms):
    res = []
    
    for i, parm in enumerate( safe_split(parms) ):
        p, a = split_parm(parm)
        if p != '...' and p!='void' and not a:
            a = 'arg%d'%i
            res.append(('%s %s'%(p,a), a))
        elif a == 'class':
            res.append( (p.replace('class', 'class_'), 'class_') )
        else:
            res.append((p,a))
        
    return res

def split_proto1(proto):
    m = re.match( r'^(.*[^a-zA-Z0-9_])([a-zA-Z0-9_]+)\((.*)\)$', proto.strip())
    if m:
        returntype = m.group(1).replace(' *','*').strip()
        funcname = m.group(2)
        parms = split_parms(m.group(3))
        
        return returntype, funcname, parms
        
def split_proto(proto):
    returntype, funcname, parms = split_proto1(proto)
    if funcname in proto_exceptions and proto_exceptions[funcname]:
        return split_proto1( proto_exceptions[funcname] )
    return returntype, funcname, parms

def parse_file(base):
    soup = download(base)

    for l in soup:
        text = []
        x = l.contents[1]
        
        for z in x.findAll(text=True):
            text.append(z)
            
        rc = l.findAll(attrs={'class':'refcount'})

        refcount = rc[0].text if rc else None
        prototype = "".join( t.replace(u'&nbsp;', ' ').replace(u'\u00b6','') for t in text ).strip()
        
        steal = False

        if 'steal' in unicode(l.text).lower():
            steal = True
        if 'stolen' in unicode(l.text).lower():
            steal = True
        
        platform = False
        if 'Availability' in unicode(l.text):
            platform = True

        yield refcount, split_proto(prototype), steal, platform

refs = set( [ 
    "PyCodeObject*",
    "PyFrameObject*",
    "PyObject*",
    "PyVarObject*",
    ] )

xxx=set()


used_bases = []

undocumented_return_values = []
varargs_functions = []
va_list_functions = []
steal_in_description = []
weird_names = []
primitive_macros = []
platform_dependent = []
duplicated_functions = []

unique_funcs = set()

for base in bases:
    
    funcs = []
    
    for rc, proto, steal, platform in parse_file(base):

        
        if proto[1] in unique_funcs:
            duplicated_functions.append( (base,proto[1]) )
            continue
            
        unique_funcs.add( proto[1] )
        
        if steal:
            steal_in_description.append( (base, proto[1]) )
            
        if platform:
            platform_dependent.append( (base,proto[1]) )
        
        if proto[1] in proto_exceptions and not proto_exceptions[proto[1]]:
            continue            
        
        if proto[2]:
            if '...' in [ x[0] for x in proto[2] ]:
                varargs_functions.append( (base,proto[1]) )
                continue
                
            if [ x[0] for x in proto[2] if 'va_list' in x[0] ]:
                va_list_functions.append((base,proto[1]))
                
            if [ x[0] for x in proto[2] if x[0].startswith('TYPE ')]:
                primitive_macros.append( (base, proto[1]) )
                continue

        orig_name = proto[1]
            
        if proto[1].startswith("Py_"):
            func_name = proto[1][3:]
        elif proto[1].startswith("Py"):
            func_name = proto[1][2:]
        elif proto[1].startswith("_Py"):
            func_name = "_"+proto[1][3:]
        else:
            weird_names.append( (base, proto[1]) )
            continue
                
        if proto[0] in refs:
            borrow = True if rc and 'borrow' in rc.lower() else False
                
            if not rc:
                undocumented_return_values.append( (base, proto[1]) )
                
            try:
                args = {
                    'REFTYPE': proto[0][:-1],
                    'REF': 'borrowed_ref' if borrow else 'ref',
                    'FUNC': func_name,
                    'ORIG': orig_name,
                    'ARGS': ', '.join( p for _,p in proto[2] if p),
                    'PARMS': ', '.join( p for p,_ in proto[2] if p)
                }
                funcs.append( safe_ref_template.format(**args) )
            except Exception as e:
                print proto
                print e
                raise
        
        elif proto[0] == 'void':
            args = {
                'FUNC': func_name,
                'ORIG': orig_name,
                'ARGS': ', '.join( p for _,p in proto[2] if p),
                'PARMS': ', '.join( p for p,_ in proto[2] if p)
            }
            funcs.append( void_template.format(**args) )
        else:
            args = {
                'RETURNTYPE': proto[0],
                'FUNC': func_name,
                'ORIG': orig_name,
                'ARGS': ', '.join( p for _,p in proto[2] if p),
                'PARMS': ', '.join( p for p,_ in proto[2] if p)
            }
            funcs.append( safe_noref_template.format(**args) )
        
        if platform:
            funcs[-1] = "#ifdef _WIN32\n\n%s\n\n#endif"%funcs[-1]

    if funcs:
        with open( 'pywrapper_api_%s.h'%base, 'w' ) as f:
            f.write( file_template.format( FILE='API_%s'%base.upper(), CONTENTS="\n\n".join( funcs ) ) )
        used_bases.append(base)

with open('pywrapper_api.h', 'w') as f:
    includes = [ '#include "pywrapper_api_%s.h"'%b for b in used_bases ]
    f.write( main_file_template.format( FILE='API_%s'%base.upper(), CONTENTS="\n".join( includes ) ) )

print 'UNDOCUMENTED RETURN VALUE:'

for base, name in sorted(undocumented_return_values):
    print 'Doc/c-api/%s.rst: '%base, name

print 'ACCEPTS VARARGS:'

for base, name in sorted(varargs_functions):
    print 'Doc/c-api/%s.rst: '%base, name

print 'ACCEPTS VA_LIST:'

for base, name in sorted(va_list_functions):
    print 'Doc/c-api/%s.rst: '%base, name

print 'STEAL in description:'

for base, name in sorted(steal_in_description):
    print 'Doc/c-api/%s.rst: '%base, name

print 'WEIRD names:'

for base, name in sorted(weird_names):
    print 'Doc/c-api/%s.rst: '%base, name

print 'PRIMITIVE MACROS:'

for base, name in sorted(primitive_macros):
    print 'Doc/c-api/%s.rst: '%base, name

print 'PLATFORM DEPENDENT:'

for base, name in sorted(platform_dependent):
    print 'Doc/c-api/%s.rst: '%base, name

print 'DUPLICATED FUNCTIONS:'

for base, name in sorted(duplicated_functions):
    print 'Doc/c-api/%s.rst: '%base, name

