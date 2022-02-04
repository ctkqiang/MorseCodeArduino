#include "pitches.h"

const String APP_NAME = "Morse Code ";
const long BAUDRATE = 0x2580;
const int LED7 = 0x7;
const int LED13 = 0xD;
const int TONE = NOTE_C8;
const int PUSH_BUTTON = 0x2;
const int PIEZO = 0x8;
const int PIEZO_FREQ = 0x3E8;
const int PIEZO_DELAY = 0x10;

int BUTTON_STATE = 0x0;

void setup()
{
  /* Initiate Serial */
  Serial.begin(BAUDRATE);

  /* Display Message */
  log(APP_NAME + "Initiated");

  /* LED declaration */
  pinMode(LED7, OUTPUT);
  pinMode(LED13, OUTPUT);

  /* Initiate Push Button */
  pinMode(PUSH_BUTTON, INPUT_PULLUP);
}

void LEDToggle(int LED, bool isOn)
{
  if (isOn) digitalWrite(LED, HIGH);

  digitalWrite(LED, LOW);
}

void beep()
{
  BUTTON_STATE = digitalRead(PUSH_BUTTON);

  if (BUTTON_STATE == LOW)
  {
    log(">>>>");
    playTone(getTempo());
  }
}

void loop()
{
  beep();
}

void log(String message)
{
  Serial.print(message + "\n");
}

long getTempo()
{
  return TONE * 0x9 / 2;
}

void playTone(int duration)
{
  tone(PIEZO, PIEZO_FREQ, PIEZO_DELAY);
  delayMicroseconds(TONE);
}
