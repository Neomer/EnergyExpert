#ifndef BUFFEREDFILE_H
#define BUFFEREDFILE_H

#include <Sdk/Core/Data/File.h>

namespace energy { namespace core { namespace data {

/**
 * @brief Класс для работы с файлами через буфер в оперативной памяти для операций записи в файл.
 * Подходит для оптимизации скорости работы приложения для случаев, когда данные в файл пишутся часто и небольшими порциями, при
 * этом актуальность данных в файле не важна.
 * Например, класс идеально подходит для логирования.
 */
class SDKSHARED_EXPORT BufferedWriteFile : public File
{
public:
    /**
     * @brief Инициализирует экземпляр класса для работы с файлами через буфер для операций записи.
     * @param cacheSize размер кэша в байтах
     * @param filename имя файла
     */
    BufferedWriteFile(size_t cacheSize, const char *filename);
    virtual ~BufferedWriteFile() override;

public:
    /**
     * @brief Записать буфер в файл
     */
    void flush();
    /**
     * @brief Размер кэша
     * @return Размер кэша в байтах
     */
    size_t getCacheSize() const;

    // IDataStream interface
public:
    virtual size_t write(const char *data, size_t size) override;
    virtual size_t write(const char *data) override;
    virtual void close() override;

private:
    void cache(const char *data, size_t size);

    char *_buffer;
    size_t _idx, _cacheSize;
};

} } }

#endif // BUFFEREDFILE_H
