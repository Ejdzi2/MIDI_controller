# MIDI_foot_controller
This is the subjective project for creating the MIDI_foot_controller using an Arduino micropro board and https://github.com/tttapa/MIDI_controller library - a great library for creating a MIDI controllers using an Arduino boards.  
This library has been obsoleted by its successor, the [**Control Surface**](https://github.com/tttapa/Control-Surface) library but for this particular project (foot controler) it was enough.

The MIDI_controller library was sligthtly modified to suit my needs. Particulary MIDI_OUTPUTS src (Digital.cpp and DigitalCC.cpp).

# Installation
Installing the MIDI_controller library

To install this library, download the latest version as a .ZIP file. Then open the Arduino IDE, go to Sketch > Include Library > Add .ZIP library, and open the .ZIP file you just downloaded.
Dependencies

The MIDI_controller library depends on the PJRC Encoder library for using rotary encoders and jog wheels. Download the .ZIP library from GitHub and install it.

If you are using an Arduino with native USB support, like the Leonardo, Due, Zero, Micro ... you'll need to install the MIDIUSB library. Install it using the Arduino IDE's library manager (Sketch > Include Library > Manage Libraries). Search for 'MIDIUSB', and install it. Alternatively, download the .ZIP library from GitHub and install it.

If you're using a Teensy board, you have to install the Arduino core for Teensy (aka Teensyduino). Download it here, if you haven't already.

# Uploading
Arduino boards with native USB support

Open controller_foot.ino, connect your Arduino, select the right port from the Tools menu, and hit upload.
