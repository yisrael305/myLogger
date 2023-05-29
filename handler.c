#include "handler.h"
#include "logger.h"

void set_logger_handler(int type, int level)
{
    switch (type) 
    {
    case CONSOLE:
        handlers[type].type = type;
        handlers[type].level = level;
        break;
    case LOG_FILE:
        handlers[type].type = type;
        handlers[type].level = level;
        break;
    case SERVER:
        handlers[type].type = type;
        handlers[type].level = level;
        break;
    default:
        break;
    }
}

void logger_init()
{
    for (int i = 0; i < 3; i++)
    {
        handlers[i].type = i;
        handlers[i].level = LOG_OFF; //The default is to print any level
    }
}


