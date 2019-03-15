#include "AbstractViewItem.h"

using namespace energy::core::draws;

AbstractViewItem::AbstractViewItem()
{

}

AbstractViewItem::~AbstractViewItem()
{

}

int32_t AbstractViewItem::getX() const
{
    return _x;
}

int32_t AbstractViewItem::getY() const
{
    return  _y;
}

int32_t AbstractViewItem::getWidth() const
{
    return _w;
}

int32_t AbstractViewItem::getHeigth() const
{
    return _h;
}
