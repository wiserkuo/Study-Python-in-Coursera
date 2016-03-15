platform : linux mint 17 / osx 10.11.3

example.c : the C extension function(s)  

# Method I (hand made)  
### 1. Write wrap.c (for connecting C to python.)  
There are 3 parts in wrap.c  
A. Exported function
  - Deal with function forms, should be one of the following
    - PyObject *MyFunction(PyObject *self, PyObject *args);
    - PyObject *MyFunctionWithKeywords(PyObject *self, PyObject *args, PyObject *kw);
    - PyObject *MyFunctionWithNoArgs(PyObject *self);  
  - Deal with args parsing while programming.  

B. Method list  
C. Initialization function  
  - Initialization function have different forms in python 2.x and 3.x  
  - Some structure members of PyModuleDef could just set as default value, check it while programming.

### 2. Write setup.py (for building C files.)
To avoid platform dependency problem, I strongly suggested to use python lib "distutils".  

for python 2.x  
$ python setup.py build  

for python 3.x  
$ python3 setup.py build  

then go to "./build/" to find what you need.  

# Method II (ctypes)  

# Others I (cython)  

# Others II (pyrex)  

# Others III (swig)  
http://swig.org/index.php  
But some people got problems with swig (including me), if you can not solve it quickly, try other ways.  
### 0. install swig  
### 1. write example.i  
swig use example.i to generate wrap.c
### 2. run swig
You can omit this step by fill in swig parameters in setup.py  
### 3. Write setup.py (for building C files.)  
To avoid platform dependency problem, I strongly suggested to use python lib "distutils".  
distutils support swig.

# Others IV (boost.python)  
http://www.boost.org/doc/libs/master/libs/python/doc/html/index.html  
Have not tried yet.  
If you are familiar with boost lib, try this.  

# enter python
for python 2.x  
$ python  

Python 2.7.6 (default, Jun 22 2015, 17:58:13)  
[GCC 4.8.2] on linux2  
Type "help", "copyright", "credits" or "license" for more information.  
\>>> import example  
\>>> example.fact(6)  
720

for python 3.x  
$ python3  

Python 3.4.3 (default, Oct 14 2015, 20:28:29)  
[GCC 4.8.4] on linux  
Type "help", "copyright", "credits" or "license" for more information.  
\>>> import example  
\>>> example.fact(6)  
720

### More details :  
for wrap.c  
https://docs.python.org/2.7/extending/index.html#extending-index  
https://docs.python.org/2.7/c-api/index.html  
https://docs.python.org/3.5/extending/index.html#extending-index  
https://docs.python.org/3/c-api/index.html  
for setup.py  
https://docs.python.org/2/distutils/apiref.html  
https://docs.python.org/3.5/distutils/apiref.html  

write fit with both python 2.x and 3.x  
http://python3porting.com/cextensions.html

Note :  
reference counter  
callback
