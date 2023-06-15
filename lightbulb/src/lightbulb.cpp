// lightbulb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Application.h"

int main()
{
    Application* app = new Application("LightBulb");

    app->run();

    delete app;
    return 0;
}