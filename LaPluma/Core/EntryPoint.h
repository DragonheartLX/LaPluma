#pragma once

extern LaPluma::Application* LaPluma::createApplication(int argc, char** argv);

int main(int argc, char** argv)
{
    LaPluma::Application* app = LaPluma::createApplication(argc, argv);
    app->init();
    app->run();
    delete app;

    return 0;
}