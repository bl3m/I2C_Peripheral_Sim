@echo off
setlocal

set "dir=C:\Users\cleme\Documents\I2C_Peripheral_Sim"

cppcheck --template=gcc -v -itm4c123gh6pm_startup_ccs_gcc.c "%dir%"