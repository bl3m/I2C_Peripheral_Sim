@echo off

set "file=C:\Users\cleme\Documents\I2C_Peripheral_Sim\Debug\I2C_Peripheral_Sim.out"
set "config=C:\Users\cleme\Documents\I2C_Peripheral_Sim\targetConfigs\Tiva_TM4C123GH6PM.ccxml"
set "dslite=C:\ti\uniflash_9.1.0\dslite.bat"

"%dslite%" --config=%config% --verbose "%file%"
