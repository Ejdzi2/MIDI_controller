#include <MIDI_Controller.h>

/*
This is practical using of the "Digital" class of the MIDI_controller library.
Conected push buttons to digital pins  and the ground of arduino pro micro. 

This buttons will play MIDI notes when pressed.

Written originally by tttapa, 08/09/2017 modified by Ejdzi2
*/

#include <MIDI_Controller.h> // Include the library

uint8_t channel = 5; //initial midi channel
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

// Create a new instance of the class 'Digital', called 'button', on pins 3-10 & 16-19, that sends MIDI messages with notes on channel (initialy 5), with velocity 127
// and on pins 2,21 that sends notes off on channel (initialy 5) - velocity 0

 
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
  {21, 127, channel, 0},  //all notes off and program change button (defined in Digital.cpp) - works when pushed simultanously with notes buttons
  {2, 127, channel, 0},   //notes off and channel change button (defined in Digital.cpp) - works when pushed simultanously with notes buttons
};

//DigitalCC off(2, MIDI_CC::All_Notes_Off, channel); // pin 2,  mozna ustawic jako all notes off - wyłączony

// A bank that shifts each button one octave (12 semitones)
Bank octave(12); 
// A bank selector with a momentary push button on pin 0 and an LED on pin 11-no light (original), 1-light (up transposed)
BankSelector bs(octave, {0}, {11, 1, 1, 1, 1});
 void setup() {  // Add the note buttons to the bank, changing the address (note number) - zmiana oktaw
  octave.add(buttons, Bank::CHANGE_ADDRESS);
  }

void loop() {
  // Refresh the button (check whether the button's state has changed since last time, if so, send it over MIDI)
  MIDI_Controller.refresh();
}
