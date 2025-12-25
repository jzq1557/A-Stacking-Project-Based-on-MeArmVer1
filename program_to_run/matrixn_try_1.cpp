/* meArm IK test - York Hackspace May 2014
 * Test applying Nick Moriarty's Inverse Kinematics solver
 * to Phenoptix' meArm robot arm, to walk a specified path.
 *
 * Pins:
 * Arduino    Base   Shoulder  Elbow    Gripper
 *    GND    Brown     Brown   Brown     Brown
 *     5V      Red       Red     Red       Red
 *     11    Yellow
 *     10             Yellow
 *      9                     Yellow
 *      6                               Yellow
 */
#include "C:\Users\Admin\Documents\PlatformIO\Projects\mearm\lib\meArm-master\meArm.h"
#include <Servo.h>

int basePin = 11;
int shoulderPin = 10;
int elbowPin = 9;
int gripperPin = 6;

meArm arm;

void setup() {
  arm.begin(basePin, shoulderPin, elbowPin, gripperPin);
}

void loop() {
  //Clap - so it's obvious we're at this part of the routine
  arm.openGripper();
  delay(1000);
  arm.closeGripper();
  delay(1000);
  arm.openGripper();
  delay(1000);

  arm.goDirectlyTo(150, 0, 100);
  delay(1000);
  arm.goDirectlyTo(130, 5, -30);
  delay(500);
  arm.goDirectlyTo(110, 5, -50);
  delay(500);
  arm.goDirectlyTo(85, 5, -65);
  delay(1000);
  arm.closeGripper();

  delay(1000);
  arm.goDirectlyTo(150, 5,-50);
  delay(500);
  arm.goDirectlyTo(150, 5,0);
  delay(500);
  arm.goDirectlyTo(150, 5, 100);
  delay(1000);
  arm.goDirectlyTo(130, 100, 100);
  delay(500);
  arm.goDirectlyTo(110, 175, 50);
  delay(1000);
  arm.goDirectlyTo(110, 170, -20);
  delay(1000);
  arm.goDirectlyTo(150, 170,-50);
  delay(500);
  arm.goDirectlyTo(120, 173,-60);
  delay(1000);
  arm.openGripper();
  
  delay(1000);
  arm.goDirectlyTo(120, 160,0);
  delay(500);
  // arm.openGripper();
  // delay(1000);
  // arm.goDirectlyTo(100, 100, 100);
  // delay(1000);
  delay(500000);
  // arm.closeGripper();
  // arm.openGripper();
  // arm.closeGripper();
  // arm.openGripper();
  // delay(500);
  // //Go up and left to grab something
  // arm.gotoPoint(-80,100,140); 
  // arm.closeGripper();
  // //Go down, forward and right to drop it
  // arm.gotoPoint(70,200,10);
  // arm.openGripper();
  // //Back to start position
  // arm.gotoPoint(0,100,50);
  return(0);
}
