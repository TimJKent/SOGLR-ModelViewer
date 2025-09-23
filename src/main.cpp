#include <iostream>

#include <SOGLR/SOGLR.hpp>

int main()
{
    Rendering::Renderer renderer;
    renderer.Begin();
    Rendering::Window window(800, 600, "SOGLR-ModelViewer");

    while (!window.ShouldClose())
    {
        window.BeginFrame();

        // Rendering code would go here

        window.EndFrame();
    }

    renderer.End();

    return 0;
}