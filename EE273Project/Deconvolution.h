#pragma once
#include "BaseLayer.h"
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class Deconvolution : public BaseLayer {
private:
    int Stride;
    int Padding;
    int Kernel_size;
    Eigen::MatrixXd kernel; 

public:
    Deconvolution();
    ~Deconvolution();

    Deconvolution(int stride, int padding, int kernel_size)
        : Stride(stride), Padding(padding), Kernel_size(kernel_size),
        kernel(MatrixXd::Zero(kernel_size, kernel_size)) {} 

    // Getters
    int getStride();
    int getPadding();
    int getKernel_size();
    MatrixXd getKernel();

    // Setters
    void setDeconvolution(int stride, int padding, int kernel_size);
    void setKernel(MatrixXd kernel); 

    MatrixXd start(MatrixXd input);  
};
