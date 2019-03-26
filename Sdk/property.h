#ifndef PROPERTY_H
#define PROPERTY_H

// Макрос для свойств простых типов данных
#define PR(T, N)  public: T get##N() const { return _##N;}      \
                          void set##N(T value) { _##N = value; }      \
                  private: T _##N;


#endif // PROPERTY_H
