#pragma once

using namespace std;

namespace NNetwork
{
    class NeuralNetwork {
    public:
        vector<double> weightsHiddenToOutput;
        vector<double> weightsInputToHidden;
        vector<double> biasHidden;
        double biasOutput;

        int layerCount;

        NeuralNetwork();
        ~NeuralNetwork();

        double Train(const vector<vector<double>>& trainingInput, const vector<double>& targetOutput, int epochs, double learningRate);

        double Predict(const vector<double>& input);

        vector<double> GetHiddenLayer() { return hiddenLayer; }
        vector<double> GetPreviousInput() { return previousInput; }
        double GetPreviousOutput() { return previousOutput; }
        
    private:
        vector<double> hiddenLayer;
        vector<double> previousInput;
        double previousOutput;
        
    };
}


