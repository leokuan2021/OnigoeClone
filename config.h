/*config.h*/

/* List of Supported Fonts
 *
  Arial14,
  Arial_bold_14,
  Callibri11,
  Callibri11_bold,
  Callibri11_italic,
  Callibri15,
  Corsiva_12,
  fixed_bold10x15,
  font5x7,    //Do not use in LARGE_FONT, can use as default font
  font8x8,
  Iain5x7,    //Do not use in LARGE_FONT, can use as default font
  lcd5x7,     //Do not use in LARGE_FONT, can use as default font
  Stang5x7,   //Do not use in LARGE_FONT, can use as default font
  System5x7,  //Do not use in LARGE_FONT, can use as default font
  TimesNewRoman16,
  TimesNewRoman16_bold,
  TimesNewRoman16_italic,
  utf8font10x16,
  Verdana12,
  Verdana12_bold,
  Verdana12_italic,
  X11fixed7x14,
  X11fixed7x14B,
  ZevvPeep8x16
 *  
 */

/* #define OLED_I2C_ADDRESS 0x3C     //Defined OLED I2C Address
 *  
 */
// pin definitions
#define CS_PIN    6
#define RST_PIN   8
#define DC_PIN    7
#define MOSI_PIN 4
#define CLK_PIN  5

/*
 * Define your font from the list. 
 * Default font: lcd5x7
 * Comment out the following for using the default font.
 */
#define LARGE_FONT Arial14

//Navigate buttons
#define BTN_SEL     12                 // Select button
#define BTN_UP      13                 // Up Button
#define BTN_DWN     11                 // Down Button
#define BTN_ESC     10                 // Exit Button

#define BTN_FLEFT     13                 // Select button
#define BTN_FRIGHT      12                 // Up Button
#define BTN_RLEFT     11                 // Down Button
#define BTN_RRIGHT     10                 // Exit Button


// Comment the following to disable internal pullup for Navigate buttons
// #define NAV_BUTTONS_INPUT_PULLUP

#define TOTAL_NAV_BUTTONS 4       // Total Navigation Button used

/*Demonstrate PWM with LED on D11*/
#define LED_PIN 17                //Defined LED Pin to D11

#define MAX_DEPTH 2

#ifdef LOC
// #define LARGE_FONT
#define INV
#endif
 
 /*Do not change the values(recomended)*/
#ifdef LARGE_FONT
#define menuFont LARGE_FONT
#define fontW 8
#define fontH 16
#else
// #define menuFont System5x7
#define menuFont lcd5x7
#define fontW 5
#define fontH 8
#endif