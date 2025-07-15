/*
 * MAX7300.h
 *
 *  Created on: Jun 20, 2025
 *      Author: CS
 */

#ifndef MAX7300_H_
#define MAX7300_H_

typedef struct{
    uint8_t address;
    bool ports[32];
    bool config[32]; //input = 1, output = 0
    uint8_t package;
    bool commandReceived;
}MAX7300;

//specific device type
#define AAI 0
#define ATI 1
#define AAX 2
#define ATL 3

//port defines
#define PORT4 0x04
#define PORT5 0x05
#define PORT6 0x06
#define PORT7 0x07
#define PORT8 0x08
#define PORT9 0x09
#define PORT10 0x0A
#define PORT11 0x0B
#define PORT12 0x0C
#define PORT13 0x0D
#define PORT14 0x0E
#define PORT15 0x0F
#define PORT16 0x10
#define PORT17 0x11
#define PORT18 0x12
#define PORT19 0x13
#define PORT20 0x14
#define PORT21 0x15
#define PORT22 0x16
#define PORT23 0x17
#define PORT24 0x18
#define PORT25 0x19
#define PORT26 0x1A
#define PORT27 0x1B
#define PORT28 0x1C
#define PORT29 0x1D
#define PORT30 0x1E
#define PORT31 0x1F

#define READ 1
#define WRITE 0


extern uint8_t MAX7300ProcessCommand(MAX7300* device, uint8_t command, uint8_t data, bool rw);
extern void MAX7300Init(MAX7300* device, uint8_t address, uint8_t package);
extern uint8_t MAX7300Read(MAX7300* device, uint8_t port);
extern uint8_t MAX7300WriteOutput(MAX7300* device, uint8_t port, uint8_t data, uint8_t length);
extern void MAX7300Configure(MAX7300* device, uint8_t ports, uint8_t config);
extern uint8_t MAX7300Reset(MAX7300* device);
#endif /* MAX7300_H_ */
