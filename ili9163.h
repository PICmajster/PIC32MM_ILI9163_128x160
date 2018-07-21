#ifndef ILI9163_H_
#define ILI9163_H_


#define RESET_ON 	PORTCbits.RC4 = 0; 
#define RESET_OFF 	PORTCbits.RC4 = 1; 	
#define SCE_ON		PORTCbits.RC5 = 0; 
#define SCE_OFF		PORTCbits.RC5 = 1; 
#define DC_ON		PORTCbits.RC3 = 0;
#define DC_OFF		PORTCbits.RC3 = 1; 

#define DisplayCLK   PORTBbits.RB8
#define DisplaySDI   PORTBbits.RB3 
extern const unsigned char bitmap[];

// Screen orientation defines:
// 0 = Ribbon at top
// 1 = Ribbon at left
// 2 = Ribbon at right
// 3 = Ribbon at bottom
/*
     Signal
   
     CS   (Chip Select)     --> RC5
     RESET                  --> RC4
     A0   (Command / Data)  --> RC3
     SDA  (Serial Data)     --> RB3
     SCK  (Serial Clock)    --> RB8
     
*/
#define LCD_ORIENTATION0	96
#define LCD_ORIENTATION1	160
#define LCD_ORIENTATION2	192
#define LCD_ORIENTATION3	0
/*
 #define LCD_ORIENTATION0	0
#define LCD_ORIENTATION1	96
#define LCD_ORIENTATION2	160
#define LCD_ORIENTATION3	192
 */
 
/*
 * Colour definition
 * for more colours * Colour Table
* http://www.rapidtables.com/web/color/RGB_Color.htm
* 
*/
#define RED decodeRgbValue(255, 0,0)
#define BLUE decodeRgbValue(0, 0, 255)
#define LIME decodeRgbValue(0, 255, 0)
#define YELLOW decodeRgbValue(255, 255,0)
#define PINK decodeRgbValue(255, 0, 255)
#define TURKISE decodeRgbValue(0, 255,255)
#define BLACK decodeRgbValue(0, 0,0)
#define WHITE decodeRgbValue(255, 255,255)

// Command defines only useful for this display controller chip
#define NOP 					0x00
#define SOFT_RESET 				0x01
#define GET_RED_CHANNEL 		0x06
#define GET_GREEN_CHANNEL 		0x07
#define GET_BLUE_CHANNEL 		0x08
#define GET_PIXEL_FORMAT 		0x0C
#define GET_POWER_MODE 			0x0A
#define GET_ADDRESS_MODE 		0x0B
#define GET_DISPLAY_MODE 		0x0D
#define GET_SIGNAL_MODE 		0x0E
#define GET_DIAGNOSTIC_RESULT 	0x0F
#define ENTER_SLEEP_MODE 		0x10
#define EXIT_SLEEP_MODE 		0x11
#define ENTER_PARTIAL_MODE 		0x12
#define ENTER_NORMAL_MODE 		0x13
#define EXIT_INVERT_MODE 		0x20
#define ENTER_INVERT_MODE 		0x21
#define SET_GAMMA_CURVE 		0x26
#define SET_DISPLAY_OFF			0x28
#define SET_DISPLAY_ON 			0x29
#define SET_COLUMN_ADDRESS 		0x2A
#define SET_PAGE_ADDRESS 		0x2B
#define WRITE_MEMORY_START 		0x2C
#define WRITE_LUT 				0x2D
#define READ_MEMORY_START 		0x2E
#define SET_PARTIAL_AREA 		0x30
#define SET_SCROLL_AREA 		0x33
#define SET_TEAR_OFF 			0x34
#define SET_TEAR_ON 			0x35
#define SET_ADDRESS_MODE 		0x36
#define SET_SCROLL_START 		0X37
#define EXIT_IDLE_MODE 			0x38
#define ENTER_IDLE_MODE 		0x39
#define SET_PIXEL_FORMAT 		0x3A
#define WRITE_MEMORY_CONTINUE 	0x3C
#define READ_MEMORY_CONTINUE 	0x3E
#define SET_TEAR_SCANLINE 		0x44
#define GET_SCANLINE 			0x45
#define READ_ID1				0xDA
#define READ_ID2				0xDB
#define READ_ID3				0xDC
#define FRAME_RATE_CONTROL1		0xB1
#define FRAME_RATE_CONTROL2		0xB2
#define FRAME_RATE_CONTROL3		0xB3
#define DISPLAY_INVERSION		0xB4
#define SOURCE_DRIVER_DIRECTION	0xB7
#define GATE_DRIVER_DIRECTION	0xB8
#define POWER_CONTROL1			0xC0
#define POWER_CONTROL2			0xC1
#define POWER_CONTROL3			0xC2
#define POWER_CONTROL4			0xC3
#define POWER_CONTROL5			0xC4
#define VCOM_CONTROL1			0xC5
#define VCOM_CONTROL2			0xC6
#define VCOM_OFFSET_CONTROL		0xC7
#define WRITE_ID4_VALUE			0xD3
#define NV_MEMORY_FUNCTION1		0xD7
#define NV_MEMORY_FUNCTION2		0xDE
#define POSITIVE_GAMMA_CORRECT	0xE0
#define NEGATIVE_GAMMA_CORRECT	0xE1
#define GAM_R_SEL               0xF2

// Macros and in-lines:

// Translates a 3 byte RGB value into a 2 byte value for the LCD (values should be 0-31)
inline uint16_t decodeRgbValue(uint8_t r, uint8_t g, uint8_t b)
{
	return (b << 11) | (g << 6) | (r);
}	

// This routine takes a row number from 0 to 20 and
// returns the x coordinate on the screen (0-127) to make
// it easy to place text
inline uint8_t lcdTextX(uint8_t x) { return x*6; }

// This routine takes a column number from 0 to 20 and
// returns the y coordinate on the screen (0-127) to make
// it easy to place text
inline uint8_t lcdTextY(uint8_t y) { return y*8; }

//	LCD function prototypes
void lcdReset(void);
void lcdWriteCommand(uint8_t address);
void lcdWriteParameter(uint8_t parameter);
void lcdWriteData(uint8_t dataByte1, uint8_t dataByte2);
void lcdInitialise(uint8_t orientation);

void lcdClearDisplay(uint16_t colour);
void lcdPlot(uint8_t x, uint8_t y, uint16_t colour);
void lcdLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t colour);
void lcdRectangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t colour);
void lcdFilledRectangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t colour);
void lcdCircle(int16_t xCentre, int16_t yCentre, int16_t radius, uint16_t colour);

void lcdPutCh(unsigned char character, uint8_t x, uint8_t y, uint16_t fgColour, uint16_t bgColour);
void lcdPutS(const char *string, uint8_t x, uint8_t y, uint16_t fgColour, uint16_t bgColour);

void lcdBitmap(const unsigned char *data, uint8_t width, uint8_t heigth, uint8_t x, uint8_t y, uint16_t fgColour, uint16_t bgColour);

void writeSD(uint8_t byteOut);
void lcdWriteCommand_bis(uint8_t cmdOut);
void lcdWriteParameter_bis(uint8_t data);
void lcdWriteData_bis(uint8_t dataByte1, uint8_t dataByte2);

#endif /* ILI9163LCD_H_ */