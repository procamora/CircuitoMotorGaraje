
/**
  @file CircuitoMotorGaraje.ino
  @brief Controlador del motor de la puerta del garaje
  @author Pablo Rocamora pablojoserocamora@gmail.com
  @date 11/06/2018
*/

#include "CircuitoMotorGaraje.h"

#define MODO_DEBUG true

void setup() {
  if (MODO_DEBUG) {
    Serial.begin(115200);
    Serial.println();
    Serial.println("Inicio");
  }

  pinMode(RELAY_OPEN_DOOR, OUTPUT);
  pinMode(RELAY_CLOSE_DOOR, OUTPUT);
  pinMode(IS_OPEN_DOOR, INPUT);
  pinMode(IS_CLOSE_DOOR, INPUT);
  pinMode(CLICK_BUTTON, INPUT);
}

/**
   Metodo para comprobar si hemos pulsado el boton, retorna true si se ha pulsado y false en caso contrario
   Guarda el estado en el que esta.
*/
bool isClickButton() {
  bool clicked = false;
  int reading = digitalRead(CLICK_BUTTON);
  if (reading == HIGH && millis() - time > debounce) {
    time = millis();
    clicked = true;
  }

  return clicked;
  Serial.println(String(clicked));
}

/**
   Metodo para obtener el pin al que hay que aplicar voltaje para accionar el rele
*/
int getPinRelay() {
  int in = digitalRead(IS_CLOSE_DOOR);
  if (in == HIGH) {
    if (MODO_DEBUG)
      Serial.println("ABRIR");

    return RELAY_OPEN_DOOR;  //9
  }
  if (MODO_DEBUG)
    Serial.println("CERRAR");

  return RELAY_CLOSE_DOOR; //10
}

bool finCarrera(int relay) {
  int pin;
  if (relay == RELAY_OPEN_DOOR)
    pin = IS_OPEN_DOOR;
  else
    pin = IS_CLOSE_DOOR;

  int in = digitalRead(pin);

  if (MODO_DEBUG) {
    Serial.println(String(RELAY_OPEN_DOOR) + ": " + String(digitalRead(RELAY_OPEN_DOOR)));
    Serial.println(String(RELAY_CLOSE_DOOR) + ": " + String(digitalRead(RELAY_CLOSE_DOOR)));
    Serial.println(String(IS_CLOSE_DOOR) + ": " + String(digitalRead(IS_CLOSE_DOOR)));
    Serial.println(String(IS_OPEN_DOOR) + ": " + String(digitalRead(IS_OPEN_DOOR)));
    Serial.println(String(in == HIGH));
    Serial.println();
  }
  if (in == HIGH)
    return true;
  return false;
}


void pause(int pin) {
  digitalWrite(pin, LOW);
}

void play() {
  long inicio = millis();
  long fin = inicio + 10000; //tiempo maximo funcionando

  int relay =  getPinRelay();
  digitalWrite(relay, HIGH);
  Serial.println( "pin: " + String(relay));

  while (!finCarrera(relay)/* || millis() < fin*/) {
    Serial.println("play");

    if (isClickButton())
      pause(relay);
    delay(1000);
  }
  Serial.println("Termina play");
  digitalWrite(relay, LOW);
}

void loop() {
  if (isClickButton()) {
    play();
  }
  delay(100);
}
