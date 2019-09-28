#include "Keyboard.h"

#include <IRremote.h>

// Os valores foram lidos e colocados direto no programa
#define RIGHT_BUTTON              16761405
#define LEFT_BUTTON               16720605
#define UP_BUTTON                 16736925
#define DOWN_BUTTON               16754775
#define HASHTAG_BUTTON            16732845
#define ASTERISK_BUTTON           16728765

const int receiverPin = 2;

IRrecv irrecv (receiverPin);
decode_results results;

void setup ()
{
  Serial.begin (9600);

  Keyboard.begin ();
  //Keyboard.end();

  irrecv.enableIRIn (); // Starts the receiver

  delay (1000);
}

void loop ()
{
  if (irrecv.decode (&results))
  {
    Serial.println ("Raw: ");
    Serial.println (results.value);
    if (results.value == RIGHT_BUTTON)
    {
      Keyboard.press (KEY_RIGHT_ARROW);
      Keyboard.releaseAll ();
      delay (50);
    }
    else if (results.value == LEFT_BUTTON)
    {
      Keyboard.press (KEY_LEFT_ARROW);
      Keyboard.releaseAll ();
      delay (50);
    }
    else if (results.value == UP_BUTTON)
    {
      Keyboard.press (KEY_UP_ARROW);
      Keyboard.releaseAll ();
      delay (50);
    }
    else if (results.value == DOWN_BUTTON)
    {
      Keyboard.press (KEY_DOWN_ARROW);
      Keyboard.releaseAll ();
      delay (50);
    }
    else if (results.value == HASHTAG_BUTTON)
    {
      Keyboard.press (KEY_LEFT_GUI);
      Keyboard.releaseAll ();
      delay (500);
      Keyboard.print ("terminal");
      delay (100);
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll ();
      delay (2000);
      Keyboard.print ("vim");
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll ();
      delay (1000);
      Keyboard.print ("i");
      delay (100);
      Keyboard.print ("Hello, iHUB!");
      Keyboard.press(KEY_ESC);
      Keyboard.releaseAll ();
      delay (500);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.print ("+");
      Keyboard.releaseAll ();
      delay (100);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.print ("+");
      Keyboard.releaseAll ();
    }
    else if (results.value == ASTERISK_BUTTON)
    {
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.print ("ZQ");
      Keyboard.releaseAll ();
      //Keyboard.press (KEY_RETURN);
      Keyboard.releaseAll ();
      delay (100);
      Keyboard.print ("exit");
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll ();
    }

    Serial.println ("OK");
    Serial.println ("Readings: ");
    Serial.print ("Hex: ");
    Serial.println (results.value, HEX);
    Serial.print ("Decimal: ");
    Serial.println (results.value, DEC);
    Serial.print ("Binary: ");
    Serial.println (results.value, BIN);
    Serial.println ();
    Serial.println ();
    irrecv.resume (); // Receives the next value
  }
}
