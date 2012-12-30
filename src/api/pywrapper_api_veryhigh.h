

#ifndef PYTHONWRAPPER_API_VERYHIGH__H
#define PYTHONWRAPPER_API_VERYHIGH__H

namespace py
{

static inline int Main(int argc, char **argv)
{
    return safe_noref( Py_Main(argc, argv) );
}

static inline int Run_AnyFile(FILE *fp, const char *filename)
{
    return safe_noref( PyRun_AnyFile(fp, filename) );
}

static inline int Run_AnyFileFlags(FILE *fp, const char *filename, PyCompilerFlags *flags)
{
    return safe_noref( PyRun_AnyFileFlags(fp, filename, flags) );
}

static inline int Run_AnyFileEx(FILE *fp, const char *filename, int closeit)
{
    return safe_noref( PyRun_AnyFileEx(fp, filename, closeit) );
}

static inline int Run_AnyFileExFlags(FILE *fp, const char *filename, int closeit, PyCompilerFlags *flags)
{
    return safe_noref( PyRun_AnyFileExFlags(fp, filename, closeit, flags) );
}

static inline int Run_SimpleString(const char *command)
{
    return safe_noref( PyRun_SimpleString(command) );
}

static inline int Run_SimpleStringFlags(const char *command, PyCompilerFlags *flags)
{
    return safe_noref( PyRun_SimpleStringFlags(command, flags) );
}

static inline int Run_SimpleFile(FILE *fp, const char *filename)
{
    return safe_noref( PyRun_SimpleFile(fp, filename) );
}

static inline int Run_SimpleFileEx(FILE *fp, const char *filename, int closeit)
{
    return safe_noref( PyRun_SimpleFileEx(fp, filename, closeit) );
}

static inline int Run_SimpleFileExFlags(FILE *fp, const char *filename, int closeit, PyCompilerFlags *flags)
{
    return safe_noref( PyRun_SimpleFileExFlags(fp, filename, closeit, flags) );
}

static inline int Run_InteractiveOne(FILE *fp, const char *filename)
{
    return safe_noref( PyRun_InteractiveOne(fp, filename) );
}

static inline int Run_InteractiveOneFlags(FILE *fp, const char *filename, PyCompilerFlags *flags)
{
    return safe_noref( PyRun_InteractiveOneFlags(fp, filename, flags) );
}

static inline int Run_InteractiveLoop(FILE *fp, const char *filename)
{
    return safe_noref( PyRun_InteractiveLoop(fp, filename) );
}

static inline int Run_InteractiveLoopFlags(FILE *fp, const char *filename, PyCompilerFlags *flags)
{
    return safe_noref( PyRun_InteractiveLoopFlags(fp, filename, flags) );
}

static inline struct _node* Parser_SimpleParseString(const char *str, int start)
{
    return safe_noref( PyParser_SimpleParseString(str, start) );
}

static inline struct _node* Parser_SimpleParseStringFlags(const char *str, int start, int flags)
{
    return safe_noref( PyParser_SimpleParseStringFlags(str, start, flags) );
}

static inline struct _node* Parser_SimpleParseFile(FILE *fp, const char *filename, int start)
{
    return safe_noref( PyParser_SimpleParseFile(fp, filename, start) );
}

static inline struct _node* Parser_SimpleParseFileFlags(FILE *fp, const char *filename, int start, int flags)
{
    return safe_noref( PyParser_SimpleParseFileFlags(fp, filename, start, flags) );
}

static inline ref<PyObject> Run_String(const char *str, int start, PyObject *globals, PyObject *locals)
{
    return safe_ref( PyRun_String(str, start, globals, locals) );
}

static inline ref<PyObject> Run_StringFlags(const char *str, int start, PyObject *globals, PyObject *locals, PyCompilerFlags *flags)
{
    return safe_ref( PyRun_StringFlags(str, start, globals, locals, flags) );
}

static inline ref<PyObject> Run_File(FILE *fp, const char *filename, int start, PyObject *globals, PyObject *locals)
{
    return safe_ref( PyRun_File(fp, filename, start, globals, locals) );
}

static inline ref<PyObject> Run_FileEx(FILE *fp, const char *filename, int start, PyObject *globals, PyObject *locals, int closeit)
{
    return safe_ref( PyRun_FileEx(fp, filename, start, globals, locals, closeit) );
}

static inline ref<PyObject> Run_FileFlags(FILE *fp, const char *filename, int start, PyObject *globals, PyObject *locals, PyCompilerFlags *flags)
{
    return safe_ref( PyRun_FileFlags(fp, filename, start, globals, locals, flags) );
}

static inline ref<PyObject> Run_FileExFlags(FILE *fp, const char *filename, int start, PyObject *globals, PyObject *locals, int closeit, PyCompilerFlags *flags)
{
    return safe_ref( PyRun_FileExFlags(fp, filename, start, globals, locals, closeit, flags) );
}

static inline ref<PyObject> CompileString(const char *str, const char *filename, int start)
{
    return safe_ref( Py_CompileString(str, filename, start) );
}

static inline ref<PyObject> CompileStringFlags(const char *str, const char *filename, int start, PyCompilerFlags *flags)
{
    return safe_ref( Py_CompileStringFlags(str, filename, start, flags) );
}

static inline ref<PyObject> Eval_EvalCode(PyCodeObject *co, PyObject *globals, PyObject *locals)
{
    return safe_ref( PyEval_EvalCode(co, globals, locals) );
}

static inline ref<PyObject> Eval_EvalCodeEx(PyCodeObject *co, PyObject *globals, PyObject *locals, PyObject **args, int argcount, PyObject **kws, int kwcount, PyObject **defs, int defcount, PyObject *closure)
{
    return safe_ref( PyEval_EvalCodeEx(co, globals, locals, args, argcount, kws, kwcount, defs, defcount, closure) );
}

static inline ref<PyObject> Eval_EvalFrame(PyFrameObject *f)
{
    return safe_ref( PyEval_EvalFrame(f) );
}

static inline ref<PyObject> Eval_EvalFrameEx(PyFrameObject *f, int throwflag)
{
    return safe_ref( PyEval_EvalFrameEx(f, throwflag) );
}

static inline int Eval_MergeCompilerFlags(PyCompilerFlags *cf)
{
    return safe_noref( PyEval_MergeCompilerFlags(cf) );
}

}

#endif // PYTHONWRAPPER_API_API_VERYHIGH__H

