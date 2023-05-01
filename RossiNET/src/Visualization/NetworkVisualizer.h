#pragma once
#include "NeuralNetwork/NeuralNetwork.h"
#include <SFML/Graphics.hpp>

namespace Window
{
    class NetworkVisualizer
    {
    public:
        NetworkVisualizer(NNetwork::NeuralNetwork& neuralNetwork, sf::RenderWindow& window);// : nn(neuralNetwork), window(window) {}

        void DrawNeuralNetwork();
        
    private:
        NNetwork::NeuralNetwork& nn;
        sf::RenderWindow& window;

        sf::Font font;
        sf::Text text;

        float radius;
    };
}
