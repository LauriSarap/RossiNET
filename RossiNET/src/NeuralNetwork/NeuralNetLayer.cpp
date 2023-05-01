#include "rpch.h"
#include "Core/Core.h"
#include "NeuralNetLayer.h"

namespace NNetwork
{
    NeuralNetLayer::NeuralNetLayer()
    {
        vector<vector<double>> trainingInput =
        {
            { 0, 0 },
            { 0, 1 },
            { 1, 0 },
            { 1, 1 }
        };
        vector<double> targetOutput = { 0, 1, 1, 0 };
        
        nn = NeuralNetwork();
     
        // Train the network
        double error = nn.Train(trainingInput, targetOutput, 50000, 0.05);
        LOG_INFO("Final error: {0}", error);
        std::cout << std::endl;

        // Predict the output
        for (const auto& input : trainingInput)
        {
            double prediction = nn.Predict(input);
            LOG_INFO("Prediction for {0} {1}: {2}", input[0], input[1], prediction);
        }
        
        std::cout << std::endl;
    }

    void NeuralNetLayer::OnUpdate()
    {
        /*
        std::cout << "Weights from input to hidden layer:" << std::endl;
        std::cout << nn.weightsInputToHidden[0] << std::endl;
        std::cout << nn.weightsInputToHidden[1] << std::endl;
        std::cout << nn.weightsInputToHidden[2] << std::endl;
        std::cout << nn.weightsInputToHidden[3] << std::endl;
        std::cout << std::endl;

        std::cout << "Weights from hidden to output layer:" << std::endl;
        std::cout << nn.weightsHiddenToOutput[0] << std::endl;
        std::cout << nn.weightsHiddenToOutput[1] << std::endl;
        std::cout << std::endl;

        std::cout << "Bias for hidden layer: " << nn.biasHidden[0] << ", " << nn.biasHidden[1] << std::endl;
        std::cout << "Bias for output layer: " << nn.biasOutput << std::endl;
        std::cout << std::endl; 
        */
    }
}
