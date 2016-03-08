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

// Initialization function
// This function should named like this : init(module_name)
PyMODINIT_FUNC initexample()
{
    PyObject *m;
	// Py_InitModule is supported by python 2.x but 3.x    
    // 1. module name
    // 2. pointer of method list
    m = Py_InitModule("example", exampleMethods);
    if (m == NULL)
    {
        return;
    }
}