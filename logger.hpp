#pragma once
/******************************************************************************
 * @file    logger.hpp
 * @brief   Singleton Logger //Log::Err() //Log::Inf() //Log::Warn()
 * @author  Francisco Amoros Cubells
 * @date    02 oct, 2020
 *****************************************************************************/
#include <string>

// Use Case:
//Log::Err("linea",a,a<b,"a<b...") //Log::Inf() //Log::Warn()

class Log
{
    private: /* Config */
        const bool Power_on_logger = true;
        const bool Debug_mode = true;
        const bool Print_Console = true;
        const bool Print_File = true;
        const char* File_name = "%d-%m-%y-Logger.log";
        //const std::string File_name = "%d-%m-%y-Logger.log";
        const bool On_folder = true;
        const char* Folder_name = "Log";


        const bool On_Json = true;
        const bool order_by_level = true;

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
