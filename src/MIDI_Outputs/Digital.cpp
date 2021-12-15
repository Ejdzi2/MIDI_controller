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
int nnn;  //the last note without noteoff (temporary variable) when sustain switch is on
int chch; //channel change variable
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
 
//sustain (without NoteOff) / normal (with NoteOff) switch
ExtIO::pinMode(20, INPUT_PULLUP);
 int ss = digitalRead(20); 
 
//channel change button  
ExtIO::pinMode(2, INPUT_PULLUP); 
    int ch = digitalRead(2);

 // all notes off and program change button
  ExtIO::pinMode(21, INPUT_PULLUP);
int alloff = digitalRead(21);

// defining program change pins (notes buttons)
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
      
//PROGRAM CHANGE changing - alloff button along with choosed note button (without transposition)
if ((alloff == LOW) && ((PC1 == LOW) || (PC2 == LOW) || (PC3 == LOW) || (PC4 == LOW) || (PC5 == LOW) || (PC6i == LOW) || (PC7i == LOW) || (PC8 == LOW) || (PC9 == LOW) || (PC10 == LOW) || (PC11 == LOW) || (PC12 == LOW) || (PC13 == LOW)))
	{ if (PC1 == LOW)
MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 1, velocity);
if (PC2 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 2, velocity);
if (PC3 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 3, velocity);
if (PC4 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 4, velocity);
if (PC5 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 5, velocity);
if (PC6i == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 6, velocity);
if (PC7i == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 7, velocity);
if (PC8 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 8, velocity);
if (PC9 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 9, velocity);
if (PC10 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 10, velocity);
if (PC11 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 11, velocity);
if (PC12 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 12, velocity);
if (PC13 == LOW)
 MIDI_Controller.MIDI()->send(PROGRAM_CHANGE, channel + channelOffset * channelsPerBank + chch, 13, velocity);
	}
	
			
//channel changing - channel button along with choosed note button (without transposition)
	    
else	if ((ch == LOW) && ((PC1 == LOW) || (PC2 == LOW) || (PC3 == LOW) || (PC4 == LOW) || (PC5 == LOW) || (PC6i == LOW) || (PC7i == LOW) || (PC8 == LOW) || (PC9 == LOW) || (PC10 == LOW) || (PC11 == LOW) || (PC12 == LOW) || (PC13 == LOW)))
	{ if (PC1 == LOW)
chch = -4;
	if (PC2 == LOW)
chch = -3;	
if (PC3 == LOW)
chch = -2;
if (PC4 == LOW)
chch = -1;
 if (PC5 == LOW)
chch = 0;
if (PC6i == LOW)
	chch = 1;
if (PC7i == LOW)
	chch = 2;
if (PC8 == LOW)
	chch = 3;
if (PC9 == LOW)
	chch = 4;
if (PC10 == LOW)
	chch = 5;
if (PC11 == LOW)
	chch = 6;
if (PC12 == LOW)
	chch = 7;
if (PC13 == LOW)
	chch = 8;
	}
	
	
else
	
	
	{ if (ss == LOW) //sustain switch on "sustain" 
	 MIDI_Controller.MIDI()->send(NOTE_OFF, channel + channelOffset * channelsPerBank + chch, nnn, velocity); //note off for last note played
	  MIDI_Controller.MIDI()->send(NOTE_ON, channel + channelOffset * channelsPerBank + chch, note + addressOffset * channelsPerBank, velocity);
    
	 //last note played without noteoff
	 nnn = note + addressOffset * channelsPerBank;  
	}  
	
	}


	    
    if (stateChange == rising)
    { // Button is released
 buttonState = state;
	  
	  if (ss == HIGH) // sustain switch on "normal" - noteoff
	  
      MIDI_Controller.MIDI()->send(NOTE_OFF, channel + channelOffset * channelsPerBank, note + addressOffset * channelsPerBank, velocity); //noteoff for last played note
    }
  }
  if (state != prevState)
  {
    prevBounceTime = millis();
    prevState = state;
  }
}
