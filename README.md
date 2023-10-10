# FFI Examples

## Requirements

A C and C++ compiler, `make`, python with the pybind11 and numpy packages.

The [slides](./slides.md) are best viewed with [slides](https://github.com/maaslalani/slides).

## Outline

I will be focusing on the case of calling compiled code from a
higher-level language. This is because it is the more common (and useful) case,
and because it is the case which is the most similar between pairs of languages.


- Basic concepts
  - Linking and namespaces, `nm`
  - Name mangling and `extern "C"`
    - I am not familiar with Fortran but my understanding is
      you can use `iso_c_binding` to 'pretend' you're a C library.

- Basic FFI
  - Shared libraries, manual lookup
    - Calling conventions
    - I will be using Python, but this style is most
      useful if you are providing bindings for multiple
      languages.
      This style works in Python, Julia, R[^1], MATLAB, and likely more.
    - `ctypes`

[^1]: R has some extra weird limitations, but they're all things that you can work around if needed.

- Language-specific options (`Python.h`, `pybind11`, etc.)
  - Can be more powerful or convenient, but really only work for one language at a time.

- Common concerns[^2]
  - Error handling
  - Cross-language memory management
  - Converting between idioms (e.g. out parameters)

[^2]: Note that these are also concerns for API design generally, not just FFI.

- General tools that do it all for you (SWIG, etc.)
  - Can be powerful!
  - Can also be a pain and generate a _lot_ of code.
  - Personally, happy medium is things like clang2py which automate boilerplate of the "manual" approach
