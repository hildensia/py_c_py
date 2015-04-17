#include "clib.h"
#include <iostream>
#include <vector>

void clib_function() {
  std::cout << "Hello, World from C++!" << std::endl;
}

std::vector<int> clib_vector_function(std::vector<double> arr) {
  std::cout << "Data: ";
  for (double d : arr) 
    std::cout << d << " ";
  std::cout << std::endl;
  return {1, 2, 3};
}

void clib_callback_function(std::function<arr(arr)> func) {
  std::vector<double> data = {1.2, 3.4, 5.6};
  
  std::cout << "Call CB from C++ with the following data: ";
  for (double d : data) 
    std::cout << d << " ";
  std::cout << std::endl;

  std::vector<double> new_data = func(data);

  std::cout << "Python returned the following data: ";
  for (double d : new_data) 
    std::cout << d << " ";
  std::cout << std::endl;
}
    

// this is what we add for python conveniece: /////////////////////////////////
//
void clib_callback_function_wrapper(void* python_function, 
                                    std::function<arr(void*, arr)> eval) {
  clib_callback_function([&](arr x) { return eval(python_function, x); });  
}
