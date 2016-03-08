#include <Python.h>

// Exported function
PyObject *wrap_fact(PyObject *self, PyObject *args)
{
	int n, result;

	// PyArg_ParseTuple() : parse python args to c
	// deal with non-basic types (in C) of args, try PyTuple_GetItem()
	if (!PyArg_ParseTuple(args, "i:fact", &n))
	{
		return NULL;
	}

	// get result from the function in example.c
	result = fact(n);

	// Py_BuildValue() : parse c value back to python
	// deal with non-basic types (in C) of args, try PyList_SetItem()
	return Py_BuildValue("i", result);
}

// Method list
// all method in c should written here, and add an extra array like below.
static PyMethodDef exampleMethods[] = 
{
	//    field 	/ c type 	 	/ meaning
	// 1. ml_name	/ char *		/ name of the method
	// 2. ml_meth	/ PyCFunction	/ pointer to the C implementation
	// 3. ml_flags	/ int 			/ flag bits indicating how the call should be constructed
	// 4. ml_doc	/ char *		/ points to the contents of the docstring
	{"fact", wrap_fact, METH_VARARGS, "Caculate N!"},
	{NULL, NULL, 0, NULL}
};

// for python 3.x
static struct PyModuleDef example =
{
    PyModuleDef_HEAD_INIT,
    "example", 				/* name of module */
    "",          			/* module documentation, may be NULL */
    -1,          			/* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    exampleMethods
};

PyMODINIT_FUNC PyInit_example(void)
{
	// return PyModule_Create(&example);
	PyObject *m;
	m = PyModule_Create(&example);
	if (m == NULL)
	{
		return;
	}
}