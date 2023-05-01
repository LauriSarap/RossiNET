#pragma once
#include "NeuralNetwork.h"
#include "Core/Core.h"

namespace NNetwork
{
    class NeuralNetLayer : public Core::Layer
    {
    public:
        NeuralNetLayer();
    
        virtual void OnUpdate() override;

        NeuralNetwork& GetNeuralNetwork() { return nn; }

    private:
        NeuralNetwork nn;
    };
}
