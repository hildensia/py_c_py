from libcpp.vector cimport vector

ctypedef vector[double] (*vector_func) (void*, vector[double])
cdef extern from "clib/clib.h":
    void clib_function()
    vector[int] clib_vector_function(vector[double])
    void clib_callback_function_wrapper(void*, vector_func)

cdef inline vector[double] evaluate_function(void* func_p, vector[double] value):
    try:
        # recover Python function object from void* argument
        func = <object>func_p
        print("value: {}".format(value))
        # call function, convert result into 0/1 for True/False
        r = func(value)
        print(r)
        return r

    except:
        print("Error...")
        # catch any Python errors and return error indicator
        return [0]


