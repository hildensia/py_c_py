#ifndef __CLIB_H__
#define __CLIB_H__
#include <vector>
#include <functional>

typedef std::vector<double> arr;

void clib_function();
std::vector<int> clib_vector_function(std::vector<double> arr);

// this is the normal interface
void clib_callback_function(std::function<arr(arr)> func);

// this is what we add for python conveniece: /////////////////////////////////
void clib_callback_function_wrapper(void* func, arr (*eval) (void*, arr));

#endif
