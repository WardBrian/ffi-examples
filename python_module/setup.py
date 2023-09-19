# see https://docs.python.org/3/extending/building.html#building

from distutils.core import setup, Extension

module1 = Extension('euler',
                    sources = ['eulermodule.c'])

setup (name = 'euler',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
