#include <MIDI_Controller.h>

/*
This is an example of the "Digital" class of the MIDI_controller library.
Connect a push buttons to digital pin 2. Connect the other pin of the button to the ground, 
a pull-up resistor is not necessary, because the internal one will be used. 
This button will play MIDI note C4 when pressed.
Map it in your DAW or DJ software.

Written by tttapa, 08/09/2017
https://github.com/tttapa/MIDI_controller
*/

#include <MIDI_Controller.h> // Include the library

uint8_t channel = 5;
const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)
const uint8_t c = 24;
const uint8_t cis = 25;
const uint8_t d = 26;
const uint8_t dis = 27;
const uint8_t e = 28; 
const uint8_t f = 29; 
const uint8_t fis = 30; 
const uint8_t g = 31; 
const uint8_t gis = 32;
const uint8_t a = 33; 
const uint8_t ais = 34; 
const uint8_t h = 35; 
const uint8_t c1 = 36;    // Note number 48 is defined as  C2 in the MIDI specification

// Create a new instance of the class 'Digital', called 'button', on pin 2, that sends MIDI messages with note 'C4' (60) on channel 1, with velocity 127

 
Digital buttons[] = {
  {3, c, channel, velocity},
  {4, cis, channel, velocity},
  {5, dis, channel, velocity}, //zamienione piny !!
  {6, d, channel, velocity}, //zamienione piny !!
  {7, e, channel, velocity},
  {8, f, channel, velocity},
  {9, fis, channel, velocity},
  {10, g, channel, velocity},
  {16, gis, channel, velocity},
  {14, a, channel, velocity},
  {15, ais, channel, velocity},
  {18, h, channel, velocity},
  {19, c1, channel, velocity},
  {21, 127, channel, 0},  //notes off 
  {2, 127, channel, 0},   //notes off
};

//DigitalCC off(2, MIDI_CC::All_Notes_Off, channel); // pin 2,  mozna ustawic jako all notes off - wyłączony

// A bank that shifts each button one octave (i.e. twelve semitones)
Bank octave(12); 

// A bank selector with a momentary push button on pin 0 and an LED on pin 11-nie swieci, 1-swieci
BankSelector bs(octave, {0}, {11, 1, 1, 1, 1});
 

void setup() {  // Add the note buttons to the bank, changing the address (i.e. note number) - zmiana oktaw
  octave.add(buttons, Bank::CHANGE_ADDRESS);
  }

void loop() {
  // Refresh the button (check whether the button's state has changed since last time, if so, send it over MIDI)
  MIDI_Controller.refresh();
}
