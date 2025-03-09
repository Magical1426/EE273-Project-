#include "ActivationFunction.h"
#include <iostream>
#include <Eigen/dense>

using namespace Eigen;
using namespace std;



MatrixXd reLU(MatrixXd ip) {
	for (int i = 0; i < ip.rows(); i++) {   //.rows() and .cols() are used to get the number of rows and columns in the matrix.
		for (int j = 0; j < ip.cols(); j++) {
			if (ip(i, j) <= 0) {   //if statement checks if its 0 or less than 0, positive values remain the same.   
				ip(i, j) = 0;
			}
		}
	}
	return ip;
}

MatrixXd tanh(MatrixXd ip) {
	MatrixXd ans = (2 * ip.array()).exp() - 1;  //array basically converts the matrix into an array, so that we can use the exp(). 
	ans = ans.array() / ((2 * ip.array()).exp() + 1);  
	return ans;
}

MatrixXd sigmoid(MatrixXd ip) {
	MatrixXd ans = 1 / (1 + (-ip.array()).exp());  
	return ans;
}

MatrixXd softmax(MatrixXd ip) {

	double totalExponent = 0;

	for (int i = 0; i < ip.rows(); i++) {
		for (int j = 0; j < ip.cols(); j++) {
		}
		totalExponent += exp(ip(i, 0));
	}

	for (int i = 0; i < ip.rows(); i++) {
		for (int j = 0; j < ip.cols(); j++) {
			ip(i, j) = exp(ip(i, j)) / totalExponent;
		}

		return ip;
	}

}

