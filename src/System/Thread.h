//
// Created by asphox on 20/11/2019.
//

#ifndef UNIJAM_THREAD_H
#define UNIJAM_THREAD_H

#include <SFML/System.hpp>
#include <functional>

class Thread
{
public:
    Thread(void(*fct)());

    template< typename T >
    Thread(T *obj, void (T::*mfct)())
            :m_realThread(&Thread::run,this)
    {
        m_function = [obj,mfct](){ (obj->*mfct)(); };
    }

    inline void start() { m_realThread.launch();m_stop=false; }
    void stop();
    inline void pause(){ m_paused = true; }
    inline void resume(){ m_paused = false; }

    ~Thread();

private:

    void run();

    volatile bool m_stop = false;
    volatile bool m_paused = false;
    sf::Thread m_realThread;
    std::function<void(void)> m_function;
};


#endif //UNIJAM_THREAD_H
