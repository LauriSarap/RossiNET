#pragma once
#include "NeuralNetwork/NeuralNetwork.h"

#include <SFML/Graphics.hpp>

using namespace NNetwork;

namespace Visualization
{
    class NeuralNetworkVisualizer
    {
    public:
        NeuralNetworkVisualizer(NeuralNetwork& neuralNetwork, sf::RenderWindow& window) : nn(neuralNetwork), window(window) {}

        void DrawNeuralNetwork();
        
    private:
        NeuralNetwork& nn;
        sf::RenderWindow& window;
    };
}
