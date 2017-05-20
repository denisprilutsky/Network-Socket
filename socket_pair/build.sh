#!/bin/bash

clear

BUILD_NAME="sockpair"

gcc $(pwd)/${BUILD_NAME}.c -o $(pwd)/${BUILD_NAME}

./${BUILD_NAME}
