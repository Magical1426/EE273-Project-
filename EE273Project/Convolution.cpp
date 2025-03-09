#include "Convolution.h"
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

Convolution::Convolution() {}

Convolution::~Convolution() {}

//Getters
int Convolution::getStride() {
    return this->Stride;
}

int Convolution::getPadding() {
    return this->Padding;
}

int Convolution::getKernel_size() {
    return this->Kernel_size;
}



MatrixXd Convolution::getKernel() {
    return this->kernel;
}

//Setters
void Convolution::setConvolution(int stride, int padding, int kernel_size, int inputChannels, int outputChannels) {
    this->Stride = stride;
    this->Padding = padding;
    this->Kernel_size = kernel_size;
    this->kernel = MatrixXd::Zero(kernel_size, kernel_size);
}

void Convolution::setKernel(MatrixXd kernel) {
	if (kernel.rows() == this->Kernel_size && kernel.cols() == this->Kernel_size) {
		this->kernel = kernel;
	}
}


MatrixXd Convolution::start(MatrixXd input) {

    int outputDimensionX = 1 + ((input.rows() + 2 * this->Padding - this->Kernel_size) / this->Stride);
    int outputDimensionY = 1 + ((input.cols() + 2 * this->Padding - this->Kernel_size) / this->Stride);
    MatrixXd output = MatrixXd::Zero(outputDimensionX, outputDimensionY); //Zero sets the matrix to be all zeros 

    MatrixXd paddingInput = MatrixXd::Zero(input.rows() + 2 * this->Padding, input.cols() + 2 * this->Padding); //Adding the padding to the matrix, makes the matrix bigger
    paddingInput.block(this->Padding, this->Padding, input.rows(), input.cols()) = input; //block selects the smaller part of the matrix and gives it to the input

    int scanLength = paddingInput.rows() - this->Kernel_size + 1; //length of the scan, determines how many times the kernel can move along the rows.

    for (int i = 0; i < scanLength; i++) { //this is where the convolution starts with a nested for loop 
        for (int j = 0; j < scanLength; j++) { //this basically moves the Eigen block across the padded input matrix.
            this->Stride << j * this->Stride;
            output(i, j) = (paddingInput.block(i * this->Stride, j * this->Stride, this->Kernel_size, this->Kernel_size).cwiseProduct(this->kernel)).sum(); //cwiseProduct does multiplication between the 2 matrix 
        }
    }

    //for debugging 
    cout << "Input Matrix: \n" << input << endl;
    cout << "Padded Input Matrix: \n" << paddingInput << endl;
    cout << "Kernel: \n" << this->kernel << endl;


    return output;

}

