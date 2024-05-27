// INCLUSÃO DE BIBLIOTECAS
#include "DFRobotDFPlayerMini.h"

// DEFINIÇÕES DE PINOS
#define pinBot1 14 // Pino GPIO14
#define pinBot2 13 // Pino GPIO13
#define pinBot3 12 // Pino GPIO12
#define pinBot4 2  // Pino GPIO2

// DEFINIÇÕES
#define volumeMP3 30

#define DEBUG

// INSTANCIANDO OBJETOS
DFRobotDFPlayerMini playerMP3;

// DECLARAÇÃO DE FUNÇÕES	

void setup() {
  Serial.begin(9600);
  delay(500); // Espera um pouco para a porta serial se estabilizar
  Serial.println();
  Serial.println(F("Iniciando DFPlayer ... (Espere 3~5 segundos)"));

  pinMode(pinBot1,INPUT_PULLUP);
  pinMode(pinBot2,INPUT_PULLUP);
  pinMode(pinBot3,INPUT_PULLUP);
  pinMode(pinBot4,INPUT_PULLUP);

  if (!playerMP3.begin(Serial)) {  // Inicia a comunicação com o módulo DFPlayer Mini
    Serial.println(F("Falha ao iniciar o DFPlayer Mini!"));
    Serial.println(F("1. Confira as conexões!"));
    Serial.println(F("2. Confira o cartão SD!"));
    while(true){
      delay(0);
    }
  }

  Serial.println(F("DFPlayer Mini ligado!"));

  playerMP3.volume(volumeMP3);

#ifdef DEBUG
  Serial.println("Fim Setup");
#endif	
  playerMP3.playFolder(2, 3); // Inicia a reprodução de uma música ao iniciar o dispositivo
}

void loop() {
  if (digitalRead(pinBot1) == LOW) {
    playerMP3.playFolder(1, 1);
    Serial.println("Tocando pasta 01, musica 001");
    delay(1000);
  }
  if (digitalRead(pinBot2) == LOW) {
    playerMP3.playFolder(1, 2);
    Serial.println("Tocando pasta 01, musica 002");
    delay(1000);
  }
  if (digitalRead(pinBot3) == LOW) {
    playerMP3.playFolder(1, 3);
    Serial.println("Tocando pasta 01, musica 003");
    delay(1000);
  }
}
