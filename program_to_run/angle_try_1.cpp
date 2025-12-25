/* meArm-angle_control_pilingup
 * Pins:
 * Arduino    Base   Shoulder  Elbow    Gripper
 *    GND    Brown     Brown   Brown     Brown
 *     5V      Red       Red     Red       Red
 *     11    Yellow
 *     10             Yellow
 *      9                     Yellow
 *      6                               Yellow
 */
// #include "C:\Users\Admin\Documents\PlatformIO\Projects\mearm\lib\meArm-master\meArm.h"
#include <Servo.h>

Servo base, rArm, fArm, claw;  

// 函数声明
void sweepServo(char servoName, int delayTime, int startAngle, int targetAngle);

void setup() 
{ 
  base.attach(11);     // base 舵机连接引脚11 舵机代号'b'
  rArm.attach(10);     // rArm 舵机连接引脚10 舵机代号'r'
  fArm.attach(9);      // fArm 舵机连接引脚9  舵机代号'f'
  claw.attach(6);      // claw 舵机连接引脚6  舵机代号'c'
  Serial.begin(9600);
} 

void loop()
{
    sweepServo('b', 15, 60, 2);
    delay(100);
    sweepServo('f', 15, 90, 70);
    sweepServo('r', 15, 90, 120);
    sweepServo('c', 5, 55, 55);
    sweepServo('f', 15, 70, 8);
    sweepServo('r', 15, 120, 165);
    delay(500);
    sweepServo('c', 10, 55, 125);//夹

    sweepServo('r', 15,165, 120);
    sweepServo('f', 15, 8, 70);
    sweepServo('b', 15, 2, 60);
    sweepServo('r', 15,120, 150);
    sweepServo('f', 15, 70, 37);
    sweepServo('r', 15,150, 181);
    delay(500);
    sweepServo('c', 5, 125, 55);//放

    sweepServo('r', 15,180, 150);
    sweepServo('f', 15, 37, 30);
    sweepServo('r', 15,150, 90);
    sweepServo('f', 15, 30, 90);
    sweepServo('b', 15, 60, 2);
    delay(100);
    sweepServo('f', 15, 90, 70);
    sweepServo('r', 15, 90, 120);
    sweepServo('f', 15, 70, 0);
    sweepServo('r', 15, 120, 178);
    delay(500);
    sweepServo('c', 10, 55, 125);//夹

    sweepServo('r', 15,178, 120);
    sweepServo('f', 15, 0, 70);
    sweepServo('b', 15, 2, 60);
    sweepServo('r', 15,120, 150);
    sweepServo('f', 15, 70, 42);
    sweepServo('r', 15,150, 169);
    delay(500);
    sweepServo('c', 5, 125, 55);//放

    sweepServo('r', 15,169, 150);
    sweepServo('f', 15, 42, 30);
    sweepServo('r', 15,150, 90);
    sweepServo('f', 15, 30, 90);//抽出，准备反叠
    delay(100);

    sweepServo('f', 15, 90, 30);
    sweepServo('r', 15,90, 150);
    sweepServo('f', 15, 30, 42);
    sweepServo('r', 15,150, 176);
    sweepServo('c', 10, 55, 125);//夹

    sweepServo('r', 15,176, 150);
    sweepServo('f', 15, 42, 30);
    sweepServo('r', 15,150, 90);
    sweepServo('f', 15, 30, 90);
    sweepServo('b', 15, 60, 2);
    sweepServo('f', 15, 90, 70);
    sweepServo('r', 15, 90, 120);
    sweepServo('f', 15, 70, 0);
    sweepServo('r', 15, 120, 172);
    delay(500);
    sweepServo('c', 5, 125, 55);//放
    
    sweepServo('r', 15,165, 120);
    sweepServo('f', 15, 8, 70);
    sweepServo('b', 15, 2, 60);
    sweepServo('r', 15,120, 150);
    sweepServo('f', 15, 70, 37);
    sweepServo('r', 15,150, 181);
    delay(500);
    sweepServo('c', 10, 55, 125);//夹

    sweepServo('r', 15,180, 150);
    sweepServo('f', 15, 37, 30);
    sweepServo('r', 15,150, 90);
    sweepServo('f', 15, 30, 90);
    sweepServo('b', 15, 60, 2);
    delay(100);
    sweepServo('f', 15, 90, 70);
    sweepServo('r', 15, 90, 120);
    sweepServo('f', 15, 70, 8);
    sweepServo('r', 15, 120, 165);
    delay(500);
    sweepServo('c', 10, 125, 55);//放

    sweepServo('r', 15,165, 120);
    sweepServo('f', 15, 8, 70);
    sweepServo('b', 15, 2, 60);
  

















//   delay(50000000000); 
}


void sweepServo(char servoName, int delayTime, int startAngle, int targetAngle) 
{
  Servo* currentServo; // 指向当前要控制的舵机对象的指针
  
  // 根据舵机代号选择对应的舵机对象
  switch(servoName) {
    case 'b':
      currentServo = &base;
      break;
    case 'r':
      currentServo = &rArm;
      break;
    case 'f':
      currentServo = &fArm;
      break;
    case 'c':
      currentServo = &claw;
      break;
    default:
      // 如果代号错误，直接返回
      return;
  }
  
  int pos; // 用于存储当前角度
  
  // 从起始角度移动到目标角度
  if(startAngle <= targetAngle) {
    // 角度递增的情况
    for(pos = startAngle; pos <= targetAngle; pos++) {
      currentServo->write(pos); // 写入当前角度
      delay(delayTime);         // 等待指定时间
    }
  } 
  else {
    // 角度递减的情况
    for(pos = startAngle; pos >= targetAngle; pos--) {
      currentServo->write(pos); // 写入当前角度
      delay(delayTime);         // 等待指定时间
    }
  }

}