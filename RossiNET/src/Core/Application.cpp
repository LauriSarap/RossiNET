#include "rpch.h"
#include "Application.h"
#include "Log.h"
#include "Visualization/WindowLayer.h"

namespace Core
{
    Application* Application::Instance = nullptr;

    Application::Application()
    {
        Instance = this;

        Log::Initialization();

        auto neuralNetLayer = std::make_unique<NNetwork::NeuralNetLayer>();
        auto windowLayer = std::make_unique<Window::WindowLayer>(neuralNetLayer->GetNeuralNetwork());
        
        layerStack.push_back(std::move(neuralNetLayer));
        layerStack.push_back(std::move(windowLayer));
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
