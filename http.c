#include "http.h"

void *connection_handler(void *);

void createServer(uint16_t port)
{
	int socket_desc, c, read_size, tr=1, *new_sock, new_socket;
	struct sockaddr_in server , client;
	char client_message[2000];
    pthread_t sniffer_thread;

    //Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( port );
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);

    if (setsockopt(socket_desc,SOL_SOCKET,SO_REUSEADDR,&tr,sizeof(int)) == -1) {
        perror("Socket failed"); 
        exit(EXIT_FAILURE);
    }
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("Bind failed"); 
        exit(EXIT_FAILURE);
	}
	
	//Listen
	if (listen(socket_desc , 3) < 0)
    {
        perror("Listen failed"); 
        exit(EXIT_FAILURE);
    }
    
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
    fflush(stdout);

	c = sizeof(struct sockaddr_in);

	while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
	{
        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) &new_socket) < 0)
        {
            perror("Thread failed"); 
            exit(EXIT_FAILURE);;
        } 
	}
	
	if (new_socket<0)
	{
		perror("Socket failed"); 
        exit(EXIT_FAILURE);
	}
}

void *connection_handler(void *socket_desc)
{

    //Get the socket descriptor
    sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];
       
    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        if ((req.method = strtok(client_message, " ")) && (req.uri = strtok(NULL, " "))){
            route();
        }
        else
        {
            res.msg = "HTTP/1.1 500 Not Handled\r\n\r\n";
            write( sock, res.msg , strlen(res.msg));
        }
        
        close(sock);
    }

    return 0;
}