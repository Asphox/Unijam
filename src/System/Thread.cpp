//
// Created by asphox on 20/11/2019.
//

#include "Thread.h"

Thread::Thread(void (*fct)())
:m_realThread(&Thread::run,this)
{
    m_function = [fct](){ fct(); };
}


void Thread::run()
{
    while(!m_stop)
    {
        if(m_paused)
        {
            sf::sleep(sf::milliseconds(1));
        }
        else
        {
            m_function();
        }
    }
}

void Thread::stop()
{
    m_stop = true;
    m_realThread.wait();
}

Thread::~Thread()
{
    stop();
}