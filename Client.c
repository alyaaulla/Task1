#include<stdio.h>
	#include<stdlib.h>
	#include<sys/types.h>
	#include<arpa/inet.h>
	#include<unistd.h>
	
	int main(){
		char server_msg[1024]="ni hao";
		char server_respond[1024];
		int net_socket;
		net_socket = socket(AF_INET,SOCK_STREAM,0);
	
		struct sockaddr_in server_address;
		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(50000);
		server_address.sin_addr.s_addr = inet_addr("192.168.146.129");
	
		int status = connect(net_socket,(struct sockaddr *) 
	&server_address,sizeof(server_address));
	
		if(status == -1){
		
		printf("error %s\n");
		}
	
		send(net_socket,server_msg,sizeof(server_msg),0);
	
		recv(net_socket,server_respond,sizeof(server_respond),0);
	
		printf("server message ; %s\n ",server_respond);
		close(net_socket);
		
		return 0;
	}
