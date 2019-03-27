#ifndef SINGLETON_H
#define SINGLETON_H

#ifndef SINGLETON
#define NO_COPY(cn)         cn(cn &other) = delete; \
                            cn(cn &&other) = delete; \
                            cn &operator =(cn &other) = delete; \
                            cn &operator =(cn &&other) = delete;


#define SINGLETON(cn)   private:    \
                            cn(cn &other) = delete; \
                            cn(cn &&other) = delete; \
                            cn &operator =(cn &other) = delete; \
                            cn &operator =(cn &&other) = delete; \
                        public: static cn &getInstance() { static cn i; return i; }

#define INTERFACE(cn)    public: \
                            cn() = default; \
                            virtual ~cn() = default;

#endif

#endif // SINGLETON_H
