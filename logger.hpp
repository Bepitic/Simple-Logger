#pragma once
/******************************************************************************
 * @file    logger.hpp
 * @brief   Singleton Logger //Log::Err() //Log::Inf() //Log::Warn()
 * @author  Francisco Amoros Cubells
 * @date    02 oct, 2020
 *****************************************************************************/

// Use Case:
//Log::Err("linea",a,a<b,"a<b...") //Log::Inf() //Log::Warn()

class Log
{
    public:

        Log(const Log&) = delete;

        static Log& Get()
        {
            static Log _log;
            return _log;
        }

        static void Err(){return Get().Error();}
        static void Warn(){return Get().Warning();}
        static void Inf(){return Get().Information();}

    private:
        Log(){}

        void Error(){}
        void Warning(){}
        void Information(){}
};
