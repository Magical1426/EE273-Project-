#pragma once

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;


class BaseLayer {
public:
	virtual ~BaseLayer() {}
	MatrixXd start(MatrixXd input) {    //This basically takes in an input and used for inheritence.
		return input;     // other layers will modify this input. 
	}

};