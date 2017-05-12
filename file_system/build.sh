#!/bin/bash

clear

CLIENT_NAME=fsclient
SERVER_NAME=fsserver

gcc $(pwd)/$(CLIENT_NAME).c -o $(pwd)/$(CLIENT_NAME)

gcc $(pwd)/$(SERVER_NAME).c -o $(pwd)/$(SERVER_NAME)

./$(CLIENT_NAME)
./$(SERVER_NAME)