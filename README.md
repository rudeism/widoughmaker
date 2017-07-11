# widoughmaker
Arduino code for building a custom controller for Widowmaker!

For those new to Arduino - there's some components you'll need in order to make this controller work:
  1. An Arduino Leonardo or Micro - this is the main micro-processor that will handle all the logic. Be sure not to get other kinds of Arduino, such as the Uno or Mega - those micro-processors do not handle keyboard/mouse signalling to the PC.
  2. An MPU6050 sensor. This is a two-in-one accelerometer (which measures force) and gyroscope (which measures orientation - this is what you'll use to handle aiming). Here's how to hook it up to the Leonardo (INT cable is optional): http://42bots.com/wp-content/uploads/2014/03/MPU6050-Arduino-Uno-Connections.jpg
  3. A thumbstick module. A quick Google search should give you some good options. Here's how to connect it: https://cdn.shopify.com/s/files/1/1689/3027/files/schematic-joystick1.png?v=1485377625
  4. Several buttons to handle all the different abilities in-game.
  5. A breadboard to handle all the grounding & power.
  
Regarding the libraries you need - clone each of these repos and put the root folders inside the Arduino/libraries folder:
  1. MPU6050 - https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050
  2. Keyboard-master - https://github.com/arduino-libraries/Keyboard
  3. Mouse-master - https://github.com/arduino-libraries/Mouse
  4. I2CDev - https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/I2Cdev
  
  Feel free to message me on Twitter (www.twitter.com/rudeism) or Discord (www.discord.gg/rudeism) if you have any questions! Enjoy!
