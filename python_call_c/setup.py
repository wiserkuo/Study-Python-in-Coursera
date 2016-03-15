#!/usr/bin/env python

from distutils.core import setup
from distutils.extension import Extension

module1 = Extension('example',
                    sources = ['wrap.c', 'example.c'])

setup (name = 'example',
       version = '1.0',
       description = 'example',
       ext_modules = [module1])