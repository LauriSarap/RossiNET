#include "rpch.h"
#include "WindowLayer.h"

namespace Window
{
    WindowLayer::WindowLayer(NNetwork::NeuralNetwork& nn) : networkVisualizer(nn, window)
    {
        window.create(sf::VideoMode(800, 600), "RossiNET");
        window.setFramerateLimit(60);
    }
    
    void WindowLayer::OnUpdate()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
        }

        window.clear();

        networkVisualizer.DrawNeuralNetwork();

        window.display();
    }
}

