# ==**基于MeArm、arduinoUNO和9g舵机实现的简单来回码垛程序**==
**本项目大概率不会再次更新，球球点击右上角“Star”给个星★😂** ~~[一个牢机械本科生勇闯git的爆糖历程](https://github.com/jzq1557)~~
***
## **一、材料准备**
1. 学校提供的陈年2.6mm木板，激光切割加工处理，CAD图纸直接拿的MeArmV1开源的DWG文件(详见[MeArmV1开源地址](https://github.com/MeArm/MeArm/tree/master/v1))然后删掉了所有水印和标志，真真乃是当代中国青年尽显实用主义之风的典范之举；
2. arduinoUNO官方板子，百分百意大利原厂(~~有钱给一千来口子学生买原厂198的电子垃圾也不愿意去买9.9国内高仿省下来钱补贴食堂，哈基济你这家伙~~)；
3. 义乌9块9面包板；
4. 烂大街的9g90s舵机；
5. 老化发硬的七彩杜邦线；
6. UBS-B数据线（自费）；
## **二、机械结构与电控**
具体组装、接线教程详见[MeArmV1开源地址](https://github.com/MeArm/MeArm/tree/master/v1)
不用再买面包板供电，直接从UNO的引脚上飞杜邦线就行：）；
## **三、程序设计**
1. 以下提到的所有程序我已放在"program_to_run"文件夹内；
2. 得益于MeArm完善的社区，我找到了一个基于MeArm统一传动方式的一个机械臂正逆解库（lib\meArm-master）；
3. 基于该库可以实现机械臂末端执行器（claw）的坐标to坐标的直线路径规划
4. 但是该库对于舵机零点的初始化精度要求较高，而统一配发的舵机精度太差，且我国网络上并无对于该库的任何校准过程日志，遂仅做尝试，详见（program_to_run\matrixn_try_1.cpp）
5. 故而转向对于单纯角度控制的开发工作（~~就是几把调参罢了~~），详见（program_to_run\angle_try_1.cpp）
   1. 基于基本的servo库，我自建了一个模块化函数
        ```
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
        ```
        具体编程逻辑和相关注释程序中已经十分简明，若有疑问请读者自学Cpp，有更多有趣的想法可以在issue里cue我或者发邮箱  
### **祝clone愉快，右上角“Star”给个星★😂**