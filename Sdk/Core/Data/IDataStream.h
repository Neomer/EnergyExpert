#ifndef IDATASTREAM_H
#define IDATASTREAM_H

#include <export.h>
#include <stddef.h>

namespace energy { namespace core { namespace data {

/**
 * @brief IDataStream поток данных
 */
class SDKSHARED_EXPORT IDataStream
{
public:
    IDataStream();
    virtual ~IDataStream();

    enum Mode
    {
        ReadOnly,
        WriteOnly,
        ReadWrite
    };

    /**
     * @brief open открыть поток данных
     */
    virtual void open(IDataStream::Mode mode) = 0;
    /**
     * @brief close закрыть поток данных
     */
    virtual void close() = 0;
    /**
     * @brief write записать данные в поток
     * @param data данные для записи
     * @param size количество байт для записи
     * @return количество реально записанных байт информации
     */
    virtual size_t write(const char *data, size_t size) = 0;
    /**
     * @brief read прочитать данные из потока
     * @param buffer буффер для записи данных
     * @param max_size размер буффера данных
     * @return количество прочитанных байт
     */
    virtual size_t read(char *buffer, size_t max_size) = 0;

};

} } }


#endif // IDATASTREAM_H
