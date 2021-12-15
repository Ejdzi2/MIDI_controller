#include "Digital.h"
#include "MIDI_Controller.h"

using namespace ExtIO;

Digital::Digital(pin_t pin, uint8_t note, uint8_t channel, uint8_t velocity) // Constructor
{
  ExtIO::pinMode(pin, INPUT_PULLUP); // Enable the internal pull-up resistor on the pin with the button/switch
  this->pin = pin;
  this->note = note;
  this->channel = channel;
  this->velocity = velocity;
}
int nnn;
int chch;
Digital::~Digital() // Destructor
{
  ExtIO::pinMode(pin, INPUT); // make it a normal input again, without the internal pullup resistor.
}

void Digital::invert() // Invert the button state (send Note On event when released, Note Off when pressed)
{
  invertState = true;
}

void Digital::refresh() // Check if the button state changed, and send a MIDI Note On or Off accordingly
{
  bool state = ExtIO::digitalRead(pin) ^ invertState; // read the button state and invert it if "invert" is true
 ExtIO::pinMode(20, INPUT_PULLUP);
 int ss = digitalRead(20); 
 
  ExtIO::pinMode(2, INPUT_PULLUP); //przełącznik kanału 
    int ch = digitalRead(2);
  //    if (ch == LOW) 
  //  channel = 6;
// else channel = 5;
 // Przycisk all off
  ExtIO::pinMode(21, INPUT_PULLUP);
int alloff = digitalRead(21);

//przyciski program change
 ExtIO::pinMode(3, INPUT_PULLUP);
 ExtIO::pinMode(4, INPUT_PULLUP);
 ExtIO::pinMode(5, INPUT_PULLUP);
 ExtIO::pinMode(6, INPUT_PULLUP);
 ExtIO::pinMode(7, INPUT_PULLUP);
 ExtIO::pinMode(8, INPUT_PULLUP);
 ExtIO::pinMode(9, INPUT_PULLUP);
 ExtIO::pinMode(10, INPUT_PULLUP);
 ExtIO::pinMode(16, INPUT_PULLUP);
 ExtIO::pinMode(14, INPUT_PULLUP);
 ExtIO::pinMode(15, INPUT_PULLUP);
 ExtIO::pinMode(18, INPUT_PULLUP);
 ExtIO::pinMode(19, INPUT_PULLUP);
int PC1 = digitalRead(3);
int PC2 = digitalRead(4);
//zamienione piny !! 5 i 6
int PC4 = digitalRead(5); 
int PC3 = digitalRead(6);
int PC5 = digitalRead(7);
int PC6i = digitalRead(8);
int PC7i = digitalRead(9);
int PC8 = digitalRead(10);
int PC9 = digitalRead(16);
int PC10 = digitalRead(14);
int PC11 = digitalRead(15);
int PC12 = digitalRead(18);
int PC13 = digitalRead(19);
  
  if (millis() - prevBounceTime > debounceTime)
  {
    int8_t stateChange = state - buttonState;

    if (stateChange == falling)
    { // Button is pushed
      buttonState = state;
      
 ExtIO::pinMode(20, INPUT_PULLUP);
 int ss = digitalRead(20); 
 
  ExtIO::pinMode(2, INPUT_PULLUP); //przełącznik kanału (5 lub 6)
    int ch = digitalRead(2);
  //    if (ch == LOW) 
  //  channel = 6;
// else channel = 5;
   //

 // Przycisk all off
  ExtIO::pinMode(21, INPUT_PULLUP);
int alloff = digitalRead(21);

//przyciski program change
 ExtIO::pinMode(3, INPUT_PULLUP);
 ExtIO::pinMode(4, INPUT_PULLUP);
 ExtIO::pinMode(5, INPUT_PULLUP);
 ExtIO::pinMode(6, INPUT_PULLUP);
 ExtIO::pinMode(7, INPUT_PULLUP);
 ExtIO::pinMode(8, INPUT_PULLUP);
 ExtIO::pinMode(9, INPUT_PULLUP);
 ExtIO::pinMode(10, INPUT_PULLUP);
 ExtIO::pinMode(16, INPUT_PULLUP);
 ExtIO::pinMode(14, INPUT_PULLUP);
 ExtIO::pinMode(15, INPUT_PULLUP);
 ExtIO::pinMode(18, INPUT_PULLUP);
 ExtIO::pinMode(19, INPUT_PULLUP);
int PC1 = digitalRead(3);
int PC2 = digitalRead(4);
//zamienione piny !! 5 i 6
int PC4 = digitalRead(5); 
int PC3 = digitalRead(6);
int PC5 = digitalRead(7);
int PC6i = digitalRead(8);
int PC7i = digitalRead(9);
int PC8 = digitalRead(10);
int PC9 = digitalRead(16);
int PC10 = digitalRead(14);
int PC11 = digitalRead(15);
int PC12 = digitalRead(18);
int PC13 = digitalRead(19);

    if (stateChange == rising)
    { // Button is released
 buttonState = state;
	  
	  if (ss == HIGH) //przełącznik ustawiony na "normalnie" on - off
	  
      MIDI_Controller.MIDI()->send(NOTE_OFF, channel + channelOffset * channelsPerBank, note + addressOffset * channelsPerBank, velocity);
    }
  }
  if (state != prevState)
  {
    prevBounceTime = millis();
    prevState = state;
  }
}
