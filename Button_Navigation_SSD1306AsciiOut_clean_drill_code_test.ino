//#include <ButtonCallback.h>

/**************************************************************************
  Sketch: MENU NAVIGATION WITH JUST 4 BUTTONS

  This Sketch displays Menu without any Serial Communication and the
  navigation is performed by 4 buttons attached to D3, D8, D4 and D1.
  Also, attach led on D11 to control brightness from menu.
  Default brightness is 15% (check line 78)

   NOTE: By default, navigation buttons use INTERNAL_PULLUP feature.
         This can be changed by commenting the line 45 in "config.h" file

   Uses SSD1306Ascii Library(https://github.com/greiman/SSD1306Ascii)
   by Bill Grieman

   Created by Tamojit Saha
    Github: https://github.com/TamojitSaha
    Website: https://www.tamojitsaha.info/
***************************************************************************/
#include <Arduino.h>
#include <Button2.h>
#include  <Chrono.h>

#include <SPI.h>
#include <Wire.h>

#include "SSD1306Ascii.h"
#include "SSD1306AsciiSoftSpi.h"

#include <menu.h>
//#include <menuIO/serialIO.h>

#include <menuIO/SSD1306AsciiOut.h>
// #include <menuIO/keyIn.h>
#include <menuIO/chainStream.h>
using namespace Menu;

SSD1306AsciiSoftSpi oled;

#include "config.h"

Button2 btnUp(BTN_UP); // Initialize the up button
Button2 btnDwn(BTN_DWN); 
Button2 btnSel(BTN_SEL); 
Button2 btnEsc(BTN_ESC); 
//serialIn serial(Serial);

/*
Button2 buttonA = Button2(BTN_FLEFT);
Button2 buttonB = Button2(BTN_FRIGHT);
Button2 buttonC = Button2(BTN_RLEFT);
Button2 buttonD = Button2(BTN_RRIGHT);

void click(Button2& btn) {
    if (btn == buttonA) {digitalWrite(17, LOW);
    } else if (btn == buttonB) {digitalWrite(16, LOW);
      
    }
      else if (btn == buttonC) {digitalWrite(15, LOW);
      
      }
      else if (btn == buttonD) {digitalWrite(14, LOW);
    }
}
*/

int ledCtrl = HIGH;  //Default LED State of LED at D11 is LOW
int alwaysFeintCtrl = 1;
int feint_random_number = random(0,2);
int twoButtonCtrl = 0;
int feintCtrl = 1;
int randomCtrl = 1;
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
unsigned long drill_duration = 1000*30;
unsigned long drill_interval = 2500;

unsigned long last_react_time = 2000;

result doAlert(eventMask e, prompt &item);

result showEvent(eventMask e, navNode& nav, prompt& item) {

  return proceed;
}



result action1(eventMask e) {
   oled.clear();
    oled.set2X();
      oled.setFont(fixed_bold10x15);
    oled.setCursor(5, 20);  

     delay(1);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(17, HIGH);
      delay(200);
  digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    digitalWrite(14, LOW);
    digitalWrite(17, LOW);
          delay(200);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(17, HIGH);
      delay(200);
        digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    digitalWrite(14, LOW);
    digitalWrite(17, LOW);
          delay(200);
    oled.println("GET");
        oled.println("READY!");

    delay(1000);
    oled.clear();
        oled.setCursor(50, 40);  

    //oled.setInvertMode(1);
    oled.println("3");
 delay(1000);
    oled.clear();
            oled.setCursor(50, 40);  

        oled.println("2");
 delay(1000);
    oled.clear();
            oled.setCursor(50, 40);  

        oled.println("1");
 delay(1000);
    oled.clear();
            oled.setCursor(30, 30);  

oled.println("GO!");
 delay(1000);
    oled.clear();

/****************************Drill code****************************************/

/*
  buttonA.setClickHandler(click);
  buttonB.setClickHandler(click);
  buttonC.setClickHandler(click);
  buttonD.setClickHandler(click);
buttonA.loop();
buttonB.loop();
buttonC.loop();
buttonD.loop();
*/

  startMillis = millis();  //initial start time
currentMillis = startMillis;  
unsigned long last_set_led_time = startMillis;
unsigned long last_press_time;
unsigned long last_react_time=5000;
unsigned long curr_react_time=0;
int num_presses = 0;
unsigned long sum_react_time=0;

int LED_not_reset_yet = 1;
int randNumber;
 int randNumber_feint;
 
// Set first random led
if (twoButtonCtrl == 1){
 randNumber = random(16,18);
 randNumber_feint = random(16,18);
}
else if (twoButtonCtrl == 0){
 randNumber = random(14,18);
 randNumber_feint = random(14,18);
}

//while (randNumber_feint == randNumber)
//{ randNumber_feint = random(14,18); }

// randNumber_feint = random(14,18);

//digitalWrite(randNumber_feint, HIGH);
//delay(100);
//digitalWrite(randNumber_feint, LOW);
//delay(30);

digitalWrite(randNumber, HIGH);
last_set_led_time = millis();

while ((currentMillis - startMillis) <= drill_duration)
  
  {  

     if ((currentMillis -last_set_led_time)<drill_interval){
        int buttonDState = digitalRead(randNumber-4);

            if (buttonDState == LOW){
              digitalWrite(randNumber, LOW);
              num_presses=num_presses+1; 
              last_press_time = millis();
            curr_react_time = last_press_time - last_set_led_time;
            sum_react_time = sum_react_time+curr_react_time;
    //        if (curr_react_time < last_react_time)
      //      last_react_time = curr_react_time;
            LED_not_reset_yet = 0;
            } else {
              LED_not_reset_yet = 1;
              
              }}

              if ((millis() -last_set_led_time)>drill_interval){
                  digitalWrite(randNumber, LOW);
                }

 currentMillis = millis();




      //  if (( currentMillis -last_react_time > last_react_time)&&LED_not_reset_yet==0){

      if ((currentMillis -last_set_led_time)>drill_interval){ //&& LED_not_reset_yet==0){
      
        if (twoButtonCtrl == 1){
 randNumber = random(16,18);
 randNumber_feint = random(16,18);
}
else if (twoButtonCtrl == 0){
 randNumber = random(14,18);
 randNumber_feint = random(14,18);
}
        
 //       randNumber = random(14,18);
  //       randNumber_feint = random(14,18);
         
//while (randNumber_feint == randNumber)
//{ randNumber_feint = random(14,18); }
//randNumber_feint = random(14,18);

if (alwaysFeintCtrl == 1){
digitalWrite(randNumber_feint, HIGH);
delay(100);
digitalWrite(randNumber_feint, LOW);
if (randNumber_feint == randNumber)
{delay(150);}
         
          digitalWrite(randNumber, HIGH);
} else if (alwaysFeintCtrl == 0)
          {
            if (feint_random_number == 0){
                digitalWrite(randNumber, HIGH);
                feint_random_number = random(0,2);}
            else if (feint_random_number == 1){

digitalWrite(randNumber_feint, HIGH);
delay(100);
digitalWrite(randNumber_feint, LOW);
if (randNumber_feint == randNumber)
{delay(150);}
         
          digitalWrite(randNumber, HIGH);


                      feint_random_number = random(0,2);

            }
            }
            
            
            
            
            

            
          last_set_led_time = millis();
        }
  
    oled.clear();
    oled.setCursor(30, 30);  
    oled.println(float(currentMillis - startMillis)/1000);
    oled.println(float(curr_react_time)/1000);
    currentMillis = millis();  //IMPORTANT to save the start time of the current LED state.
  }











for (int i=0; i<3; i++){
        oled.setCursor(40, 80);
      oled.println(i);
      
    delay(200);
    oled.clear();
}
    delay(1);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(17, HIGH);
      delay(200);
  digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    digitalWrite(14, LOW);
    digitalWrite(17, LOW);
          delay(200);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(17, HIGH);
      delay(200);
        digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    digitalWrite(14, LOW);
    digitalWrite(17, LOW);
          delay(200);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(17, HIGH);
      delay(200);
              digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    digitalWrite(14, LOW);
    digitalWrite(17, LOW);
          delay(200);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(17, HIGH);
      delay(200);
  oled.clear();
            oled.setCursor(2, 15);  

        oled.println("TIME!");
 delay(2000);
 oled.clear();
            oled.setCursor(2, 10);  
    oled.set1X();
        oled.println("AVG TIME:");
            oled.set2X();

                oled.println(float(sum_react_time/num_presses)/1000);
 delay(6000);

    oled.clear();
    oled.set1X();
  oled.setFont(menuFont);


  digitalWrite(16, LOW);
    digitalWrite(15, LOW);
    digitalWrite(14, LOW);
    digitalWrite(17, LOW);
return quit;
}

result action2(eventMask e, navNode& nav, prompt &item) {
  //Serial.print(e);
  //Serial.println(" action2 executed, quiting menu");
  return quit;
}


result ledOn() {
  ledCtrl = HIGH;
  analogWrite(LED_PIN, 255);
  return proceed;
}
result ledOff() {
  ledCtrl = LOW;
  analogWrite(LED_PIN, 0);
  return proceed;
}


result internalLedOn() {
  digitalWrite(17, HIGH);
  return proceed;
}
result internalLedOff() {
  analogWrite(17, LOW);
  return proceed;
}

result feintOn() {
  feintCtrl = 1;
  return proceed;
}
result feintOff() {
  feintCtrl = 0;
  return proceed;
}
result randomOn() {
  randomCtrl = 1;
  return proceed;
}
result randomOff() {
  randomCtrl = 0;
  return proceed;
}
result alwaysFeintOn() {
  alwaysFeintCtrl = 1;
  return proceed;
}
result alwaysFeintOff() {
  alwaysFeintCtrl = 0;
  return proceed;
}
result twoButtonOn() {
  twoButtonCtrl = 1;
  return proceed;
}
result twoButtonOff() {
  twoButtonCtrl = 0;
  return proceed;
}




 unsigned long durationValue = drill_duration/1000;   //Default LED brightness value
result adjustDuration() {
  drill_duration = durationValue*1000;
  //if (ledCtrl == HIGH) {
   // int pwm = int(2.55 * float(brightnessValue));
   // analogWrite(LED_PIN, pwm);
 // }
}

 unsigned long intervalValue = drill_interval;   //Default LED brightness value
result adjustInterval() {
  drill_interval = intervalValue;
}

TOGGLE(ledCtrl, setLed, "Led: ", doNothing, noEvent, noStyle //,doExit,enterEvent,noStyle
       , VALUE("On", HIGH, ledOn, enterEvent)//ledOn function is called
       , VALUE("Off", LOW, ledOff, enterEvent)//ledOff function is called
      );

TOGGLE(feintCtrl, setFeint, "Feint: ", doNothing, noEvent, noStyle //,doExit,enterEvent,noStyle
       , VALUE("On", HIGH, feintOn, enterEvent)//ledOn function is called
       , VALUE("Off", LOW, feintOff, enterEvent)//ledOff function is called
      );


      

TOGGLE(randomCtrl, setRandom, "Random: ", doNothing, noEvent, noStyle //,doExit,enterEvent,noStyle
       , VALUE("On", HIGH, randomOn, enterEvent)//ledOn function is called
       , VALUE("Off", LOW, randomOff, enterEvent)//ledOff function is called
      );

TOGGLE(alwaysFeintCtrl, setAlwaysFeint, "Feint: ", doNothing, noEvent, noStyle //,doExit,enterEvent,noStyle
       , VALUE("Always", HIGH, alwaysFeintOn, enterEvent)//ledOn function is called
       , VALUE("Random", LOW, alwaysFeintOff, enterEvent)//ledOff function is called
      );
TOGGLE(twoButtonCtrl, set2Button, "2 Button: ", doNothing, noEvent, noStyle //,doExit,enterEvent,noStyle
       , VALUE("On", HIGH, twoButtonOn, enterEvent)//ledOn function is called
       , VALUE("Off", LOW, twoButtonOff, enterEvent)//ledOff function is called
      );




int selTest = 0;
SELECT(selTest, selMenu, "Select", doNothing, noEvent, noStyle
       , VALUE("Zero", 0, doNothing, noEvent)
       , VALUE("One", 1, doNothing, noEvent)
       , VALUE("Two", 2, doNothing, noEvent)
      );

int chooseTest = -1;
CHOOSE(chooseTest, chooseMenu, "Choose", doNothing, noEvent, noStyle
       , VALUE("First", 1, doNothing, noEvent)
       , VALUE("Second", 2, doNothing, noEvent)
       , VALUE("Third", 3, doNothing, noEvent)
       , VALUE("Last", -1, doNothing, noEvent)
      );

//customizing a prompt look!
//by extending the prompt class
class altPrompt: public prompt {
  public:
    altPrompt(constMEM promptShadow& p): prompt(p) {}
    Used printTo(navRoot &root, bool sel, menuOut& out, idx_t idx, idx_t len, idx_t) override {
      return out.printRaw(F("special prompt!"), len);
    }
};

MENU(subMenu, "Settings", showEvent, anyEvent, noStyle
  //   , FIELD(brightnessValue, "Drill Duration (s)", "%", 30, 180, 15, 15, adjustBrightness, enterEvent, wrapStyle)
     , SUBMENU(setLed)
     , SUBMENU(setFeint)
     , SUBMENU(setRandom)

  //   , OP("Random On", internalLedOn, enterEvent) // will turn on built-in LED
  //   , OP("Random Off", internalLedOff, enterEvent)// will turn off built-in LED
  //   , OP("Feint On", showEvent, anyEvent)
  //   , OP("Feint Off", showEvent, anyEvent)
     , altOP(altPrompt, "", showEvent, anyEvent)
     , EXIT("<Back")
    );

MENU(mainMenu, "--MAIN MENU--", doNothing, noEvent, wrapStyle
     , OP("Start Drill", action1, enterEvent)  //anyEvent
 //    , OP("View Results", action2, enterEvent)
     /* FIELD Parameters :

        Action Name(function name), Action Heading, Action Heading Unit,
        range_lowest, range_highest, range_increment_step,
        range_decrement_step
     */
     , FIELD(durationValue, "Duration", "s", 0, 120, 5, 5, adjustDuration, enterEvent, wrapStyle)
     , FIELD(intervalValue, "Interval", "ms", 1000, 5000, 100, 100, adjustInterval, enterEvent, wrapStyle)
     , SUBMENU(set2Button)
     , SUBMENU(setAlwaysFeint)
    // , OP("Random On", internalLedOn, enterEvent) // will turn on built-in LED
   //  , SUBMENU(subMenu)
    
  //   , SUBMENU(selMenu)
  //   , SUBMENU(chooseMenu)
  //   , OP("Alert test", doAlert, enterEvent)
   //  , EXIT("<Back")
       , EXIT("SLEEP")
    );



//describing a menu output device without macros
//define at least one panel for menu output
const panel panels[] MEMMODE = {{0, 0, 128 / fontW, 64 / fontH}};
navNode* nodes[sizeof(panels) / sizeof(panel)]; //navNodes to store navigation status
panelsList pList(panels, nodes, 1); //a list of panels and nodes
idx_t tops[MAX_DEPTH] = {0, 0}; //store cursor positions for each level

#ifdef LARGE_FONT
SSD1306AsciiOut outOLED(&oled, tops, pList, 8, 2); //oled output device menu driver

#else
SSD1306AsciiOut outOLED(&oled, tops, pList, 5, 1); //oled output device menu driver
#endif

menuOut* constMEM outputs[]  MEMMODE  = {&outOLED}; //list of output devices
outputsList out(outputs, 1); //outputs list

chainStream<0> in(NULL);

NAVROOT(nav, mainMenu, MAX_DEPTH, in, out);

void button_init()
{
      btnUp.setTapHandler([](Button2 & b) {
       // Up
       nav.doNav(downCmd); // It's called downCmd because it decreases the index of an array. Visually that would mean the selector goes upwards.
    });

    btnDwn.setTapHandler([](Button2 & b) {
        // Down
        nav.doNav(upCmd); // It's called upCmd because it increases the index of an array. Visually that would mean the selector goes downwards.
    });

     btnSel.setTapHandler([](Button2 & b) {
        // Sel
        nav.doNav(enterCmd); // It's called upCmd because it increases the index of an array. Visually that would mean the selector goes downwards.
    });

     btnEsc.setTapHandler([](Button2 & b) {
        // Esc
        nav.doNav(escCmd); // It's called upCmd because it increases the index of an array. Visually that would mean the selector goes downwards.
    });
}

void button_loop()
{
    // Check for button presses
    btnUp.loop();
    btnDwn.loop();
    btnSel.loop();
    btnEsc.loop();
}


result alert(menuOut& o, idleEvent e) {
  if (e == idling) {
    o.setCursor(0, 0);
    o.print("alert test");
    o.setCursor(0, 1);
    o.print("press [select]");
    o.setCursor(0, 2);
    o.print("to continue...");
  }
  return proceed;
}

result doAlert(eventMask e, prompt &item) {
  nav.idleOn(alert);
  return proceed;
}

//when menu is suspended
result idle(menuOut &o, idleEvent e) {
  o.clear();
  switch (e) {
    case idleStart: o.println("suspending menu!"); break;
    case idling: { o.clear(); break;}  //o.println("Press any button "); o.println("to continue ... "); break;}
    case idleEnd: o.println("resuming menu."); break;
  }
  return proceed;
}

void setup() {
    button_init();

 // joystickBtns.begin();
 // pinMode(LED_PIN, OUTPUT);
  pinMode(17, OUTPUT);
    pinMode(16, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);

  Wire.begin();
  oled.begin(&Adafruit128x64, CS_PIN, DC_PIN, CLK_PIN, MOSI_PIN, RST_PIN); //check config
  oled.setFont(menuFont);
  //  oled.setScrollMode(SCROLL_MODE_AUTO);

    oled.displayRemap(true);
  oled.clear();

  nav.idleTask = idle; //point a function to be used when menu is suspended

  
}

void loop() {
  button_loop();

  nav.poll();
//  delay(1);//simulate a delay when other tasks are done
}
