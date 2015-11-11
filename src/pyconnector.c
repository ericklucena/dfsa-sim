#include <Python.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aloha.h"
#include "result.h"

static PyObject *DFSA_lowerBound( PyObject *self, PyObject *args );
static PyObject *DFSA_eomLee( PyObject *self, PyObject *args );
static PyObject *DFSA_chen( PyObject *self, PyObject *args );

static PyMethodDef DFSAMethods[] = {
	{"lowerBound", DFSA_lowerBound, METH_VARARGS},
	{"eomLee", DFSA_eomLee, METH_VARARGS},
	{"chen", DFSA_chen, METH_VARARGS},
	{NULL, NULL} 
};

static struct PyModuleDef dfsaModuleDef = {
	PyModuleDef_HEAD_INIT,
	"DFSA", //enable "import DFSA"
	NULL, //omit module documentation
	-1, //module keeps state in global variables
	DFSAMethods //link module name "DFSA" to methods table 
};

PyMODINIT_FUNC PyInit_DFSA(void) {
	return PyModule_Create( &dfsaModuleDef ); 
}

static PyObject *DFSA_lowerBound( PyObject *self, PyObject *args ) {

	Result *result = aloha(lowerBound);
	
	return Py_BuildValue("[(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)]", 
		result[0].numIteration, result[0].numEmpty, result[0].numCollision,
		result[1].numIteration, result[1].numEmpty, result[1].numCollision,
		result[2].numIteration, result[2].numEmpty, result[2].numCollision,
		result[3].numIteration, result[3].numEmpty, result[3].numCollision,
		result[4].numIteration, result[4].numEmpty, result[4].numCollision,
		result[5].numIteration, result[5].numEmpty, result[5].numCollision,
		result[6].numIteration, result[6].numEmpty, result[6].numCollision,
		result[7].numIteration, result[7].numEmpty, result[7].numCollision,
		result[8].numIteration, result[8].numEmpty, result[8].numCollision,
		result[9].numIteration, result[9].numEmpty, result[9].numCollision
		);
} 

static PyObject *DFSA_eomLee( PyObject *self, PyObject *args ) {

	Result *result = aloha(eomLee);
	
	return Py_BuildValue("[(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)]", 
		result[0].numIteration, result[0].numEmpty, result[0].numCollision,
		result[1].numIteration, result[1].numEmpty, result[1].numCollision,
		result[2].numIteration, result[2].numEmpty, result[2].numCollision,
		result[3].numIteration, result[3].numEmpty, result[3].numCollision,
		result[4].numIteration, result[4].numEmpty, result[4].numCollision,
		result[5].numIteration, result[5].numEmpty, result[5].numCollision,
		result[6].numIteration, result[6].numEmpty, result[6].numCollision,
		result[7].numIteration, result[7].numEmpty, result[7].numCollision,
		result[8].numIteration, result[8].numEmpty, result[8].numCollision,
		result[9].numIteration, result[9].numEmpty, result[9].numCollision
		);
} 

static PyObject *DFSA_chen( PyObject *self, PyObject *args ) {

	Result *result = aloha(chen);
	
	return Py_BuildValue("[(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)(idd)]", 
		result[0].numIteration, result[0].numEmpty, result[0].numCollision,
		result[1].numIteration, result[1].numEmpty, result[1].numCollision,
		result[2].numIteration, result[2].numEmpty, result[2].numCollision,
		result[3].numIteration, result[3].numEmpty, result[3].numCollision,
		result[4].numIteration, result[4].numEmpty, result[4].numCollision,
		result[5].numIteration, result[5].numEmpty, result[5].numCollision,
		result[6].numIteration, result[6].numEmpty, result[6].numCollision,
		result[7].numIteration, result[7].numEmpty, result[7].numCollision,
		result[8].numIteration, result[8].numEmpty, result[8].numCollision,
		result[9].numIteration, result[9].numEmpty, result[9].numCollision
		);
} 
