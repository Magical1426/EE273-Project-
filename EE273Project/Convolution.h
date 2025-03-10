#pragma once
#include "BaseLayer.h"
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

class Convolution : public BaseLayer {
private:
    int Stride;
    int Padding;
    int Kernel_size;
    Eigen::MatrixXd kernel;

public:
    Convolution();
    ~Convolution();

    Convolution(int Stride, int Padding, int Kernel_size) : Stride(Stride), Padding(Padding), Kernel_size(Kernel_size) {};

    int getStride();
    int getPadding();
    int getKernel_size();
    int getInputChannels();
    int getOutputChannels();
    Eigen::MatrixXd getKernel();

    void setConvolution(int stride, int padding, int kernel_size);
    void setKernel(Eigen::MatrixXd kernel);

    Eigen::MatrixXd start(Eigen::MatrixXd input);
};