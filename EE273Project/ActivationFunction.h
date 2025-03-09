#pragma once

#include <iostream>
#include <Eigen/dense>

using namespace Eigen;
using namespace std;

MatrixXd reLU(MatrixXd ip);
MatrixXd tanh(MatrixXd ip);
MatrixXd sigmoid(MatrixXd ip);
MatrixXd softmax(MatrixXd ip);



