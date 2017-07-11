/* Code to control the mouse pointer
 * through the movement of the head
 * Change values at vx and vy (+300 and -100 in my case)
 * using the TEST code to make your project work.
 * 
 * Gabry295
 */

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>
#include <Keyboard.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;

int stickXPin = A0;
int stickYPin = A1;

int stickClickPin = 4;
int adsPin = 5;
int hookPin = 6;
int wallhackPin = 7;
int shootPin = 11;

int stickX = 0;
int stickY = 0;

int stickClick = 0;
int ads = 0;
int hook = 0;
int wallhack = 0;
int shoot = 0;

int wPressed = 0;
int aPressed = 0;
int sPressed = 0;
int dPressed = 0;
int mouseLPressed = 0;
int mouseRPressed = 0;
int fPressed = 0;
int qPressed = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1){  
    }
  }

  pinMode(stickXPin, INPUT);
  pinMode(stickYPin, INPUT);

    pinMode(stickClickPin, INPUT_PULLUP);
    pinMode(adsPin, INPUT_PULLUP);
    pinMode(hookPin, INPUT_PULLUP);
    pinMode(wallhackPin, INPUT_PULLUP);
    pinMode(shootPin, INPUT_PULLUP);
}

void loop() {
  
  stickX = analogRead(stickXPin) - 513;
  stickY = analogRead(stickYPin) - 507;

  stickClick = digitalRead(stickClickPin);
 
    ads = digitalRead(adsPin);
    hook = digitalRead(hookPin);
    wallhack = digitalRead(wallhackPin);
    shoot = digitalRead(shootPin);
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = (gx+300)/200+2;  // "+300" because the x axis of gyroscope give values about -350 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
  vy = (gy-100)/200; // same here about "-100"

  if (stickClick == 1){
    Mouse.move(vx, vy);
  }

  if (stickX < -300){
    if (sPressed == 0){
      sPressed = 1;
      Keyboard.press('s');
    }
  }
  else
  {
    if (sPressed == 1){
      sPressed = 0;
      Keyboard.release('s');
    }
  }

  if (stickX > 300){
    if (wPressed == 0){
      wPressed = 1;
      Keyboard.press('w');
    }
  }
  else
  {
    if (wPressed == 1){
      wPressed = 0;
      Keyboard.release('w');
    }
  }

  if (stickY < -300){
    if (aPressed == 0){
      aPressed = 1;
      Keyboard.press('a');
    }
  }
  else
  {
    if (aPressed == 1){
      aPressed = 0;
      Keyboard.release('a');
    }
  }

  if (stickY > 300){
    if (dPressed == 0){
      dPressed = 1;
      Keyboard.press('d');
    }
  }
  else
  {
    if (dPressed == 1){
      dPressed = 0;
      Keyboard.release('d');
    }

  if (ads == 1){
    if (mouseRPressed == 0){
      mouseRPressed = 1;
      Mouse.press(MOUSE_RIGHT);
    }
  }
  else if (ads == 0){
    if (mouseRPressed == 1){
      mouseRPressed = 0;
      Mouse.release(MOUSE_RIGHT);
    }
  }

  if (shoot == 1){
    if (mouseLPressed == 0){
      mouseLPressed = 1;
      Mouse.press(MOUSE_LEFT);
    }
  }
  else if (shoot == 0){
    if (mouseLPressed == 1){
      mouseLPressed = 0;
      Mouse.release(MOUSE_LEFT);
    }
  }

  if (hook == 1){
    if (fPressed == 0){
      fPressed = 1;
      Keyboard.press('f');
    }
  }
  else if (hook == 0){
    if (fPressed == 1){
      fPressed = 0;
      Keyboard.release('f');
    }
  }

  if (wallhack == 1){
    if (qPressed == 0){
      qPressed = 1;
      Keyboard.press('q');
    }
  }
  else if (wallhack == 0){
    if (qPressed == 1){
      qPressed = 0;
      Keyboard.release('q');
    }
  }
  }
  
  delay(20);
}
