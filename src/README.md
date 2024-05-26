## Part 1. Готовый докер
* Берём официальный докер-образ с nginx и скачиваем его при помощи 'docker pull'.
* ![](./screenshots/img_1.1.png)
* Проверяем наличие докер-образа через 'docker images'.
* ![](./screenshots/img_1.2.png)
* Запускаем докер-образ через 'docker run -d [image_id|repository]'. Проверяем, что образ запустился через 'docker ps'.
* ![](./screenshots/img_1.3.png)
* Смотрим информацию о контейнере через 'docker inspect [container_id|container_name]'. По выводу команды определяем размер контейнера:
* ![](./screenshots/img_1.4.png)
* Список замапленных портов и ip контейнера:
* ![](./screenshots/img_1.5.png)
* Останавливаем докер образ через 'docker stop [container_id|container_name]'. Проверяем, что образ остановился через 'docker ps'.
* ![](./screenshots/img_1.6.png)
* Запускаем докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду 'docker run -d -p [port:port]'.
* ![](./screenshots/img_1.7.png)
* Проверяем, что в браузере по адресу localhost:80 доступна стартовая страница nginx.
* ![](./screenshots/img_1.8.png)
* Перезапускаем докер контейнер через 'docker restart [container_id|container_name]'.
* ![](./screenshots/img_1.9.png)
## Part 2. Операции с контейнером
* Прочитаем конфигурационный файл '/etc/nginx/nginx.conf' внутри докер контейнера через команду 'docker exec [container_id|container_name] [command]'.
* ![](./screenshots/img_2.1.png)
* Создаём на локальной машине файл "nginx.conf". Настриваем в нём по пути "/status" отдачу страницы статуса сервера nginx.
* ![](./screenshots/img_2.10.png)
* Скопируем созданный файл "nginx.conf" внутрь докер-образа через команду 'docker cp [file] [container_id]:[path]'.
* ![](./screenshots/img_2.2.png)
* Перезапускаем nginx внутри докер-образа через команду 'docker exec nginx -s reload'.
* ![](./screenshots/img_2.3.png)
* По адресу "localhost:80/status" открываем страничку со статусом сервера nginx.
* ![](./screenshots/img_2.4.png)
* Через 'docker inspect [container_id]' проверим команды, выполняемые при запуске, docker export не экспортирует всю информацию о контейнере — только файловую систему.
* ![](./screenshots/img_2.7.png)
* Экспортируем контейнер в файл "container.tar" через команду 'docker export -o [filename.tar] [container_id]'. Останавливаем контейнер.
* ![](./screenshots/img_2.5.png)
* Удаляем образ через 'docker rmi -f [image_id|repository]'. Флаг 'f', чтобы не удалять перед этим контейнеры. Потом удаляем остановленный контейнер через 'docker rm [container_id].
* ![](./screenshots/img_2.6.png)
* Итак, при импорте дампа обратно в новый образ докера необходимо указать дополнительные флаги для воссоздания контекста. Импортируем контейнер обратно через команду 'docker import --change 'CMD [startup_command]' [filename.tar] [name]'. Запускаем импортированный контейнер как обычно.
* ![](./screenshots/img_2.8.png)
* Проверяем ещё раз "localhost:80/status".
* ![](./screenshots/img_2.9.png)