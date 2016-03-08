# build
$ gcc -fPIC wrap.c example.c -o example.so -shared  -I/usr/include/python2.7 -I/usr/lib/python2.7/config

# enter python
$ python

Python 2.7.6 (default, Jun 22 2015, 17:58:13)  
[GCC 4.8.2] on linux2  
Type "help", "copyright", "credits" or "license" for more information.  
\>>> import example  
\>>> example.fact(6)  
720
