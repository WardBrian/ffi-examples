# see online ctypes documentation at http://docs.python.org/library/ctypes.html
import ctypes


# get a handle on our shared library:
lib = ctypes.CDLL('../C++/euler.so')

euler = lib.euler
euler.argtypes = [ctypes.c_int]
euler.restype = ctypes.c_double


if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        print ("usage: python euler.py N")
        sys.exit(1)

    iter = int(sys.argv[1])
    print(f"e = {euler(iter)}")
