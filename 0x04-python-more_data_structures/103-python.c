#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyListObject *list;
	PyObject *item;

	size = PyList_Size(p);
	list = (PyListObject *)p;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
	}
}

void print_python_bytes(PyObject *p)
{
	PyBytesObject *bytes;
	Py_ssize_t size, i;

	printf("[.] bytes object info\n");

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	bytes = (PyBytesObject *)p;
	size = PyBytes_Size(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", bytes->ob_sval);

	if (size > 10)
		size = 10;

	printf("  first %ld bytes: ", size);
	for (i = 0; i < size; i++)
	{
		printf("%02x", (unsigned char)bytes->ob_sval[i]);
		if (i < size - 1)
			printf(" ");
	}
	printf("\n");
}
