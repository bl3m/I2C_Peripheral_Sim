/*
 * main.c
 *
 *  Created on: Jun 20, 2025
 *      Author: CS
 */

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/interrupt.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "MAX7300.h"
#include "main.h"

uint8_t addresses[4] = {0x40, 0x41, 0x42, 0x43};
MAX7300 devices[4];
uint32_t i2cCommand[4] = {0, 0, 0, 0};
uint32_t i2cDataRx[4] = {0, 0, 0, 0};
uint8_t txData;

int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN
                            | SYSCTL_XTAL_16MHZ);
    I2C0_Init();
    I2C1_Init();
    uint8_t i;
    for(i = 0; i < 4; i++){
        MAX7300Init(&devices[i], addresses[i], AAI);
    }
    IntMasterEnable();
    while(1){

    }
}

void I2C0_Init(void){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    GPIOPinConfigure(GPIO_PB3_I2C0SDA);
    GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
    GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
    IntEnable(INT_I2C0);
    I2CSlaveIntEnableEx(I2C0_BASE, I2C_SLAVE_INT_DATA);
    I2CSlaveEnable(I2C0_BASE);
    I2CSlaveAddressSet(I2C0_BASE, 0, addresses[0]);
    I2CSlaveAddressSet(I2C0_BASE, 1, addresses[1]);
}

void I2C1_Init(void){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA6_I2C1SCL);
    GPIOPinConfigure(GPIO_PA7_I2C1SDA);
    GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);
    GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);
    IntEnable(INT_I2C1);
    I2CSlaveIntEnableEx(I2C1_BASE, I2C_SLAVE_INT_DATA);
    I2CSlaveEnable(I2C1_BASE);
    I2CSlaveAddressSet(I2C1_BASE, 0, addresses[2]);
    I2CSlaveAddressSet(I2C1_BASE, 1, addresses[3]);
}

void I2C0SlaveIntHandler(void){
    I2CSlaveIntClear(I2C0_BASE); //Clear interrupt flag
    uint32_t checkStatus;
    checkStatus = HWREG(I2C0_BASE + I2C_O_SCSR); //read slave status control register
    checkStatus &= 0x0B;
    //check which slave address was matched
    //check whether the slave was addressed as a transmitter or a receiver
    //if addressed as receiver, determine if command byte was received
    //read or write data to the device
    //clear commandReceived on MAX7300 struct

    if(checkStatus & 0x08 == 0x00){
        //slv addr 1
        if(checkStatus & 0x03 == 0x02){
            //read command
            i2cCommand[0] = I2CSlaveDataGet(I2C0_BASE); //Read data from addr 0x41
            txData = MAX7300ProcessCommand(&devices[0], i2cCommand[0], i2cDataRx[0], READ); //process command
            I2CSlaveDataPut(I2C0_BASE, txData);
        }
        else{
            //write command, wait for data byte or process command if command byte already sent
            if(devices[0].commandReceived){
                i2cDataRx[0] = I2CSlaveDataGet(I2C0_BASE); //Read data from addr 0x41
                MAX7300ProcessCommand(&devices[0], i2cCommand[0], i2cDataRx[0], WRITE); //process command
                devices[0].commandReceived = false;
            }
            else{
                i2cCommand[0] = I2CSlaveDataGet(I2C0_BASE); //Read data from addr 0x41
                devices[0].commandReceived = true;
            }
        }
    }
    else{
        //slv addr 2
        if(checkStatus & 0x03 == 0x02){
            //read command
            i2cCommand[1] = I2CSlaveDataGet(I2C0_BASE); //Read data from addr 0x42
            txData = MAX7300ProcessCommand(&devices[1], i2cCommand[1], i2cDataRx[1], READ); //process command
            I2CSlaveDataPut(I2C0_BASE, txData);
        }
        else{
            //write command, wait for data byte or process command if command byte already sent
            if(devices[1].commandReceived){
                i2cDataRx[1] = I2CSlaveDataGet(I2C0_BASE); //Read data from addr 0x42
                MAX7300ProcessCommand(&devices[1], i2cCommand[1], i2cDataRx[1], WRITE); //process command
                devices[1].commandReceived = false;
            }
            else{
                i2cCommand[1] = I2CSlaveDataGet(I2C0_BASE); //Read data from addr 0x42
                devices[1].commandReceived = true;
            }
        }
    }
    updatePorts();
}

void I2C1SlaveIntHandler(void){
    I2CSlaveIntClear(I2C1_BASE); //Clear interrupt flag
    uint32_t checkStatus;
    checkStatus = HWREG(I2C1_BASE + I2C_O_SCSR); //read slave status control register
    checkStatus &= 0x0B;
    //check which slave address was matched
    //check whether the slave was addressed as a transmitter or a receiver
    //if addressed as receiver, determine if command byte was received
    //read or write data to the device
    //clear commandReceived on MAX7300 struct

    if(checkStatus & 0x08 == 0x00){
        //slv addr 1
        if(checkStatus & 0x03 == 0x02){
            //read command
            i2cCommand[2] = I2CSlaveDataGet(I2C1_BASE); //Read data from addr 0x41
            txData = MAX7300ProcessCommand(&devices[2], i2cCommand[2], i2cDataRx[2], READ); //process command
            I2CSlaveDataPut(I2C1_BASE, txData);
        }
        else{
            //write command, wait for data byte or process command if command byte already sent
            if(devices[2].commandReceived){
                i2cDataRx[2] = I2CSlaveDataGet(I2C1_BASE); //Read data from addr 0x41
                MAX7300ProcessCommand(&devices[2], i2cCommand[2], i2cDataRx[2], WRITE); //process command
                devices[2].commandReceived = false;
            }
            else{
                i2cCommand[2] = I2CSlaveDataGet(I2C1_BASE); //Read data from addr 0x41
                devices[2].commandReceived = true;
            }
        }
    }
    else{
        //slv addr 2
        if(checkStatus & 0x03 == 0x02){
            //read command
            i2cCommand[3] = I2CSlaveDataGet(I2C1_BASE); //Read data from addr 0x42
            txData = MAX7300ProcessCommand(&devices[3], i2cCommand[3], i2cDataRx[3], READ); //process command
            I2CSlaveDataPut(I2C1_BASE, txData);
        }
        else{
            //write command, wait for data byte or process command if command byte already sent
            if(devices[3].commandReceived){
                i2cDataRx[3] = I2CSlaveDataGet(I2C1_BASE); //Read data from addr 0x42
                MAX7300ProcessCommand(&devices[3], i2cCommand[3], i2cDataRx[3], WRITE); //process command
                devices[3].commandReceived = false;
            }
            else{
                i2cCommand[3] = I2CSlaveDataGet(I2C1_BASE); //Read data from addr 0x42
                devices[3].commandReceived = true;
            }
        }
    }
    updatePorts();
}

void updatePorts(){
    //update input ports
}
