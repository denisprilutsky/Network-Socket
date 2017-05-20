#!/bin/bash

clear

rm $(pwd)/socket.soc

SERVER_NAME="fsserver"

gcc $(pwd)/${SERVER_NAME}.c -o $(pwd)/${SERVER_NAME}

./${SERVER_NAME}
