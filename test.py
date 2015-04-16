import lib

def cb_test(x):
    print("CB test: {}".format(x))
    x[0] = 5.6
    x[1] = 7.8
    x[2] = 9.0
    return x

if __name__ == "__main__":
    lib.lib_function()
    print("="*80)
    print(lib.lib_list_function([3.4, 5.6]))
    print("="*80)
    lib.lib_callback_function(cb_test)

