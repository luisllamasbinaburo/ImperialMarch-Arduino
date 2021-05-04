#include <./imperialMarch.hpp>

const int STEPPER1_STEP = 0;
const int STEPPER1_DIR = 1;

ImperialMarch imperialMarch;

void playNote(int note, int duration)
{
   auto start_time = millis();
   auto step_time = 1000000 / note;

   while (millis() - start_time < duration)
   {
      digitalWrite(STEPPER1_STEP, HIGH);
      delayMicroseconds(100);
      digitalWrite(STEPPER1_STEP, LOW);
      delayMicroseconds(step_time - 100);
   }
}

void setup()
{
   pinMode(STEPPER1_DIR, OUTPUT);
   pinMode(STEPPER1_STEP, OUTPUT);

   digitalWrite(STEPPER1_DIR, HIGH);
   digitalWrite(STEPPER1_STEP, LOW);

   imperialMarch.playNoteCallback = playNote;
}

void loop()
{
   imperialMarch.playSong();

   delay(500);
}