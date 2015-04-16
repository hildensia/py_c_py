cimport clib

def lib_function():
    clib.clib_function()

def lib_list_function(l):
    return clib.clib_vector_function(l)

def lib_callback_function(func):
    clib.clib_callback_function_wrapper(<void*>func, clib.evaluate_function)
