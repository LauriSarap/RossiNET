#include "rpch.h"
#include "Application.h"
#include "Log.h"

namespace Core
{
    Application* Application::Instance = nullptr;

    Application::Application()
    {
        Instance = this;

        Log::Initialization();

        auto neuralNetLayer = std::make_unique<NNetwork::NeuralNetLayer>();
        layerStack.push_back(std::move(neuralNetLayer));
    }

    Application::~Application(){}

    void Application::Run()
    {
        std::cout << "Program started!" << std::endl;
        
        while (true)
        {
            for (auto& layer : layerStack)
            {
                layer->OnUpdate();
            }
        }
    }


}
