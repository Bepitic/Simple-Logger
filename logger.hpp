#pragma once
/******************************************************************************
 * @file    logger.hpp
 * @brief   Singleton Logger C++17 //Log::Err() //Log::Inf() //Log::Warn()
 * @author  Francisco Amoros Cubells
 * @date    02 oct, 2020
 *****************************************************************************/
#include <string>
#include <iostream>

// Use Case:
//Log::Err("linea",a,a<b,"a<b...") //Log::Inf() //Log::Warn()

class Log
{
    private: /* Config */
        const static bool Power_on_logger = true;
        const bool Debug_mode = true;
        const bool Print_Console = true;
        const bool Print_File = true;
        //const char* File_name = "%d-%m-%y-Logger.log";
        //const std::string File_name = "%d-%m-%y-Logger.log";
        const bool On_folder = true;
        const char* Folder_name = "Log";

        const bool On_Json = true;
        const bool Order_by_level = true;

    public:

        static Log& Get()
        {
            static Log _log;
            return _log;
        }

        static void Err()
        {
            if constexpr(Power_on_logger)
            { return Get().Error(); }
        }

        static void Warn()
        {
            if constexpr(Power_on_logger)
            { return Get().Warning(); }
        }

        static void Inf()
        {
            if constexpr(Power_on_logger)
            { return Get().Information(); }
        }

    private:
        //Delete ways to instantiate the class and allow to construct private.
        Log() = default;
        Log(const Log&) = delete;
        Log(Log &&) = delete;

        Log &operator =(const Log &) = delete;
        Log &operator =(Log &&) = delete;

        void Error(){std::cout<<"Error"<<std::endl;}
        void Warning(){std::cout<<"Warning"<<std::endl;}
        void Information(){std::cout<<"Information"<<std::endl;}
};
