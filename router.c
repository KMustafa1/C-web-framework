#include "http.h"

int main(int argc, char **argv)
{
    createServer(atoi(argv[1]));
    return 0;
}

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        res.msg = 
        "HTTP/1.1 200 ok\r\n\r\n"
        "Hello World";
        write( sock, res.msg , strlen(res.msg));
    }

    ROUTE_POST("/")
    {
        
    }
  
    ROUTE_END()
}