#pragma once
#include "NeuralNetwork.h"
#include "Core/Core.h"

namespace NNetwork
{
    class NeuralNetLayer : public Core::Layer
    {
    public:
        NeuralNetLayer();
        ~NeuralNetLayer();
    
        virtual void OnUpdate() override;
        void WaitForInput();

        NeuralNetwork& GetNeuralNetwork() { return nn; }

    private:
        NeuralNetwork nn;

        std::thread inputThread;
    };
}
