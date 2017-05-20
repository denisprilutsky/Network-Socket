#!/bin/bash

clear

#rm $(pwd)/socket.soc

CLIENT_NAME="fsclient"

gcc $(pwd)/${CLIENT_NAME}.c -o $(pwd)/${CLIENT_NAME}

./${CLIENT_NAME}
