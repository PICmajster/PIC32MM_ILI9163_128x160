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
    
	//lcdFillRect(20, 20, 50, 50, RED);
	//lcdLine(20,50,100,50,LIME);
	//lcdPutCh('A',5,5,LIME,BLACK,2);
    //lcdBitmap(bitmap1,128,30,0,0,BLACK,LIME);
    //lcdBitmap(bitmap3,128,30,0,31,YELLOW,RED);
    //lcdBitmap(bitmap2,128,30,0,62,LIGHT_GOLDENROD_YELLOW,BLUE);
    //lcdBitmap(bitmap4,128,30,0,93,RED,PINK);
    //lcdBitmap(bitmap5,128,30,0,124,WHITE,BLACK);
    //lcdPutS("ILI9163", 0, 50, ORANGE, BLACK, 3);
    //lcdCircle(50,50,30,ORANGE);
    //lcdFastHLine(10, 10, 50, LIME);
    //lcdFastVLine(10, 10, 50, LIME);
    while (1) {

    }
}

