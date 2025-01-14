#ifndef __OPENCL_VERSION__
#include "../lib/OpenCL/OpenCLKernel.hpp"  // Hack to make syntax highlighting work
#endif

__kernel void kernel1(__global const float* d_input, __global float* d_output) {
  size_t index = get_global_id(0);
  d_output[index] = cos(d_input[index]);
  //d_output[index] = native_cos (d_input[index]);
}
