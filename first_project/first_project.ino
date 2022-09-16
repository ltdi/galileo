/*********************************
* 
*
* Permite probar el ponchitoCIII 
* https://github.com/ciiiutnfrc/ponchitoCIII
*
**********************************/

int pulsRojo = 8;
int pulsVerde = 4;
int pulsAmarillo = 7;
int ledRojo = 9;
int ledVerde = 5;
int ledAmarillo = 6;


int valorPulsador1 = 1;
int valorPulsador2 = 1;
int valorPulsador3 = 1;


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int uno = 1;
int cero = 0;

void setup() {
  // Activamos los pines de entrada y salida
  pinMode(pulsRojo, INPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(pulsAmarillo, INPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(pulsVerde, INPUT);
  pinMode(ledVerde, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);




  // Leemos el valor del pin
  valorPulsador1 = digitalRead(pulsRojo);
  valorPulsador2 = digitalRead(pulsAmarillo);
  valorPulsador3 = digitalRead(pulsVerde);

  // Encendemos o apagamos el pin del LED según convenga


  if (valorPulsador1 == LOW) {
    digitalWrite(ledRojo, HIGH);
    Serial.print("Rojo = ");
    Serial.print(uno);
  }
  else {
    digitalWrite(ledRojo, LOW);
    Serial.print("Rojo = ");
    Serial.print(cero);
  }

  if (valorPulsador2 == LOW) {
    digitalWrite(ledAmarillo, HIGH);
    Serial.print("Amarillo = ");
    Serial.print(uno);
  }
  else {
    digitalWrite(ledAmarillo, LOW);
    Serial.print("Amarillo = ");
    Serial.print(cero);
  }

  if (valorPulsador3 == LOW) {
    digitalWrite(ledVerde, HIGH);
    Serial.print("Verde = ");
    Serial.print(uno);
  }
  else {
    digitalWrite(ledVerde, LOW);
    Serial.print("Verde = ");
    Serial.print(cero);
        
  }
  Serial.println("");
  delay(100);
}
