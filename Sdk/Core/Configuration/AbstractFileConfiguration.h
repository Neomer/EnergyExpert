#ifndef ABSTRACTFILECONFIGURATION_H
#define ABSTRACTFILECONFIGURATION_H

#include <Sdk/Core/Configuration/IConfiguration.h>

namespace energy { namespace core { namespace configuration {

/**
 * @brief Абстрактный класс конфигурации, частично реализующий интерфейс IConfiguration.
 * Класс описывающий конфигурации хранящиеся в локальных файлах на диске. Реализует функционал открытия и закрытия файла.
 * Файл читается целиком, поэтому не рекомендуется использовать для объемных файлов конфигураций.
 */
class AbstractFileConfiguration : public IConfiguration
{
public:
    AbstractFileConfiguration();
    virtual ~AbstractFileConfiguration() override = default;

    // IConfiguration interface
public:
    /**
     * @brief Открывает файл, читает полностью весь файл.
     * @param path Путь к файлу
     */
    virtual void open(const char *path) override;
    virtual void saveAndClose() override;
    virtual void rejectAndClose() override;

protected:
    /**
     * @brief Вызывается, когда файл успешно полностью прочитан.
     * @param str Считанные данные из файла.
     */
    virtual void fileDataReady(const std::string &str) = 0;

private:
    std::FILE *_file;
    const char *_message;
};

} } }

#endif // ABSTRACTFILECONFIGURATION_H
