import lib
import numpy as np

def cb_test(x):
    print("Python CB got following data from C++: {}".format(x))
    x[0] = 5.6
    x[1] = 7.8
    x[2] = 9.0
    return x

def cb_numpy_test(x):
    print("Before numpy: {}".format(x))
    y = np.array(x)
    y *= 2
    z = list(y)
    print("After numpy: {}".format(z))
    return z

if __name__ == "__main__":
    lib.lib_function()
    print("="*80)
    print(lib.lib_list_function([3.4, 5.6]))
    print("="*80)
    lib.lib_callback_function(cb_test)
    lib.lib_callback_function(cb_numpy_test)

