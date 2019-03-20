#include <iostream>
#include <thread>
#include <chrono>

#include "Application.h"

using namespace energy::gui;

Application::Application()
{

}

Application::Application(int argv, const char **args)
{
    //TODO: Сделать парсинг аргументов
}

int Application::exec()
{
    while (true) {
        std::cout << "I'm inside main GUI thread!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
