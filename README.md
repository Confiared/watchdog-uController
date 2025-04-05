## USB wire
Prepare a wire, by sides:
- USB C (or what ever fit into you ESP32 or other platform)
- Female pin from arduino bus
Your USB wire should be wired in this order: Black, green, white, red

And connected like this:
- Red on +5V
- White on P0-
- Green on P0+
- Black on GND
<img src="/USB-header.png" width="400"/>

Of course the reset pair have to be connected on motherboard reset pins.
<img src="/watchdog.jpg" width="400"/>

And you need the software loaded as service: https://github.com/Confiared/watchdog-USB

## WARNING
NOT WORK WITH ARDUINO, because arduino is reset when the serial port is open, and relay is quickly set to on
