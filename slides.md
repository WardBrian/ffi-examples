---
theme: ./.slides.theme.json
author: Brian Ward
date: MMMM dd, YYYY
paging: Slide %d / %d
note: best viewed using https://github.com/maaslalani/slides
---
<br/>

<br/>

# Foreign Function Interfaces

*or*

# How to have users in X but write your code in Y

---

# First, some disclaimers

- I will be focusing on the case of calling compiled code from a
higher-level language. This is because it is the more common (and useful) case,
and because it is the case which is the most similar between pairs of languages.
<br/>
- I will also be primarily using C++ and Python for demonstrations, but my emphasis
will be on a style that works more broadly.

---

# Running code example:

To make this concrete, we will use the following code for most of the talk:

```c
~~~cat C/euler.c

~~~
```

---
# Basic Concepts

## Shared libraries

A shared library is a file that contains compiled code that can be loaded into memory and executed by a program at runtime. These are also known as dynamic libraries or dynamic link libraries (DLLs).

These are created when you pass `-fPIC -shared` to your compiler.

All of the ways we learn to call our code will involve loading it from a shared library, but at different levels of abstraction.

---
# Basic Concepts

## Calling conventions and Linking

- At a low level, a function is only a place in memory where some code lives, and a name for that place.
<br/>
- Calling that function is "just" a matter of preparing memory in a certain way and then jumping to that place.
<br/>
  - This certain way is known as a "calling convention".
  To be overly general, there is usually one important calling convention per OS-architecture pair, and your system C compiler (`gcc`, `clang`, etc) uses it.

### Demo: `nm`


---
# Basic Concepts

## Name mangling

The previous demo only worked because C uses a very simple model of name lookup ("linking") which uses the name of the function as you wrote it in your code.

If we use another language, like C++, things get more complicated.

### Demo: `nm` again

---

# Basic Concepts

## Avoiding name mangling: `extern "C"`

- In C++ (and Rust) you can explicitly disable name mangling by declaring a function as `extern "C"`.
<br/>
  - This will tell it to use the "C Linkage", which as we learned just means "the name of the function and nothing fancy".
<br/>
- Fortran also uses name mangling, though by default it is usually much simpler (just an underscore is added to the name).
<br/>
  - My understanding is you can use a module called `iso_c_binding` to 'pretend' you're a C library in a similar fashion.
<br/>


*Aside*: Name mangling is what allows for things like `namespace`s and function overloading, so it's there for a good reason, it just gets in our way a bit here. The fact that there is one big global namespace for programs on your computer means you need to be careful when using non-mangled names!

---

# Foreign Function Interfaces

We now know how to control the way our code is exposed to the global namespace, but how do we actually call it?

---

## The Goal
We will use this test file for all the examples:

```python
~~~cat python_ctypes/test.py

~~~
```
---

# Method 1: Language-specific libraries

Many higher-level languages have a way of writing compiled code
which then exposes itself as a library/module.

In Python, this can be done with the API in the `Python.h` header.


---

# Method 1: Language-specific libraries


```c
~~~head -n15 python_module/eulermodule.c

~~~
// more code follows ...
```

### Demo: `python_module/`


---

# Method 1: Language-specific libraries

## Pros
  - The built module is installed in the standard location for your language.
  - Build process is handled by the language's packaging system (this is also a con).
  - Can leverage powerful features or more native constructs (e.g., Python lists).

## Cons
  - You need to learn the low-level API for your language.
    - This will end up looking very different in every language. Heavy macro use and new 'gotchas'.
  - The same shared library cannot be re-used between languages.

---

# Method 2: Tools that try to do it for you

Especially if you are only targeting a single language, tools exist to automate some or all of this.

In Python, the most popular is `pybind11`.


---

# Method 2: Tools that try to do it for you

```c++
~~~head -n16 python_pybind/euler_pybind.cpp

~~~
```

### Demo: `python_pybind/`

---

# Method 2: Tools that try to do it for you

The pros and cons from Method 1 also generally apply, plus:

## Pros
  - Can be very concise.
  - Can understand higher-level concepts like objects in the compiled language.

## Cons
  - May require annotation in your original code.
  - Can generate a lot of hard-to-read code (an older tool called `SWIG` garnered a reputation for this).
  - Often specific to a single language-language pairing.

---

# Method 3: Do it yourself with a generic library

Most languages have a way to load a shared library and call functions from it directly. In Python, this is provided by the standard library module `ctypes`.

---

# Method 3: Do it yourself with a generic library

Wrapping our `euler` function is simple. We primarily need to tell Python where to find our shared library, and what the types of the arguments and return value are.

```python
~~~cat python_ctypes/euler.py

~~~
```

### Demo: `python_ctypes/`

---

# Method 3: Do it yourself with a generic library

## Pros
  - Very simple!
  - A similar approach is available in most languages (Julia has `Libdl`, MATLAB has `loadlibrary` and `calllib`, R has `.C`* ).
  - Same shared library can be re-used between languages.
  - You are ultimately just writing code *in the higher level language*.

## Cons
  - Writing stubs can be a tedious process, especially if you have a lot of functions to wrap*.
  - Library needs to be in a well-defined location, building it is on your own.

---

# Common "real world" concerns

Regardless of your approach, there are a few things that come up often that our simple example didn't cover.


A. Error handling across languages

B. Memory management

C. Making code "feel right" in the higher-level language

### Demo: `real_world_concerns/` (uses "Method 3")

```shell
~~~tree real_world_concerns/ -I __pycache__ --noreport
```

~~~
```

---

# So, what do I do?


All of these are using the same underlying machinery to actually load and call functions.

Any 'magic' provided by one of these _must_ be possible with the others, it's just a question of how much effort it requires.

Some memory is being configured and then a specific location in a shared library is being jumped to. If you can figure out how to do that in X, Y, or Z language, the rest is just engineering.

<br/>

I am always annoyed when a talk says 'there are tradeoffs to every solution', however...

---

# So, what do I do?

*Personally*, I tend to start with "Method 3" and see how far it gets me.

I find a happy medium are tools like `clang2py` - this reads a C header and generates the `ctypes` boilerplate to call into a shared library with that API.

Turning that into a nice-to-use library is still up to you, but that's the part you probably want to control anyway.

---

# `exit()`

<br/>

<br/>

Questions?

<br/>

<br/>


### Repo: https://github.com/WardBrian/ffi-examples/

### December 7th: Sciware


