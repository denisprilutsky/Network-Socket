#!/bin/bash

clear

SERVER_NAME="netserver"

gcc $(pwd)/${SERVER_NAME}.c -o $(pwd)/${SERVER_NAME}

./${SERVER_NAME} 127.0.0.1 5000
