#include "logger.h"

//Array to hold the pointers of the logging functions
void (*handlerFunc[3])(logEvent*) = { log_to_console, log_to_logFile, log_to_server };

//This array using to log type of error
char* logLevelArr[5] = { "VERBOSE","DEBUG","INFO","WARNING","ERROR" };

//Global buf to the server
char* serverBuf = NULL;

void log_to_console(logEvent* ev)
{
    printf("%s ", ev->time);
    printf("%s ", logLevelArr[ev->level]);
    printf("%s \n", ev->message);
}

void log_to_logFile(logEvent* ev)
{
    FILE* logFile = fopen("log_file", "a");

    fprintf(logFile, "%s ", logLevelArr[ev->level]);
    fprintf(logFile, "%s ", ev->time);
    fprintf(logFile, "%s\n", ev->message);
    
    fclose(logFile);
}

void log_to_server(logEvent *ev)
{
    int x = 0;
    if (serverBuf != NULL)
    {
        x = strlen(serverBuf);
    }
    serverBuf = realloc(serverBuf, x +strlen(ev->message) + strlen(ev->time)+ strlen(logLevelArr[ev->level]));
    strcpy(serverBuf, ev->time);
    strcat(serverBuf, " ");
    strcat(serverBuf, logLevelArr[ev->level]);
    strcat(serverBuf, " ");
    strcat(serverBuf, ev->message); 
}

void logger_get_time(logEvent* ev)
{
	time_t tm;
	char buf[10];
	struct tm* tm_info;

	tm = time(NULL);
    tm_info = localtime(&tm);
    strftime(buf, 10, "%H:%M:%S", tm_info);
    buf[9] = '\0';
    ev->time = (char*)strdup(buf);
}

void create_log_event(int level, char* message)
{
    logEvent ev;
    ev.level = level;
    ev.message = malloc(sizeof(char) * strlen(message)+1);
    if (ev.message == NULL) return;
    strcpy(ev.message, message);
    strcat(ev.message, "\0");
    logger_get_time(&ev);
    logging(&ev);
    free(ev.message);
}

void logging(logEvent* event)
{
    for (int i = 0; i < 3; i++)
    {
        if (event->level <= handlers[i].level)
        {
            handlerFunc[i](event);
        }
    }    
}

char* retrieve_server_buffer()
{
    return serverBuf;
}


void delete_servBuf()
{ 
    free(serverBuf);
    serverBuf = NULL;
}
