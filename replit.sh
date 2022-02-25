# !/bin/bash

# Color Constants
RESTORE='\033[0m'

RED='\033[00;31m'
GREEN='\033[00;32m'
YELLOW='\033[00;33m'
BLUE='\033[00;34m'
PURPLE='\033[00;35m'
CYAN='\033[00;36m'
LIGHTGRAY='\033[00;37m'

LRED='\033[01;31m'
LGREEN='\033[01;32m'
LYELLOW='\033[01;33m'
LBLUE='\033[01;34m'
LPURPLE='\033[01;35m'
LCYAN='\033[01;36m'
WHITE='\033[01;37m'


if [ -d ../build ]; then
    rm -rf ../build
fi
mkdir -p ../build
cd ../build
cmake ../calci++/
make

if [ -f ./calci++_test ]; then
    printf "\n${LBLUE}Running tests...${RESTORE}\n"
    ./calci++_test
else
    printf "\n${LRED}Error: ./calci++_test not found.${RESTORE}\n"
fi

# if [ -f ./calci++_main ]; then
#     printf "\n${LBLUE}Running main...${RESTORE}\n"
#     ./calci++_main
# else
#     printf "\n${LRED}Error: ./calci++_main not found.${RESTORE}\n"
# fi

cd ../calci++/