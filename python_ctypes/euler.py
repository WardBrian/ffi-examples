# see online ctypes documentation at http://docs.python.org/library/ctypes.html
import ctypes


# get a handle on our shared library:
lib = ctypes.CDLL('../C++/euler.so')

euler = lib.euler
euler.argtypes = [ctypes.c_int]
euler.restype = ctypes.c_double
