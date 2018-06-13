#include <SoftwareSerial.h> // Biblioteca SoftwareSerial

//Definicao pinos dos sensores sensor
int microfone1 = A0;
int microfone2 = A1;
int microfone3 = A2;
int microfone4 = A3;
int microfone5 = A4;
int microfone6 = A5;

SoftwareSerial comunicacaoESP(8, 9); // objeto para comunicação serial com o ESP8266 nas Portas 8(RX) e 9(TX)
// Define que o modulo ira utilizar a serial comunicacaoESP
//ESP8266 wifi(comunicacaoESP);
//Define as Variávei que ´ra receber os valores dos microfones
int valor_micro1 = 0;
int valor_micro2 = 0;
int valor_micro3 = 0;
int valor_micro4 = 0;
int valor_micro5 = 0;
int valor_micro6 = 0;

void setup()
{
  Serial.begin(115200);
  comunicacaoESP.begin(115200);
  //Define pinos dos sensores como entrada.
  pinMode(microfone1, INPUT);
  pinMode(microfone2, INPUT);
  pinMode(microfone3, INPUT);
  pinMode(microfone4, INPUT);
  pinMode(microfone5, INPUT);
  pinMode(microfone6, INPUT);
}

void loop()
{
  //As variaveis recebem os valores passados pelas portas analógicas.
  valor_micro1 = analogRead(microfone1);
  valor_micro2 = analogRead(microfone2);
  valor_micro3 = analogRead(microfone3);
  valor_micro4 = analogRead(microfone4);
  valor_micro5 = analogRead(microfone5);
  valor_micro6 = analogRead(microfone6);
  String valores = "";
  valores += valor_micro1;
  valores += "|";
  valores += valor_micro2;
  valores += "|";
  valores += valor_micro3;
  valores += "|";
  valores += valor_micro4;
  valores += "|";
  valores += valor_micro5;
  valores += "|";
  valores += valor_micro6;
  Serial.println(valores);
  comunicacaoESP.println(valores);
  delay(50);
}
