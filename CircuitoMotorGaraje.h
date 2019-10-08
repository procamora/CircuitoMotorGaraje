#ifndef CircuitoMotorGaraje_h
#define CircuitoMotorGaraje_h


#include <avr/wdt.h> // Incluir la librería que contiene el watchdog 

#define IS_CLOSE_DOOR 12
#define RELAY_OPEN_DOOR 8

#define IS_OPEN_DOOR 11
#define RELAY_CLOSE_DOOR 9

#define TIME_MAX 30 //Tiempo maximo de rele activo

#define CLICK_BUTTON 2

#define LED_OK 10

#define ANALOG_PIN A1

// Multiplicamos 50 por el porcentaje del potenciometro, va desde 0ms a 50000ms
#define TIME_ACTIVE 500

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long times = 0;         // the last time the output pin was toggled
#define debounce 2000   // the debounce time, increase if the output flickers

long potentiometerValue = 0; //valor que leemos del potenciometro, es un porcentaje 0-100

bool opening = false; // para saber si estamos abriendo la puerta, usado en la funcion invert

#endif
