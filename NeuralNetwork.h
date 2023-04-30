#pragma once

#include <vector>
#include "MathFunctions.h"

using namespace std;

class NeuralNetwork {
public:
    vector<double> weightsHiddenToOutput;
    vector<double> weightsInputToHidden;
    vector<double> biasHidden;
    double biasOutput;

    NeuralNetwork();
    ~NeuralNetwork();

    double Train(const vector<vector<double>>& trainingInput, const vector<double>& targetOutput, int epochs, double learningRate);

    double Predict(const vector<double>& input);
};


