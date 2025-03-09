#include <iostream>
#include <Eigen/dense>
#include <vector>
#include "ActivationFunction.h"
#include "Convolution.h"

using namespace Eigen;
using namespace std;

int main() {
    Convolution conv;
    conv.setConvolution(1, 10, 2, 1, 1); // The stride=1, padding=1, Kernel_size=2

    MatrixXd input(3, 3); //3x3 input matrix
    input << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    MatrixXd kernel(2, 2); //2x2 kernel
    kernel << 1, 0,
        -1, 1;

    conv.setKernel(kernel);
    MatrixXd output = conv.start(input);

    cout << "Convolution Output:\n" << output << endl;
    cout << "\n";
/*
    MatrixXd matrixTest(2, 2);  //this basically creates a 2x2 matrix
    matrixTest(0, 0) = -3;
    matrixTest(0, 1) = -0.4;
    matrixTest(1, 0) = 0.2;
    matrixTest(1, 1) = 2;

    cout << "Input matrix: " << endl;
    cout << matrixTest << endl;

    cout << "\n" << "\n";

    MatrixXd ans1, ans2, ans3, ans4;

    ans1 = reLU(matrixTest);
    cout << "ReLU: " << endl << ans1 << endl;
    cout << "\n" << "\n";

    ans2 = tanh(matrixTest);
    cout << "Tanh: " << endl << ans2 << endl;
    cout << "\n" << "\n";

    ans3 = sigmoid(matrixTest);
    cout << "Sigmoid: " << endl << ans3 << endl;
    cout << "\n" << "\n";

    ans4 = softmax(matrixTest);
    cout << "Softmax: " << endl << ans4 << endl;
    cout << "\n" << "\n";


*/
    return 0;
}
    


