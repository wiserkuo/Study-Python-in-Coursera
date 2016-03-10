example.c : the C extension function(s)  
## Method I : Write wrap.c (for connecting C to python)  
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

# build
for python 2.x  
$ gcc -fPIC wrap.c example.c -o example.so -shared  -I/usr/include/python2.7 -I/usr/lib/python2.7/config

for python 3.x  
$ gcc -fPIC wrap.c example.c -o example.so -shared  -I/usr/include/python3.4 -I/usr/lib/python3.4/config

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

More details :  
https://docs.python.org/2.7/c-api/index.html  
https://docs.python.org/3/c-api/index.html  

write fit with both python 2.x and 3.x  
http://python3porting.com/cextensions.html

Note :
reference counter
callback
