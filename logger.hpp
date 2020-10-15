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
        const static bool Print_Console = true;
        const static bool Print_File = true;
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

        template <typename... Args>
        static void Err(Args... a)
        {
            if constexpr(Power_on_logger)
            { return Get().Error(a...); }
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

        template <typename... Args>
        void Error(Args... a)
        {
            if constexpr(Print_Console)
            {
                p_console("Error::", a...);
            }

            if constexpr(Print_File)
            {
            }
        }

        template <typename... Args>
        void Warning(Args... a)
        {
            if constexpr(Print_Console)
            {
                p_console("Warning::", a...);
            }

            if constexpr(Print_File)
            {
            }
        }

        template <typename... Args>
        void Information(Args... a)
        {
            if constexpr(Print_Console)
            {
                p_console("Information::", a...);
            }

            if constexpr(Print_File)
            {
            }
        }

        template <typename T,typename... Args>
        void p_file( T head, Args... a)
        {
            std::cout << head;
            p_file(a...);
        }

        void p_file()
        {
            std::cout << std::endl;
        }

        template <typename T,typename... Args>
        void p_console( T head, Args... a)
        {
            std::cout << head;
            p_console(a...);
        }

        void p_console()
        {
            std::cout << std::endl;
        }
};
