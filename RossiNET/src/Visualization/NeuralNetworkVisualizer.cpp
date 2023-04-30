#include "rpch.h"
#include "NeuralNetworkVisualizer.h"

void Visualization::NeuralNetworkVisualizer::DrawNeuralNetwork()
{
    sf::Vector2u windowSize = window.getSize();

    float radius = std::min(windowSize.x, windowSize.y) / 20.0f;

    sf::Font font;
    font.loadFromFile("../../../RossiNET/src/Resources/Montserrat-Medium.ttf");
}
