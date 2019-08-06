#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#define BACK_LOG 1000
#define BUFFER_SIZE 1024
char buffer[BUFFER_SIZE] = {0};
char path[] = "echo_sock";
void handleError(char *msg) { //错误处理函数
    perror(msg);
    exit(-1);
}

void bindToAddress(int serverSocket) { //将socket与某个地址绑定
    struct sockaddr_un address;
    //memset(&address, 0, sizeof(address));
    address.sun_family = AF_UNIX;//使用Unix domain
    //strncpy(address.sun_path, path, sizeof(address.sun_path)-1);
    //strncpy(address.sun_path, path, sizeof(path));
    strcpy(address.sun_path + 1, path);
    address.sun_path[0] = 0;
    socklen_t addrlen = sizeof(address.sun_family) + sizeof(path);
    if (remove(path) == -1 && errno != ENOENT) { //绑定之前先要将这个路径对应的文件删除，否则会报EADDRINUSE
        handleError("删除失败");
    }
    if (bind(serverSocket, (struct sockaddr *)&address, addrlen) == -1) {
        handleError("地址绑定失败");
    }
}

void echo(int socket) {
    int numberOfReaded, numberOfWrited = 0;
    while (true) {
        numberOfReaded = recv(socket, buffer, BUFFER_SIZE, 0);//读取客户端进程发送的数据
        if (numberOfReaded == -1) {
            handleError("读取数据错误");
        } else if (numberOfReaded == 0) {
            printf("客户端关闭连接\n");
            close(socket);
            return;
        }
        printf("收到对端进程数据长度为%d，开始echo", numberOfReaded);
        if (numberOfReaded > 0) {
            numberOfWrited = write(socket, buffer, numberOfReaded);//然后原版返回
            printf("  写入的结果为%d\n", numberOfWrited);
        }
    }
}

void handleRequest(int serverSocket) {
    int socket = accept(serverSocket, NULL, NULL);//监听客户端的请求，没有请求到来的话会一直阻塞
    if (socket == -1) {
        handleError("accept 错误");
    }
    puts("client发起连接...");
    echo(socket);
}
int main(void) {
    int serverSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        handleError("创建socket失败");
    }
    bindToAddress(serverSocket);
    if (listen(serverSocket, BACK_LOG) == -1) {//转为被动模式
        handleError("监听失败");
    }
    while (true) {
        handleRequest(serverSocket);
    }
}