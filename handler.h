#pragma once
#ifndef HANDLER
#define HANDLER

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Types of handlers 
typedef enum
{
    CONSOLE,
    LOG_FILE,
    SERVER
}handler_t;

typedef enum
{
    LOG_OFF,
    LOG_VERBOSE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;  

//Struct to hold the log details
typedef struct
{
    int level;
    char* time;
    char* message;
}logEvent;

//Struct to define the handlers
typedef struct
{
    int type;
    int level;
}LogHandler;

//Global array that holds the 3 handlers
static LogHandler handlers[3];

//Function to set the level in the each handler from wich level to log
void set_logger_handler(int type, int level);

//Function that initial the handlers
void logger_init();


#endif // !HANDLER
