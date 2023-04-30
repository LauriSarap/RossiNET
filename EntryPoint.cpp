#include <iostream>
#include <conio.h>
#include "NeuralNetwork.h"

int main()
{
	std::cout << "Program started!" << std::endl;
	char inputKey;

	NeuralNetwork nn;

	while (true)
	{
		inputKey = _getch();
		
		// Neural network
		vector<vector<double>> trainingInput =
		{
			{ 0, 0 },
			{ 0, 1 },
			{ 1, 0 },
			{ 1, 1 }
		};
		vector<double> targetOutput = { 0, 1, 1, 0 };
		
		if (inputKey == 'n')
		{
			nn = NeuralNetwork();
			cout << "New neural network created." << endl;
			cout << endl;
		}
		
		if (inputKey == 't')
		{
			// Train the network
			double error = nn.Train(trainingInput, targetOutput, 50000, 0.05);
			std::cout << std::endl;
			cout << "Final Error: " << error << endl;
		}
		
		if (inputKey == 'u')
		{
			// Predict the output
			for (const auto &input : trainingInput)
			{
				double prediction = nn.Predict(input);
				std::cout << "Prediction for " << input[0] << " " << input[1] << ": " << prediction << std::endl;
			}
			std::cout << std::endl;
		}
		
		if (inputKey == 'i')
		{
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
		}

		if (inputKey == 'c')
		{
			cout << "Press 'n' to create a new neural network." << endl;
			cout << "Press 't' to train the neural network." << endl;
			cout << "Press 'u' to use the neural network." << endl;
			cout << "Press 'i' to print the weights and biases of the neural network." << endl;
		}

		inputKey = 'q';

		cout << "Press 'c' for commands." << endl;
	}

}
