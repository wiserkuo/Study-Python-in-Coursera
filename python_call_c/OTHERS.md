# Others I (swig)  
http://swig.org/index.php  
But some people got problems with swig (including me), if you can not solve it quickly, try other ways.  
### 0. install swig  
### 1. write example.i  
swig use example.i to generate wrap.c
### 2. run swig  
$ swig -python -o wrap.c example.i  
You can omit this step by fill in swig parameters in setup.py  
### 3. Write setup.py (for building C files.)  
To avoid platform dependency problem, I strongly suggested to use python lib "distutils".  
distutils support swig.

# Others II (boost.python)  
http://www.boost.org/doc/libs/master/libs/python/doc/html/index.html  
Have not tried yet.  
If you are familiar with boost lib, try this.  

# Others III (cython)  
http://cython.org/  
Have not tried yet.  
Infact, cython is another language but very similiar to python.

# Others IV (pyrex)  
Have not tried yet.  
