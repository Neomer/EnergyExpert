#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <deque>
#include <inttypes.h>

namespace energy { namespace gui { namespace widgets {

/**
 * @brief Базовый класс для все виджетов в системе
 */
class AbstractWidget
{
public:
    AbstractWidget(AbstractWidget *parent = nullptr);
    AbstractWidget(int32_t left, int32_t top, uint32_t width, uint32_t height, AbstractWidget *parent = nullptr);
    /**
     * @brief Удаляет виджет, при этом удаляются так же все дочерние виджеты
     */
    virtual ~AbstractWidget();

    int32_t getLeft() const { return _left; }
    virtual void setLeft(int32_t value);

    int32_t getTop() const { return _top; }
    virtual void setTop(int32_t value);

    uint32_t getWidth() const { return _width; }
    virtual void setWidth(uint32_t value);

    uint32_t getHeight() const { return _height; }
    virtual void setHeight(uint32_t value);

    void addChildWidget(AbstractWidget *widget);

    AbstractWidget *getParent() { return _parent; }
    const AbstractWidget *getParent_const() const { return _parent; }

    int32_t getAbsoluteLeft() const;

private:
    std::deque<AbstractWidget *> _childWidgets;
    int32_t _left, _top;
    uint32_t _width, _height;
    AbstractWidget *_parent;
};

} } }

#endif // ABSTRACTWIDGET_H
