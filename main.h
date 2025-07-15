/*
 * main.h
 *
 *  Created on: Jun 27, 2025
 *      Author: CS
 */

#ifndef MAIN_H_
#define MAIN_H_

//define input and output ports

extern void I2C0_Init(void);
extern void I2C1_Init(void);
extern void I2C0SlaveIntHandler(void);
extern void I2C1SlaveIntHandler(void);
extern void updatePorts();


#endif /* MAIN_H_ */
