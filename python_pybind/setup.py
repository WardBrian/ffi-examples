from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension

module1 = Pybind11Extension('euler',
                    sources = ['euler_pybind.cpp'])

setup(name = 'euler',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
