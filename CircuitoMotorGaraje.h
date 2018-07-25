#ifndef CircuitoMotorGaraje_h
#define CircuitoMotorGaraje_h

#define IS_CLOSE_DOOR 11
#define RELAY_OPEN_DOOR 7

#define IS_OPEN_DOOR 12
#define RELAY_CLOSE_DOOR 8

#define TIME_MAX 30 //Tiempo maximo de rele activo

#define CLICK_BUTTON 2

#define LED_OK 3

#define ANALOG_PIN A0

// Multiplicamos 50 por el porcentaje del potenciometro, va desde 0ms a 50000ms
#define TIME_ACTIVE 500

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
#define debounce 2000   // the debounce time, increase if the output flickers

long potentiometerValue = 0; //valor que leemos del potenciometro, es un porcentaje 0-100

#endif
