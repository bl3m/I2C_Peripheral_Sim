@echo off
setlocal

:set_args
set "build_dir=C:\Users\cleme\Documents\I2C_Peripheral_Sim\Release"
cd "%build_dir%"
rem set PATH

:run_make
make all

