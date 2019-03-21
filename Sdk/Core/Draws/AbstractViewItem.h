#ifndef ABSTRACTVIEWITEM_H
#define ABSTRACTVIEWITEM_H

#include <Sdk/export.h>
#include <inttypes.h>

namespace energy { namespace core { namespace draws {

/**
 * @brief Абстрактный класс для всех элементов для отрисовки
 */
class SDKSHARED_EXPORT AbstractViewItem
{
public:
    AbstractViewItem();
    virtual ~AbstractViewItem();

    /**
     * @brief возвращает координату X элемента
     */
    virtual int32_t getX() const;
    /**
     * @brief возвращает координату Y элемента
     */
    virtual int32_t getY() const;
    /**
     * @brief возвращает ширину элемента
     */
    virtual int32_t getWidth() const;
    /**
     * @brief возвращает высоту элемента
     */
    virtual int32_t getHeigth() const;

private:
    int32_t _x, _y, _w, _h;
};

} } }



#endif // ABSTRACTVIEWITEM_H
