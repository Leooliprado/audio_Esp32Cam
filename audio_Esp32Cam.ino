#include <PCM.h>
#include "audio.h"


void setup() {
  pinMode(11, OUTPUT);
}

void loop() {
  // startPlayback(PCM_ZERO, sizeof(PCM_ZERO));
  // delay(4000);
  startPlayback(sertor, sizeof(sertor));
  delay(4000);
  
}

