from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

import os
pwd = os.getcwd()

os.environ['CFLAGS'] = '-I/usr/include/python3.4m -std=c++0x'
os.environ['LDFLAGS'] = '-L/usr/lib/python3.4m -L' + pwd + '/clib'


setup(
    ext_modules = cythonize([Extension("lib", ["lib.pyx"],
                                       libraries=["clib"],
                            language="c++")])
)
