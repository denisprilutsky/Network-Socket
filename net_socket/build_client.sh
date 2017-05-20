#!/bin/bash

clear

CLIENT_NAME="netclient"

gcc $(pwd)/${CLIENT_NAME}.c -o $(pwd)/${CLIENT_NAME}

./${CLIENT_NAME} 127.0.0.1 5717
