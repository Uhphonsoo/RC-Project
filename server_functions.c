#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>
#include "functions.h"
#include "server_functions.h"
#include "constants.h"

extern int  errcode;
extern int fd, newfd, afd;
extern socklen_t addrlen;
extern struct addrinfo hints, *res;
extern struct sockaddr_in addr;

int create_socket() {

    fd = socket(AF_INET, SOCK_DGRAM, 0); // UDP Socket
    if(fd == -1) {
        perror("ERROR: create_UDP_socket: can't open socket.\n");
        exit(EXIT_FAILURE);
    }
    return fd;
}


void  get_address_info(struct addrinfo *hints, struct addrinfo **res) {

    memset(&(*hints), 0, sizeof((*hints))); 
    (*hints).ai_family = AF_INET;        // IPv4
    (*hints).ai_socktype = SOCK_DGRAM;   // UDP socket

    errcode = getaddrinfo(NULL, PORT, &(*hints), &(*res));
    if(errcode != 0) {
        perror("ERROR: get_address_info_UDP\n");
        exit(EXIT_FAILURE);
    }
}

void create_UDP_server_socket() {

    fd_UDP = socket(AF_INET, SOCK_DGRAM, 0); // UDP Socket
    if(fd_UDP == -1) {
        perror("ERROR: create_UDP_socket: can't open socket.\n");
        exit(EXIT_FAILURE);
    }
}


void get_address_info_server_UDP() {

    memset(&hints_UDP, 0, sizeof(hints_UDP)); 
    hints_UDP.ai_family = AF_INET;        // IPv4
    hints_UDP.ai_socktype = SOCK_DGRAM;   // UDP socket

    errcode = getaddrinfo(DSIP, DSport, &hints_UDP, &res_UDP);
    if(errcode != 0) {
        perror("ERROR: get_address_info_UDP\n");
        exit(EXIT_FAILURE);
    }
}


void create_TCP_server_socket() {

    fd_TCP = socket(AF_INET, SOCK_STREAM, 0); // TCP Socket
    if(fd_TCP == -1) {
        perror("ERROR: create_TCP_socket: can't open socket.\n");
        exit(EXIT_FAILURE);
    }
}


void get_address_info_server_TCP() {

    memset(&hints_TCP, 0, sizeof(hints_TCP)); 
    hints_TCP.ai_family = AF_INET;        // IPv4
    hints_TCP.ai_socktype = SOCK_STREAM;  // TCP socket

    errcode = getaddrinfo(DSIP, DSport, &hints_TCP, &res_TCP);
    if(errcode != 0) {
        perror("ERROR: get_address_info_TCP\n");
        exit(EXIT_FAILURE);
    }
}