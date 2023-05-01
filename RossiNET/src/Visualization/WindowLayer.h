#pragma once
#include "NetworkVisualizer.h"
#include "Core/Core.h"

namespace Window
{
    class WindowLayer : public Core::Layer
    {
    public:
        WindowLayer(NNetwork::NeuralNetwork& nn);

        virtual void OnUpdate() override;

    private:
        sf::RenderWindow window;
        NetworkVisualizer networkVisualizer;
    
    };
}
