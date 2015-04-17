from libcpp.vector cimport vector

# This is the wrapper around the cpp lib
ctypedef vector[double] (*vector_func) (void*, vector[double])
cdef extern from "clib/clib.h":
    void clib_function()
    vector[int] clib_vector_function(vector[double])
    void clib_callback_function_wrapper(void*, vector_func)

# This is a evaluation function, which gets the python function as void pointer
# and the value data from C++ -- a bit ugly, but closures do not to seem between
# python and cython functions, so I do that in C++
cdef inline vector[double] evaluate_function(void* func_p, vector[double] value):
    # recover Python function object from void* argument and call it
    return (<object> func_p)(value)



