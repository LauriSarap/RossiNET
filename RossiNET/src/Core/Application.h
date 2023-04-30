#pragma once
#include "Layer.h"
#include "NeuralNetwork/NeuralNetLayer.h"

namespace Core
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        static Application* Instance;
        std::vector<std::unique_ptr<Layer>> layerStack;
    };
    
}
