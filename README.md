# py_c-_py
A cython wrapper from python to C++ to python again


## Setup
First build the cpp lib:

    $ cd clib
    $ make

Then build the C extension with cython:

    $ python setup.py build_ext -i
    
Be sure that `$LD_LIBRARY_PATH` points to the `clib` directory that `libclib.so` can be found :

    $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/clib
    
Run the 'tests':

    $ python test.py
    
    
## What is it?

We want to hand over pure python functions to a library that expects `std::function` objects, let it run and then use the result in python again.

## How is it achieved?
First we write a wrapper for each function that expexts a `std::function` which expects a `void*` and a `std::function` with the same signature as the original `std::function` object plus a void pointer.
The `void*` will point to the python function and the other `std::function` to something, which can evaluate this python function. We that give the original function a closure with the right signature.
What? Here's an example:

    // The original function we want to wrap
    int orig_func(std::function<double(double)> callback) { // do something }
    
    // The wrapper around that
    int orig_func_wrapper(void* python_func, std::function<double(void*, double)> eval_func) {
        return orig_func([](double v){ return eval_func(python_func, v); };
    }

Ok, now we need the evaluation function. That one is done in cython. We nee one for each `std::function` template instantiation we want to use as callback. It gets as first argument the python function as `void*`

    # eval_func for std::fucntion<double(double)> 
    cdef inline double evaluate_function(void* func_p, double value):
      # recover Python function object from void* argument and call it
      return (<object> func_p)(value)
      
Now we want to call the `orig_func` from python. We wrap that using cython and our wrappers like this:

    def py_orig_func(py_func):
        orig_func_wrapper(<void*>py_func, evaluate_function)

Everything else is normal cython. Refer to its documentation for that.
