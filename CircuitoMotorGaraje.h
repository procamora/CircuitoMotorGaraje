#ifndef CircuitoMotorGaraje_h
#define CircuitoMotorGaraje_h

#define RELAY_OPEN_DOOR 7
#define RELAY_CLOSE_DOOR 8

#define IS_CLOSE_DOOR 11
#define IS_OPEN_DOOR 12

#define TIME_MAX 30 //Tiempo maximo de rele activo

#define CLICK_BUTTON 2

#define LED_OK 3

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 2000;   // the debounce time, increase if the output flickers

#endif
