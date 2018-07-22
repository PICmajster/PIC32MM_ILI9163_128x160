/*
    File Name:        :  main.c

    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
 */

#include "mcu_config_files/mcc.h"
#include "xc.h" /* wykrywa rodzaj procka i includuje odpowiedni plik naglowkowy "pic32mm0256gpm048.h"*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> /*deklaracje uint8_t itp*/
#include "delay.h"
#include "ili9163.h"
#include "bitmap.h"

int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    RESET_OFF; /*Reset hgh*/
    lcdInitialise(LCD_ORIENTATION3);
        
    // When using interrupts, you need to set the Global Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalDisable();
    lcdClearDisplay(BLACK);
    //lcdPutS("PIC32MM", lcdTextX(1), lcdTextY(2), YELLOW, BLACK);
	//lcdFilledRectangle(20, 20, 50, 50, TURKISE);
	//lcdLine(20,50,100,50,LIME);
	//lcdPutCh('A',5,5,LIME,BLACK);
    lcdBitmap(bitmap1,128,30,0,0,BLACK,TURKISE);
    lcdBitmap(bitmap3,128,30,0,31,YELLOW,BLUE);
    lcdBitmap(bitmap2,128,30,0,62,BLACK,LIME);
    lcdBitmap(bitmap4,128,30,0,93,BLACK,PINK);
    lcdBitmap(bitmap5,128,30,0,124,WHITE,BLACK);
    
    
    
    while (1) {

    }
}

