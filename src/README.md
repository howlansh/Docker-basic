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
* 
* ![](./screenshots/img_2.2.png)
* 
* ![](./screenshots/img_2.3.png)
* 
* ![](./screenshots/img_2.4.png)
* 
* ![](./screenshots/img_2.5.png)
* 
* ![](./screenshots/img_2.6.png)
## Part 3. Мини веб-сервер
* 
* ![](./screenshots/img_3.1.png)
## Part 4. Свой докер
* 
* ![](./screenshots/img_4.1.png)
## Part 5. Dockle
* 
* ![](./screenshots/img_5.1.png)
## Part 6. Базовый Docker Compose
* 
* ![](./screenshots/img_6.1.png)