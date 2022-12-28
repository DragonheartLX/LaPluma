#include <iostream>
#include <LaPluma.h>

using namespace std;
using namespace LaPluma;

class LaPlumaApp: public Application
{
public:
    LaPlumaApp() {};
    ~LaPlumaApp() {};
};

LaPluma::Application* LaPluma::createApplication(int argc, char** argv)
{
    return new LaPlumaApp();
};