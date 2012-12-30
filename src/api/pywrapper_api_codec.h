

#ifndef PYTHONWRAPPER_API_CODEC__H
#define PYTHONWRAPPER_API_CODEC__H

namespace py
{

static inline int Codec_Register(PyObject *search_function)
{
    return safe_noref( PyCodec_Register(search_function) );
}

static inline ref<PyObject> Codec_Encode(PyObject *object, const char *encoding, const char *errors)
{
    return safe_ref( PyCodec_Encode(object, encoding, errors) );
}

static inline ref<PyObject> Codec_Decode(PyObject *object, const char *encoding, const char *errors)
{
    return safe_ref( PyCodec_Decode(object, encoding, errors) );
}

static inline ref<PyObject> Codec_Encoder(const char *encoding)
{
    return safe_ref( PyCodec_Encoder(encoding) );
}

static inline ref<PyObject> Codec_Decoder(const char *encoding)
{
    return safe_ref( PyCodec_Decoder(encoding) );
}

static inline ref<PyObject> Codec_IncrementalEncoder(const char *encoding, const char *errors)
{
    return safe_ref( PyCodec_IncrementalEncoder(encoding, errors) );
}

static inline ref<PyObject> Codec_IncrementalDecoder(const char *encoding, const char *errors)
{
    return safe_ref( PyCodec_IncrementalDecoder(encoding, errors) );
}

static inline ref<PyObject> Codec_StreamReader(const char *encoding, PyObject *stream, const char *errors)
{
    return safe_ref( PyCodec_StreamReader(encoding, stream, errors) );
}

static inline ref<PyObject> Codec_StreamWriter(const char *encoding, PyObject *stream, const char *errors)
{
    return safe_ref( PyCodec_StreamWriter(encoding, stream, errors) );
}

static inline int Codec_RegisterError(const char *name, PyObject *error)
{
    return safe_noref( PyCodec_RegisterError(name, error) );
}

static inline ref<PyObject> Codec_LookupError(const char *name)
{
    return safe_ref( PyCodec_LookupError(name) );
}

static inline ref<PyObject> Codec_StrictErrors(PyObject *exc)
{
    return safe_ref( PyCodec_StrictErrors(exc) );
}

static inline ref<PyObject> Codec_IgnoreErrors(PyObject *exc)
{
    return safe_ref( PyCodec_IgnoreErrors(exc) );
}

static inline ref<PyObject> Codec_ReplaceErrors(PyObject *exc)
{
    return safe_ref( PyCodec_ReplaceErrors(exc) );
}

static inline ref<PyObject> Codec_XMLCharRefReplaceErrors(PyObject *exc)
{
    return safe_ref( PyCodec_XMLCharRefReplaceErrors(exc) );
}

static inline ref<PyObject> Codec_BackslashReplaceErrors(PyObject *exc)
{
    return safe_ref( PyCodec_BackslashReplaceErrors(exc) );
}

}

#endif // PYTHONWRAPPER_API_API_CODEC__H

