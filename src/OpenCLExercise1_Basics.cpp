//////////////////////////////////////////////////////////////////////////////
// OpenCL exercise 1: Basics
//////////////////////////////////////////////////////////////////////////////

// includes
#include <stdio.h>

#include <Core/Assert.hpp>
#include <Core/Time.hpp>
#include <OpenCL/Device.hpp>
#include <OpenCL/Event.hpp>
#include <OpenCL/Program.hpp>
#include <OpenCL/cl-patched.hpp>

#include <cnpy/cnpy.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

//////////////////////////////////////////////////////////////////////////////
// CPU implementation
//////////////////////////////////////////////////////////////////////////////

int main() {
    // Load the .npy file
    cnpy::NpyArray arr = cnpy::npy_load("/home/sandy/Downloads/OpenCLExercise1_Basics/Sinogram_0.5.npy");

    // Ensure the data is two-dimensional and of type float
    if (arr.shape.size() != 2 || arr.word_size != sizeof(float)) {
        std::cerr << "Error: Expected a 2D array of floats." << std::endl;
        return 1;
    }

    // Extract the data
    float* data = arr.data<float>();

    // Get the shape of the array
    size_t rows = arr.shape[0];
    size_t cols = arr.shape[1];

    std::cout << "Array shape: " << rows << " rows x " << cols << " columns" << std::endl;

    // Print the first 3 rows of data
    size_t rows_to_print = std::min(size_t(3), rows);
    for (size_t i = 0; i < rows_to_print; ++i) {
        std::cout << "Row " << i << ": ";
        for (size_t j = 0; j < cols; ++j) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << data[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
