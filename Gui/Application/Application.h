#ifndef APPLICATION_H
#define APPLICATION_H

namespace energy::gui {

class Application
{
public:
    Application();
    Application(int argv, const char **args);

    int exec();
};

}


#endif // APPLICATION_H
