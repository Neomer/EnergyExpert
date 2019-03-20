#ifndef WINDOW_H
#define WINDOW_H

#include <Widgets/AbstractWidget.h>

namespace energy { namespace gui { namespace widgets {

class Window : public AbstractWidget
{
public:
    Window();
    virtual ~Window() override = default;
};

} } }


#endif // WINDOW_H
