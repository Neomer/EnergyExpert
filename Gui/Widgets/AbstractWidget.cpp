#include "AbstractWidget.h"

using namespace energy::gui::widgets;

AbstractWidget::AbstractWidget(AbstractWidget *parent) :
    _left{0}, _top{0}, _width{0}, _height{0}, _parent{parent}
{

}

AbstractWidget::AbstractWidget(int32_t left, int32_t top, uint32_t width, uint32_t height, AbstractWidget *parent):
    _left{left}, _top{top}, _width{width}, _height{height}, _parent{parent}
{

}

AbstractWidget::~AbstractWidget()
{
    for(auto w : _childWidgets) {
        delete w;
    }
}

void AbstractWidget::setLeft(int32_t value)
{
    _left = value;
}

void AbstractWidget::setTop(int32_t value)
{
    _top = value;
}

void AbstractWidget::setWidth(uint32_t value)
{
    _width = value;
}

void AbstractWidget::setHeight(uint32_t value)
{
    _height = value;
}

void AbstractWidget::addChildWidget(AbstractWidget *widget)
{
    _childWidgets.push_back(widget);
}

int32_t AbstractWidget::getAbsoluteLeft() const
{
    return _left + (_parent != nullptr ? _parent->getAbsoluteLeft() : 0);
}

int32_t AbstractWidget::getAbsoluteTop() const
{
    return _top + (_parent != nullptr ? _parent->getAbsoluteTop() : 0);
}




