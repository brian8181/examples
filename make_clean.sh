#!/bin/bash

make -f makefile clean | tee make.log
make -f makefile | tee -a make.log