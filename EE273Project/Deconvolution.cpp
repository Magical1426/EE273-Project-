#include "Deconvolution.h"
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

Deconvolution::Deconvolution() {}
Deconvolution::~Deconvolution() {}

int Deconvolution::getStride() {
    return this->Stride;
}

int Deconvolution::getPadding() {
    return this->Padding;
}

int Deconvolution::getKernel_size() {
    return this->Kernel_size;
}

MatrixXd Deconvolution::getKernel() {
    return this->kernel;  
}

void Deconvolution::setDeconvolution(int stride, int padding, int kernel_size) {
    this->Stride = stride;
    this->Padding = padding;
    this->Kernel_size = kernel_size;
}

void Deconvolution::setKernel(MatrixXd kernel) { //checks whether or not the matrix has the correct dimensions
    if (kernel.rows() == this->Kernel_size && kernel.cols() == this->Kernel_size) {
        this->kernel = kernel;
    }
    else {
        throw invalid_argument("Kernel dimensions do not match Kernel_size.");
    }
}

MatrixXd Deconvolution::start(MatrixXd input) {
    int strideDimensions = this->Stride * (input.rows() - 1) + this->Kernel_size - 2 * this->Padding;
	int paddedDimensions = strideDimensions + 2 * this->Padding; //variable that stores the dimensions of the padded and strided matrix


    MatrixXd Output = MatrixXd::Zero(paddedDimensions, paddedDimensions); //storing the results at the end 

	for (int i = 0; i < input.rows(); i++) { //this iterates through the input matrix
        for (int j = 0; j < input.cols(); j++) {
            Output.block(i * this->Stride, j * this->Stride, this->Kernel_size, this->Kernel_size) +=
                input(i, j) * this->kernel; //updating the output 
        }
    }

    cout << "Input Size: " << input.rows() << "x" << input.cols() << endl; //debugg
    cout << "Kernel Size: " << this->Kernel_size << endl;
    cout << "Stride: " << this->Stride << ", Padding: " << this->Padding << endl;
    cout << "Output Size: " << Output.rows() << "x" << Output.cols() << endl;
    cout << "\n";

    return Output;
}
