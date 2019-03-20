#ifndef ICONFIGURATION_H
#define ICONFIGURATION_H

#include <string>

#include <Core/Exceptions/IOException.h>
#include <Core/Types/IStringable.h>

namespace energy { namespace core { namespace configuration {

/**
 * @brief Интерфейс для класса конфигураций.
 * Класс должен работать с копией конфигурации, для поддержки возможности закрытия файла без изменений.
 */
class IConfiguration
{
public:
    IConfiguration() = default;
    virtual ~IConfiguration() = default;
    /**
     * @brief Открыть файл конфигурации.
     * @param path Путь до файла конфигурации
     * @throw energy::core::exceptions::IOException Не удалось получить доступ к файлу
     */
    virtual void open(const char *path) = 0;
    /**
     * @brief Сохранить и закрыть файл конфигурации
     * @throw energy::core::exceptions::IOException Не удалось получить доступ к файлу
     */
    virtual void saveAndClose() = 0;
    /**
     * @brief Закрыть файл без изменений
     * @throw energy::core::exceptions::IOException Не удалось получить доступ к файлу
     */
    virtual void rejectAndClose() = 0;
    /**
     * @brief write Записать значение в файл конфигурации.
     * @param key Ключ конфигурации
     * @param value Целое значение
     */
    virtual void write(const char *key, int value) = 0;
    /**
     * @brief write Записать значение в файл конфигурации.
     * @param key Ключ конфигурации
     * @param value Вещественное число
     */
    virtual void write(const char *key, double value) = 0;
    /**
     * @brief write Записать значение в файл конфигурации.
     * @param key Ключ конфигурации
     * @param value Строка
     */
    virtual void write(const char *key, std::string &value) = 0;
    /**
     * @brief write Записать значение в файл конфигурации.
     * @param key Ключ конфигурации
     * @param value Строка
     */
    virtual void write(const char *key, const char *value) = 0;
    /**
     * @brief write Записать значение в файл конфигурации.
     * @param key Ключ конфигурации
     * @param value Строка
     */
    virtual void write(const char *key, const energy::core::types::IStringable *value) = 0;
    /**
     * @brief readInt Прочитать значение из файла конфигурации.
     * @param key Ключ конфигурации
     * @return Целое число
     * @throw energy::core::exceptions::IOException Не удалось найти значение с указанным ключом
     * @throw std::invalid_argument Преобразование не может быть выполнено
     * @throw std::out_of_range Преобразованное значение будет выходить за границы диапазона значений типа результата
     */
    virtual int readInt(const char *key) const = 0;
    /**
     * @brief readDouble Прочитать значение из файла конфигурации.
     * @param key Ключ конфигурации
     * @return Вещественное число
     * @throw energy::core::exceptions::IOException Не удалось найти значение с указанным ключом
     * @throw std::invalid_argument Преобразование не может быть выполнено
     * @throw std::out_of_range Преобразованное значение будет выходить за границы диапазона значений типа результата
     */
    virtual double readDouble(const char *key) const = 0;
    /**
     * @brief readString Прочитать значение из файла конфигурации.
     * @param key Ключ конфигурации
     * @return Строка
     * @throw energy::core::exceptions::IOException Не удалось найти значение с указанным ключом
     * @throw std::invalid_argument Преобразование не может быть выполнено
     * @throw std::out_of_range Преобразованное значение будет выходить за границы диапазона значений типа результата
     */
    virtual std::string readString(const char *key) const = 0;
};

} } }

#endif // ICONFIGURATION_H
