
/**
  @file CircuitoMotorGaraje.ino
  @brief Controlador del motor de la puerta del garaje
  @author Pablo Rocamora pablojoserocamora@gmail.com
  @date 11/06/2018
*/

#include "CircuitoMotorGaraje.h"

#define MODO_DEBUG true



/**
   Metodo para comprobar si hemos pulsado el boton, retorna true si se ha pulsado y false en caso contrario
   Guarda el estado en el que esta. Para detectarlo comprueba si llega voltaje al pin, con un voltaje >=3 and <= 5
*/
bool isClickButton() {
  bool clicked = false;
  int reading = digitalRead(CLICK_BUTTON);
  if (reading == HIGH && millis() - times > debounce) {
    times = millis();
    clicked = true;
  }


  ///////////////////////////////////////
  // FIXME IMPORTANTE, ESTE IF NO SE HA CHEKEADO, PROBARLO CUANDO TENGA ACCESO AL HARDWARE
  //////////////////////////////////////
  // solo esperamos si nota una pulsacion de boton
  // Puede que haya que aumentarlo un poco, probar con el mando los tiempos de espera
  if (clicked)
    delay(1000);
  //Serial.println(String(clicked));
  //despues de 1 seg volvemos a comprobar si esta pulsado, esto es para intentar evitar falsos positivos alargando el tiempo de pulsacion
  return clicked && digitalRead(CLICK_BUTTON) == HIGH;
}

/**
   Metodo para obtener el pin al que hay que aplicar voltaje para accionar el rele
*/
int getPinRelay() {
  int in = digitalRead(IS_CLOSE_DOOR);
  if (in == LOW) {
    if (MODO_DEBUG)
      Serial.println("ABRIR");

    opening = true;
    return RELAY_OPEN_DOOR;  //8
  }

  if (MODO_DEBUG)
    Serial.println("CERRAR");

  opening = false;
  return RELAY_CLOSE_DOOR; //9
}

/**
   Metodo que retorna true cuando el pin del sensor se pone a 0V indicando que llega al final del recorrido
*/
bool finCarrera(int pinRelay) {
  int pin;
  if (pinRelay == RELAY_OPEN_DOOR)
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

  if (in == LOW)
    return true;
  return false;
}

/**
   Metodo para cortar el voltaje del pin que esta activando un relay, se ejecuta cuando estando
   en modo play volvemos a pulsar el boton, retorna el pin al que aplicamos voltaje
*/
/*
  int invert(int pinRelay) {
  if (MODO_DEBUG)
    Serial.println("pauso pin: " + pinRelay);

  // Si la puerta esta abriendose apagamos el rele y activamos el de cerrar
  if (opening) {
    digitalWrite(RELAY_OPEN_DOOR, LOW); //Primero apagamos para no tener los 2 cables con tension
    delay(300);
    digitalWrite(RELAY_CLOSE_DOOR, HIGH);
    opening = false;
    return RELAY_CLOSE_DOOR;
  }
  else {
    digitalWrite(RELAY_CLOSE_DOOR, LOW);
    delay(300);
    digitalWrite(RELAY_OPEN_DOOR, HIGH);
    opening = true;
    return RELAY_OPEN_DOOR;  //8

  }
  }
*/

/**
   Metodo
*/
void play() {
  unsigned long inicio = millis();
  unsigned long fin = inicio + (potentiometerValue * TIME_ACTIVE); // tiempo maximo funcionando

  int relay =  getPinRelay();
  digitalWrite(relay, HIGH);

  if (MODO_DEBUG)
    Serial.println( "inicio pin: " + String(relay));

  delay(1000);  // esperamos 1 segudo antes de la primera comprobacion para evitar falsos positivos

  while (!finCarrera(relay) && (unsigned long) millis() <= fin) {
    if (MODO_DEBUG) {
      Serial.println("play");
      Serial.println(String(millis()) + " <= " + String(fin));
    }
    //if (isClickButton())
    //  relay = invert(relay);

    delay(80);
  }
  if (MODO_DEBUG)
    Serial.println("Termina pin: " + relay);
  digitalWrite(relay, LOW);
}

/**
   Metodo que comprueba si se ha superado el valor maximo de las variables que almacenan el valor de millis(),
   cuando se supera para a ser un numero negativo. Lo comprueba con 100 seg de adelanto para evitar fallos durante
   el proceso de abrir o cerrar la puerta
*/
bool isReboot() {
  long millisOverflow = millis() + 100000;
  if (millisOverflow < 0) {
    if (MODO_DEBUG)
      Serial.println("reinicio");
    return true;
  }
  return false;
}



void setup() {
  if (MODO_DEBUG) {
    Serial.begin(9600);
    Serial.println("Inicio");
  }

  pinMode(RELAY_OPEN_DOOR, OUTPUT);
  pinMode(RELAY_CLOSE_DOOR, OUTPUT);
  pinMode(IS_OPEN_DOOR, INPUT);
  pinMode(IS_CLOSE_DOOR, INPUT);
  pinMode(CLICK_BUTTON, INPUT);
  pinMode(LED_OK, OUTPUT);
  pinMode(ANALOG_PIN, INPUT);

  digitalWrite(LED_OK, HIGH);

  long value = analogRead(ANALOG_PIN);          // realizar la lectura analógica raw
  times = 0;         //  lo inicializamos aqui porque el reset de millis es necesario que tambien lo reinizialice
  Serial.println(times);

  potentiometerValue = map(value, 0, 1023, 0, 100);  // convertir a porcentaje
  if (MODO_DEBUG)
    Serial.println("Tiempo maximo activo del relay: " + String(potentiometerValue * TIME_ACTIVE) + "ms");

}

void loop() {
  // si millis genera un overflow reset de millis
  if (isReboot()) {
    RESTART;
    //setup(); //ya lo hace restart
  }
  Serial.println(millis());

  if (isClickButton()) {
    // delay(4000);
    //if (digitalRead(CLICK_BUTTON)) {
    play();
    // }
  }
  delay(10);
}
