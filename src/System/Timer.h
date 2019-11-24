//
// Created by asphox on 19/11/2019.
//

#ifndef UNIJAM_TIMER_H
#define UNIJAM_TIMER_H

#include <cstdint>
#include <vector>
#include <iostream>
#include <SFML/System.hpp>

#include "Thread.h"

template< typename T >
class Timer
{
public:
    Timer() = default;

    explicit Timer(uint32_t periodMS)
    :m_thread(this,&Timer<T>::update)
    ,m_periodMS(periodMS)
    {
    }

    inline void setPeriodMS(uint32_t periodMS)
    {
        m_periodMS = periodMS;
    }

    inline void start()
    {
        m_thread.start();
    }

    inline void stop()
    {
        m_thread.stop();
        m_runned = false;
    }


    void addCallBack(T* ptr,void(T::*mfct)(void))
    {
        m_callBacks.push_back( std::make_pair(ptr,mfct) );
    }

private:

    void update()
    {
        if(m_runned)
        {
            for(auto it : m_callBacks)
            {
                ((it.first)->*(it.second))();
            }
            sf::sleep(sf::milliseconds(m_periodMS));
        } else
        {
            m_runned = true;
        }

    }

    Thread m_thread;
    uint32_t m_periodMS = 0;
    std::vector< std::pair<T*,void(T::*)(void)> > m_callBacks;
    bool m_runned = false;
};


#endif //UNIJAM_TIMER_H
