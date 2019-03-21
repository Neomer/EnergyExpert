#ifndef FILE_H
#define FILE_H

#include <cstdio>
#include <string>

#include <Sdk/Core/Data/IDataStream.h>

namespace energy { namespace core { namespace data {

/**
 * @brief Класс для работы с файлом.
 */
class SDKSHARED_EXPORT File : public IDataStream
{
public:
    /**
     * @brief Инициализирует экземпляр класса для работы с файлом.
     * @param filename Имя файла.
     */
    File(const char *filename);
    virtual ~File() override;

    // IDataStream interface
public:
    virtual void open(IDataStream::Mode mode) override;
    virtual void close() override;
    virtual size_t write(const char *data, size_t size) override;
    virtual size_t write(const char *data) override;
    virtual size_t read(char *buffer, size_t max_size) override;
    virtual bool isOpen() const override;

private:
    std::FILE *_file;
    const char *_filename;
};

} } }

#endif // FILE_H
