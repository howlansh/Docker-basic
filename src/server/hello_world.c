#include <fcgiapp.h>
#include <stdio.h>

int main(void) {
    // Открываем FastCGI сокет
    int sockfd = FCGX_OpenSocket("127.0.0.1:8080", 100);
    if (sockfd < 0) {
        fprintf(stderr, "Ошибка открытия FastCGI сокета\n");
        return 1;
    }

    FCGX_Request req;
    FCGX_Init();
    FCGX_InitRequest(&req, sockfd, 0);

    while (FCGX_Accept_r(&req) >= 0) {
        // Отправляем HTTP-заголовки
        FCGX_FPrintF(req.out, "Content-type: text/html\r\n\r\n");

        // Отправляем тело HTML-страницы
        FCGX_FPrintF(req.out, "Hello World!");
        FCGX_Finish_r(&req);
    }

    FCGX_Finish_r(&req);
    // Завершающие действия - запись статистики, логгирование ошибок и т.п. 

    return 0;
}
// Установим пакет 'libfcgi-dev'
// Компилируем командой 'gcc -Wall -Werror -Wextra hello_world.c -lfcgi'
// -lfcgi указывает компилятору линковать соответствующую библиотеку FastCGI.