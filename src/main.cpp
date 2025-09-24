#include <iostream>
#include <memory>

#include <SOGLR/SOGLR.hpp>

int main()
{
    Rendering::Renderer renderer;
    renderer.Begin();
    Rendering::Window window(800, 600, "SOGLR-ModelViewer");
    if (!window.IsValid())
    {
        renderer.End();
        exit(EXIT_FAILURE);
    }
    std::shared_ptr<Rendering::Shader> shader = std::make_shared<Rendering::Shader>(
        "S:\\Users\\Timber\\Documents\\GitHub\\SOGLR-ModelViewer\\shaders\\vertexShader.glsl",
        "S:\\Users\\Timber\\Documents\\GitHub\\SOGLR-ModelViewer\\shaders\\diffuseShader.glsl");

    std::vector<float> triangle = {
        -0.6f, -0.4f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.6f, -0.4f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 0.6f, 0.0f, 0.0f, 0.0f, 1.0f};

    std::shared_ptr<Rendering::VertexBuffer> vertexBuff = std::make_shared<Rendering::VertexBuffer>(triangle);

    std::shared_ptr<Rendering::IndexBuffer> indexBuffer = std::make_shared<Rendering::IndexBuffer>(std::vector<GLuint>{0, 1, 2});
    auto obj1 = renderer.CreateRenderObject(indexBuffer, vertexBuff, shader);
    float rotation = 1.0;

    std::shared_ptr<Rendering::Camera> scene_camera = std::make_shared<Rendering::Camera>();
    renderer.SetSceneCamera(scene_camera);
    scene_camera->GetTransform().position_ = glm::vec3(0.0f, 0.0f, 3.0f);
    renderer.BeginFrame();
    while (!window.ShouldClose())
    {
        renderer.EndFrame();
        window.BeginFrame();
        renderer.BeginFrame();

        shader->Bind();

        shader->SetUniform3f("objectColor", glm::vec3(1.0f, 1.0f, 1.0f));
        shader->SetUniform3f("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
        shader->SetUniform3f("lightPos", glm::vec3(1.0f, 1.0f, 1.0f));

        rotation = rotation + (renderer.GetDeltaTime() * 360.0f);

        obj1->SetRotation(glm::vec3(0.0f, rotation, 0.0f));
        obj1->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));

        renderer.DrawRenderList();

        window.EndFrame();
    }

    renderer.EndFrame();

    renderer.End();

    return 0;
}