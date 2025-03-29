#!/bin/bash

FMT_LT_GREEN='\e[92m'
FMT_GREEN='\e[32m'
FMT_RED='\e[31m'
FMT_RESET='\e[0m'

STD_OUT ()
{
    local TEXT=$1
    echo -e "${FMT_RED}MAKE${FMT_RESET}: ${FMT_GREEN}$TEXT${FMT_RESET}"
}


STD_OUT "clean all output files from \"./build\" and rebuild, log to \"make.log\", (overwrites last) ...\n"
make -f makefile clean > make.log
make -f makefile >> make.log

STD_OUT "./make.log ..."
cat make.log
STD_OUT "EOF\n"

STD_OUT "make clean done."