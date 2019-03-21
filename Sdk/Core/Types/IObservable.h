#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H

#include <deque>
#include <mutex>
#include <algorithm>

#include <Sdk/export.h>

namespace energy { namespace core { namespace types {

/**
 * @brief Паттерн Наблюдатель.
 * Класс, ожидающий обновление данных.
 */
template<typename T>
class IObservable;

template<typename T>
class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual bool onUpdate(const T &value, const IObservable<T> *observable)
    {
        return false;
    }
};

template<typename T>
class IObservable
{
public:
    IObservable() = default;
    virtual ~IObservable() = default;

    void registerObserver(IObserver<T> *observer) {
        std::lock_guard<std::mutex> lock(_updateMtx);
        if (std::find(_observerList.begin(), _observerList.end(), observer) == _observerList.end()) {
            _observerList.push_back(observer);
        }
    }

    void unregisterObserver(IObserver<T> *observer) {
        std::lock_guard<std::mutex> lock(_updateMtx);
        _observerList.erase(
                    std::remove(_observerList.begin(), _observerList.end(), observer),
                    _observerList.end());
    }

    void update(const T &value) {
        std::lock_guard<std::mutex> lock(_updateMtx);
        for (auto o : _observerList) {
            if (o->onUpdate(value, this)) {
                break;
            }
        }
    }

private:
    std::mutex _updateMtx;
    std::deque<IObserver<T> *> _observerList;
};

} } }

#endif // IOBSERVABLE_H
