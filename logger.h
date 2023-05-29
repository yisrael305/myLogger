#pragma once
#include "handler.h"

#define log_v(messege) create_log_event(LOG_VERBOSE, messege)
#define log_d(messege) create_log_event(LOG_DEBUG, messege)
#define log_w(messege) create_log_event(LOG_WARNING, messege)
#define log_e(messege) create_log_event(LOG_ERROR, messege)
#define log_i(messege) create_log_event(LOG_INFO, messege)

//Format the log to the consule
void log_to_console(logEvent *ev);

//Format the log to the file
void log_to_logFile(logEvent *ev);

//Format the log to the server
void log_to_server(logEvent *ev);

//Function to get the time of the log and make him string
void logger_get_time(logEvent* ev);

//Create a struct to hold the log details
void create_log_event(int level, char* message);

//Function that check on the handlers and logging accordinly
void logging(logEvent* event);

//Function to retrieve the server buffer
char* retrieve_server_buffer();

void delete_servBuf();