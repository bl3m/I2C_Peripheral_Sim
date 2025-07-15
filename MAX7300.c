/*
 * MAX7300.c
 *
 *  Created on: Jun 20, 2025
 *      Author: CS
 */
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/debug.h"
#include "MAX7300.h"

/* DESC ----------------------------------------------------------------------
 |
 | ROUTINE NAME:    MAX7300ProcessCommand
 |
 |  DESCRIPTION:    Interpret data sent to I2C Peripheral
 +---------------------------------------------------------------------------*/
uint8_t MAX7300ProcessCommand(MAX7300* device, uint8_t command, uint8_t data, bool rw){
    uint8_t result = 0;
    switch(command){
    case 0x00:
        //NOP
        break;
    case 0x04:
        //Configuration
        break;
    case 0x06:
        //Transition detect mask
        break;
    case 0x07:
        //reserved
        break;
    case 0x09:
        //Port configure P7, P6, P5, P4
        MAX7300Configure(device, PORT4, data);
        break;
    case 0x0A:
        //Port configure P11, P10, P9, P8
        MAX7300Configure(device, PORT8, data);
        break;
    case 0x0B:
        //Port configure P15, P14, P13, P12
        MAX7300Configure(device, PORT12, data);
        break;
    case 0x0C:
        //Port configure P19, P18, P17, P16
        MAX7300Configure(device, PORT16, data);
        break;
    case 0x0D:
        //Port configure P23, P22, P21, P20
        MAX7300Configure(device, PORT20, data);
        break;
    case 0x0E:
        //Port configure P27, P26, P25, P24
        MAX7300Configure(device, PORT24, data);
        break;
    case 0x0F:
        //Port configure P31, P30, P29, P28
        MAX7300Configure(device, PORT28, data);
        break;
    case 0x20:
        //Port 0 Only, N/A
        break;
    case 0x21:
        //Port 1 Only, N/A
        break;
    case 0x22:
        //Port 2 Only, N/A
        break;
    case 0x23:
        //Port 3 Only, N/A
        break;
    case 0x24:
        //Port 4 Only
        if(rw){
            result = MAX7300Read(device, PORT4);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT4, data & 0x01, 1);
        }
        break;
    case 0x25:
        //Port 5 Only
        if(rw){
            result = MAX7300Read(device, PORT5);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT5, data & 0x01, 1);
        }
        break;
    case 0x26:
        //Port 6 Only
        if(rw){
            result = MAX7300Read(device, PORT6);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT6, data & 0x01, 1);
        }
        break;
    case 0x27:
        //Port 7 Only
        if(rw){
            result = MAX7300Read(device, PORT7);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT7, data & 0x01, 1);
        }
        break;
    case 0x28:
        //Port 8 Only
        if(rw){
            result = MAX7300Read(device, PORT8);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT8, data & 0x01, 1);
        }
        break;
    case 0x29:
        //Port 9 Only
        if(rw){
            result = MAX7300Read(device, PORT9);
            result = result & 0x01;
        }
        else{
            result = MAX7300WriteOutput(device, PORT9, data & 0x01, 1);
        }
        break;
    case 0x2A:
        //Port 10 Only
        if(rw){
            result = MAX7300Read(device, PORT10);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT10, data & 0x01, 1);
        }
        break;
    case 0x2B:
        //Port 11 Only
        if(rw){
            result = MAX7300Read(device, PORT11);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT11, data & 0x01, 1);
        }
        break;
    case 0x2C:
        //Port 12 Only
        if(rw){
            result = MAX7300Read(device, PORT12);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT12, data & 0x01, 1);
        }
        break;
    case 0x2D:
        //Port 13 Only
        if(rw){
            result = MAX7300Read(device, PORT5);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT5, data & 0x01, 1);
        }
        break;
    case 0x2E:
        //Port 14 Only
        if(rw){
            result = MAX7300Read(device, PORT14);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT14, data & 0x01, 1);
        }
        break;
    case 0x2F:
        //Port 15 Only
        if(rw){
            result = MAX7300Read(device, PORT15);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT15, data & 0x01, 1);
        }
        break;
    case 0x30:
        //Port 16 Only
        if(rw){
            result = MAX7300Read(device, PORT16);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT16, data & 0x01, 1);
        }
        break;
    case 0x31:
        //Port 17 Only
        if(rw){
            result = MAX7300Read(device, PORT17);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT17, data & 0x01, 1);
        }
        break;
    case 0x32:
        //Port 18 Only
        if(rw){
            result = MAX7300Read(device, PORT18);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT18, data & 0x01, 1);
        }
        break;
    case 0x33:
        //Port 19 Only
        if(rw){
            result = MAX7300Read(device, PORT19);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT19, data & 0x01, 1);
        }
        break;
    case 0x34:
        //Port 20 Only
        if(rw){
            result = MAX7300Read(device, PORT20);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT20, data & 0x01, 1);
        }
        break;
    case 0x35:
        //Port 21 Only
        if(rw){
            result = MAX7300Read(device, PORT21);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT21, data & 0x01, 1);
        }
        break;
    case 0x36:
        //Port 22 Only
        if(rw){
            result = MAX7300Read(device, PORT22);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT22, data & 0x01, 1);
        }
        break;
    case 0x37:
        //Port 23 Only
        if(rw){
            result = MAX7300Read(device, PORT23);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT23, data & 0x01, 1);
        }
        break;
    case 0x38:
        //Port 24 Only
        if(rw){
            result = MAX7300Read(device, PORT24);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT24, data & 0x01, 1);
        }
        break;
    case 0x39:
        //Port 25 Only
        if(rw){
            result = MAX7300Read(device, PORT25);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT25, data & 0x01, 1);
        }
        break;
    case 0x3A:
        //Port 26 Only
        if(rw){
            result = MAX7300Read(device, PORT26);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT26, data & 0x01, 1);
        }
        break;
    case 0x3B:
        //Port 27 Only
        if(rw){
            result = MAX7300Read(device, PORT27);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT27, data & 0x01, 1);
        }
        break;
    case 0x3C:
        //Port 28 Only
        if(rw){
            result = MAX7300Read(device, PORT28);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT28, data & 0x01, 1);
        }
        break;
    case 0x3D:
        //Port 29 Only
        if(rw){
            result = MAX7300Read(device, PORT29);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT29, data & 0x01, 1);
        }
        break;
    case 0x3E:
        //Port 30 Only
        if(rw){
            result = MAX7300Read(device, PORT30);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT30, data & 0x01, 1);
        }
        break;
    case 0x3F:
        //Port 31 Only
        if(rw){
            result = MAX7300Read(device, PORT31);
            result = result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT31, data & 0x01, 1);
        }
        break;
    case 0x40:
        //Ports 4-7
        if(rw){
            result = MAX7300Read(device, PORT4);
            result = result & 0x0F;
        }
        else{
            MAX7300WriteOutput(device, PORT4, data & 0x0F, 4);
        }
        break;
    case 0x41:
        //Ports 4-8
        if(rw){
            result = MAX7300Read(device, PORT4);
            result = result & 0x1F;
        }
        else{
            MAX7300WriteOutput(device, PORT4, data & 0x01F, 5);
        }
        break;
    case 0x42:
        //Ports 4-9
        if(rw){
            result = MAX7300Read(device, PORT4);
            result = result & 0x3F;
        }
        else{
            MAX7300WriteOutput(device, PORT4, data & 0x03F, 6);
        }
        break;
    case 0x43:
        //Ports 4-10
        if(rw){
            result = MAX7300Read(device, PORT4);
            result = result & 0x7F;
        }
        else{
            MAX7300WriteOutput(device, PORT4, data & 0x07F, 7);
        }
        break;
    case 0x44:
        //Ports 4-11
        if(rw){
            result = MAX7300Read(device, PORT4);
        }
        else{
            MAX7300WriteOutput(device, PORT4, data, 8);
        }
        break;
    case 0x45:
        //Ports 5-12
        if(rw){
            result = MAX7300Read(device, PORT5);
        }
        else{
            MAX7300WriteOutput(device, PORT4, data, 8);
        }
        break;
    case 0x46:
        //Ports 6-13
        if(rw){
            result = MAX7300Read(device, PORT6);
        }
        else{
            MAX7300WriteOutput(device, PORT6, data, 8);
        }
        break;
    case 0x47:
        //Ports 7-14
        if(rw){
            result = MAX7300Read(device, PORT7);
        }
        else{
            MAX7300WriteOutput(device, PORT7, data, 8);
        }
        break;
    case 0x48:
        //Ports 8-15
        if(rw){
            result = MAX7300Read(device, PORT8);
        }
        else{
            MAX7300WriteOutput(device, PORT8, data, 8);
        }
        break;
    case 0x49:
        //Ports 9-16
        if(rw){
            result = MAX7300Read(device, PORT9);
        }
        else{
            MAX7300WriteOutput(device, PORT9, data, 8);
        }
        break;
    case 0x4A:
        //Ports 10-17
        if(rw){
            result = MAX7300Read(device, PORT10);
        }
        else{
            MAX7300WriteOutput(device, PORT10, data, 8);
        }
        break;
    case 0x4B:
        //Ports 11-18
        if(rw){
            result = MAX7300Read(device, PORT11);
        }
        else{
            MAX7300WriteOutput(device, PORT11, data, 8);
        }
        break;
    case 0x4C:
        //Ports 12-19
        if(rw){
            result = MAX7300Read(device, PORT12);
        }
        else{
            MAX7300WriteOutput(device, PORT12, data, 8);
        }
        break;
    case 0x4D:
        //Ports 13-20
        if(rw){
            result = MAX7300Read(device, PORT13);
        }
        else{
            MAX7300WriteOutput(device, PORT13, data, 8);
        }
        break;
    case 0x4E:
        //Ports 14-21
        if(rw){
            result = MAX7300Read(device, PORT14);
        }
        else{
            MAX7300WriteOutput(device, PORT14, data, 8);
        }
        break;
    case 0x4F:
        //Ports 15-22
        if(rw){
            result = MAX7300Read(device, PORT15);
        }
        else{
            MAX7300WriteOutput(device, PORT15, data, 8);
        }
        break;
    case 0x50:
        //Ports 16-23
        if(rw){
            result = MAX7300Read(device, PORT16);
        }
        else{
            MAX7300WriteOutput(device, PORT16, data, 8);
        }
        break;
    case 0x51:
        //Ports 17-24
        if(rw){
            result = MAX7300Read(device, PORT17);
        }
        else{
            MAX7300WriteOutput(device, PORT17, data, 8);
        }
        break;
    case 0x52:
        //Ports 18-25
        if(rw){
            result = MAX7300Read(device, PORT18);
        }
        else{
            MAX7300WriteOutput(device, PORT18, data, 8);
        }
        break;
    case 0x53:
        //Ports 19-26
        if(rw){
            result = MAX7300Read(device, PORT19);
        }
        else{
            MAX7300WriteOutput(device, PORT19, data, 8);
        }
        break;
    case 0x54:
        //Ports 20-27
        if(rw){
            result = MAX7300Read(device, PORT20);
        }
        else{
            MAX7300WriteOutput(device, PORT20, data, 8);
        }
        break;
    case 0x55:
        //Ports 21-28
        if(rw){
            result = MAX7300Read(device, PORT21);
        }
        else{
            MAX7300WriteOutput(device, PORT21, data, 8);
        }
        break;
    case 0x56:
        //Ports 22-29
        if(rw){
            result = MAX7300Read(device, PORT22);
        }
        else{
            MAX7300WriteOutput(device, PORT22, data, 8);
        }
        break;
    case 0x57:
        //Ports 23-30
        if(rw){
            result = MAX7300Read(device, PORT23);
        }
        else{
            MAX7300WriteOutput(device, PORT23, data, 8);
        }
        break;
    case 0x58:
        //Ports 24-31
        if(rw){
            result = MAX7300Read(device, PORT24);
        }
        else{
            MAX7300WriteOutput(device, PORT24, data, 8);
        }
        break;
    case 0x59:
        //Ports 25-31
        if(rw){
            result = MAX7300Read(device, PORT25);
            result =  result & 0x7F;
        }
        else{
            MAX7300WriteOutput(device, PORT25, data & 0x7F, 7);
        }
        break;
    case 0x5A:
        //Ports 26-31
        if(rw){
            result = MAX7300Read(device, PORT26);
            result =  result & 0x3F;
        }
        else{
            MAX7300WriteOutput(device, PORT26, data & 0x3F, 6);
        }
        break;
    case 0x5B:
        //Ports 27-31
        if(rw){
            result = MAX7300Read(device, PORT27);
            result =  result & 0x1F;
        }
        else{
            MAX7300WriteOutput(device, PORT27, data & 0x1F, 5);
        }
        break;
    case 0x5C:
        //Ports 28-31
        if(rw){
            result = MAX7300Read(device, PORT28);
            result =  result & 0x0F;
        }
        else{
            MAX7300WriteOutput(device, PORT28, data & 0x0F, 4);
        }
        break;
    case 0x5D:
        //Ports 29-31
        if(rw){
            result = MAX7300Read(device, PORT29);
            result =  result & 0x07;
        }
        else{
            MAX7300WriteOutput(device, PORT29, data & 0x07, 3);
        }
        break;
    case 0x5E:
        //Ports 30-31
        if(rw){
            result = MAX7300Read(device, PORT30);
            result =  result & 0x03;
        }
        else{
            MAX7300WriteOutput(device, PORT30, data & 0x03, 2);
        }
        break;
    case 0x5F:
        //Port 31 only
        if(rw){
            result = MAX7300Read(device, PORT31);
            result =  result & 0x01;
        }
        else{
            MAX7300WriteOutput(device, PORT31, data & 0x01, 1);
        }
        break;
    default:
        break;
    }
    return result;
}

/* DESC ----------------------------------------------------------------------
 |
 | ROUTINE NAME:    MAX7300Init
 |
 |  DESCRIPTION:    Initialize MAX7300 struct
 +---------------------------------------------------------------------------*/
void MAX7300Init(MAX7300* device, uint8_t address, uint8_t package){
    uint8_t i;
    device->address = address;
    device->package = package;
    for(i = 0; i < 32; i++){
        device->config[i] = 0;
        device->ports[i] = 0;
    }
    device->commandReceived = false;
}

/* DESC ----------------------------------------------------------------------
 |
 | ROUTINE NAME:    MAX7300Read
 |
 |  DESCRIPTION:    Read data from the MAX7300
 +---------------------------------------------------------------------------*/
uint8_t MAX7300Read(MAX7300* device, uint8_t port){
    uint8_t data = 0x00, i = 0;
    while(port < 32 && i < 8){
        data = data | ((uint8_t)(device->ports[port]) << i);
        port++;
        i++;
    }
    return data;
}

/* DESC ----------------------------------------------------------------------
 |
 | FUNCTION NAME:    MAX7300WriteOutput
 |
 |  DESCRIPTION:    Write data to the MAX7300
 +---------------------------------------------------------------------------*/
uint8_t MAX7300WriteOutput(MAX7300* device, uint8_t port, uint8_t data, uint8_t length){
    uint8_t i;
    for(i = 0; i < length; i++){
        if(!device->config[i + port]){
            device->ports[i] = data & 0x01;
        }
        else{
            //input port, do not write!!
        }
        data = data >> 1;
    }
    return 0;
}

/* DESC ----------------------------------------------------------------------
 |
 | ROUTINE NAME:    MAX7300Configure
 |
 |  DESCRIPTION:    Configure MAX7300 ports as inputs or outputs
 +---------------------------------------------------------------------------*/
void MAX7300Configure(MAX7300* device, uint8_t ports, uint8_t config){
    uint8_t i;
    ASSERT(ports == PORT4 ||
           ports == PORT8 ||
           ports == PORT12 ||
           ports == PORT16 ||
           ports == PORT20 ||
           ports == PORT24 ||
           ports == PORT28);
    for(i = 0; i < 4; i++){
        if((config & 0x03) == 1){
            //data = data | (0x00 << i); //output
            device->config[i + ports] = 0;
        }
        else if((config & 0x03) == 2 || (config & 0x03) == 3){
            //data = data | (0x01 << i); //input
            device->config[i + ports] = 1;
        }
        else{
            continue;
        }
        config = config >> 2;
    }
    //device->config = data << ports;
}

/* DESC ----------------------------------------------------------------------
 |
 | ROUTINE NAME:    MAX7300Reset
 |
 |  DESCRIPTION:    Reset data
 +---------------------------------------------------------------------------*/
uint8_t MAX7300Reset(MAX7300* device){

    return 0;
}
