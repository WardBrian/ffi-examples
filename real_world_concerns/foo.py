import ctypes
from numpy.ctypeslib import ndpointer

_error_ptr = ctypes.POINTER(ctypes.c_void_p)
_double_array = ndpointer(dtype=ctypes.c_double, flags=("C_CONTIGUOUS"))

lib = ctypes.CDLL('./libfoo.so')

# some of this can be automated using tools like clang2py: https://github.com/trolldbois/ctypeslib
_frob_create = lib.foo_create_frobulator
_frob_create.argtypes = [ctypes.c_int, ctypes.c_int, _error_ptr]
_frob_create.restype = ctypes.c_void_p

_frob_destroy = lib.foo_destroy_frobulator
_frob_destroy.argtypes = [ctypes.c_void_p]
_frob_destroy.restype = None

_compute = lib.foo_compute
_compute.argtypes = [ctypes.c_void_p, _double_array, _double_array, ctypes.c_int, _error_ptr]

_get_error_msg = lib.foo_error_get_message
_get_error_msg.argtypes = [ctypes.c_void_p]
_get_error_msg.restype = ctypes.c_char_p

_error_destroy = lib.foo_destroy_error
_error_destroy.argtypes = [ctypes.c_void_p]
_error_destroy.restype = None

# turn the above into something idomatic

import numpy as np

def _handle_error(error_ptr):
    if error_ptr.contents:
        msg = _get_error_msg(error_ptr.contents).decode('utf-8') # copies the string
        _error_destroy(error_ptr.contents)
        return RuntimeError(msg)
    else:
        return RuntimeError("Unknown error")

class Frobulator:
    def __init__(self, x, y):
        err = ctypes.pointer(ctypes.c_void_p())
        self._ptr = _frob_create(x, y, err)
        if not self._ptr:
            raise _handle_error(err)

    def __del__(self):
        if hasattr(self, '_ptr') and self._ptr is not None:
            _frob_destroy(self._ptr)

    def compute(self, data):
        err = ctypes.pointer(ctypes.c_void_p())
        out = np.empty_like(data)
        rc = _compute(self._ptr, data, out, len(data), err)
        if rc != 0:
            raise _handle_error(err)
        return out
