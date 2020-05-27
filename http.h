#ifndef HTTP_H_
#define HTTP_H_

#include<stdio.h>
#include<string.h>	
#include<stdlib.h>	
#include<sys/socket.h>
#include<arpa/inet.h>	
#include<unistd.h>
#include<pthread.h>

//function prototips
void createServer(uint16_t port);

//socket
int sock;
void route();

// Client requests
struct requests
{
    char *method, *uri, *arg0, *arg1, *arg2;
}req;

//server responds
struct responds
{
    char *msg;
}res;

//macro for `route()`
#define ROUTE_START() \
    if(req.arg0 = strtok(req.uri,"/")){\
        req.arg1 = strtok(NULL,"/");\
        req.arg2 = strtok(NULL,"/");}\
    else req.arg0="/";\
    if (0) {  
#define ROUTE(METHOD,URI)   } else if (strcmp(URI,req.arg0)==0&&strcmp(METHOD,req.method)==0) {
#define ROUTE_GET(URI)      ROUTE("GET", URI) 
#define ROUTE_POST(URI)     ROUTE("POST", URI) 
#define ROUTE_END()         } 

#endif