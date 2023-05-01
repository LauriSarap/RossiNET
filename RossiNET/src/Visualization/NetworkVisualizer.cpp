#include "rpch.h"
#include "Core/Core.h"
#include "NetworkVisualizer.h"

namespace Window
{

    NetworkVisualizer::NetworkVisualizer(NNetwork::NeuralNetwork& neuralNetwork, sf::RenderWindow& windowRef) : nn(neuralNetwork), window(windowRef)
    {
        std::string executablePath = Core::Core::GetExecutablePath();
        std::string resourcePath = Core::Core::GetResourcePath(executablePath, "../../../RossiNET/src/Resources/Montserrat-Medium.ttf");
        LOG_INFO("Loaded font from: {0}", resourcePath);
        font.loadFromFile(resourcePath);

        text.setFont(font);
        text.setFillColor(sf::Color::Black);

        radius = 20.0f;
    }
    
    void NetworkVisualizer::DrawNeuralNetwork()
    {
        sf::Vector2f windowSize(static_cast<float>(window.getView().getSize().x), static_cast<float>(window.getView().getSize().y));
        radius = std::min(windowSize.x, windowSize.y) / 20.0f;
        text.setCharacterSize(static_cast<unsigned int>(radius / 2));

        float layerSpacing = windowSize.x / (nn.layerCount + 1.0f);
        float neuronSpacing;

        for (size_t layerIndex = 0; layerIndex < nn.layerCount; ++layerIndex)
        {
            // Adjust neuron spacing based on layers neuron count
            unsigned int neuronCount = 1;
            
            if (layerIndex == 0)
            {
                neuronSpacing = windowSize.y / (2 + 1.0f);
                neuronCount = 2;
            }
            if (layerIndex == 1)
            {
                neuronSpacing = windowSize.y / (2 + 1.0f);
                neuronCount = 2;
            }
            if (layerIndex == 2)
            {
                neuronSpacing = windowSize.y / (1 + 1.0f);
                neuronCount = 1;
            }

            // Iterate through each neuron in the layer
            for (size_t neuronIndex = 0; neuronIndex < neuronCount; ++neuronIndex)
            {
                sf::CircleShape neuronShape(radius);
                neuronShape.setOrigin(radius, radius);
                neuronShape.setFillColor(sf::Color::White);
                neuronShape.setOutlineColor(sf::Color::Yellow);
                neuronShape.setOutlineThickness(2.0f);

                float xPos = layerSpacing * (layerIndex + 1);
                float yPos = neuronSpacing * (neuronIndex + 1);

                neuronShape.setPosition(xPos, yPos);
                window.draw(neuronShape);

                if (layerIndex == 0)
                {
                    text.setString(Core::Core::ToStringWithPrecision(nn.GetPreviousInput()[neuronIndex], 3));
                    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
                    text.setPosition(xPos, yPos);
                    window.draw(text);
                }
                if (layerIndex == 1)
                {
                    text.setString(Core::Core::ToStringWithPrecision(nn.GetHiddenLayer()[neuronIndex], 3));
                    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
                    text.setPosition(xPos, yPos);
                    window.draw(text);
                }
                if (layerIndex == 2)
                {
                    text.setString(Core::Core::ToStringWithPrecision(nn.GetPreviousOutput(), 3));
                    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
                    text.setPosition(xPos, yPos);
                    window.draw(text);
                }
            }
        }
    }
}
