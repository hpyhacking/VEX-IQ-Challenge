#pragma config(Sensor, port4,  TouchLED1,      sensorVexIQ_LED)
#pragma config(Sensor, port10, Gyro,           sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor2,          leftkouqiuMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor3,          leftarmMotor,  tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightMotor,    tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor8,          rightkouqiuMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor9,          rightarmMotor, tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// 1   Kouqiu_fangqiu(nDegree,nSpeed,nGoTime);
// 2   Kouqiu_zhuangqiu(nDegree,nSpeed,nGoTime);
// 3   UpDown_RightArm(nDegree,nSpeed,nGoTime);
// 4   Go_Forward_Distance(nDistance, nSpeed,nMaxTime);
// 5   Go_Forward_Time(nSpeed,nGoTime,nFactor);
// 6   Gyro_Rotation(nDegree,nSpeed,nMaxTime);

//	1nAct,2nSpeed,3nDegree,4nDistance,5nGoTime,6nMaxTime,7nFactor;

/*
int Act[30][7]={
	{1,20,60,0,600,0,0},     // 1   UpDown_Gou(nSpeed,nDegree,nGoTime);
	{1,20,0,0,600,0,0},      // 1   UpDown_Gou(nSpeed,nDegree,nGoTime);
	{2,20,70,0,500,0,0},     // 2   UpDown_Claw(nSpeed,nDegree,nGoTime);
	{2,20,0,0,500,0,0},      // 2   UpDown_Claw(nSpeed,nDegree,nGoTime);
	{3,20,80,0,500,0,0},     // 3   UpDown_Arm(nSpeed,nDegree,nGoTime);
	{3,20,0,0,500,0,0},      // 3   UpDown_Arm(nSpeed,nDegree,nGoTime);
	{4,20,0,360,0,5000,0},   // 4   Go_Forward_Distance(nSpeed,nDistance, nMaxTime);
	{4,-20,0,360,0,5000,0},  // 4   Go_Forward_Distance(nSpeed,nDistance, nMaxTime);
	{5,20,0,100,300,0,95},   // 5   Go_Forward_Time(nSpeed,nGoTime,nFactor);
	{5,-20,0,100,300,0,110}, // 5   Go_Forward_Time(nSpeed,nGoTime,nFactor);
	{6,20,30,0,0,5000,0},	   // 6   Gyro_Rotation(nDegree,nSpeed,nMaxTime);
	{6,-20,20,0,0,5000,0},   //	6   Gyro_Rotation(nDegree,nSpeed,nMaxTime);
};
*/
//	1nAct,2nSpeed,3nDegree,4nDistance,5nGoTime,6nMaxTime,nFactor;
int Act[75][7]={

	{5,20,0,0,750,0,100},    // 1   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{6,-20,24,0,0,5000,0},    // 2   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,-20,0,0,600,0,100},    // 3   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{6,20,8,0,0,5000,0},    // 4   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,50,0,0,1000,0,100},    // 5   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{3,100,170,0,1200,0,0},      // 6   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{6,20,10,0,0,5000,0},    // 7   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,20,0,0,1260,0,100},    // 8   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{3,30,100,0,1800,0,0},      // 9   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{5,-50,0,0,1000,0,100},    // 10   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{3,30,0,0,800,0,0},      // 11   UpDown_Arm(nSpeed,nDegree,nGoTime);5
//***********right-green-20OK**************************************************************



//********40-ok***************************************************************************************
	{5,20,0,0,760,0,100},    // 1   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{6,-20,24,0,0,5000,0},    // 2   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,-20,0,0,600,0,100},    // 3   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{6,20,9,0,0,5000,0},    // 4   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,50,0,0,1000,0,100},    // 5   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{3,100,170,0,1200,0,0},      // 6   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{6,20,13,0,0,5000,0},    // 7   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,20,0,0,1400,0,100},    // 8   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{3,30,100,0,1800,0,0},      // 9   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{5,-50,0,0,1000,0,100},    // 10   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{3,30,0,0,800,0,0},      // 11   UpDown_Arm(nSpeed,nDegree,nGoTime);5
//***********left-green-40OK**************************************************************


//*******************************************************************************
	{3,100,195,0,1000,0,0},      // 1   UpDown_Arm(nSpeed,nDegree,nGoTime);5

	{5,50,0,0,1050,0,100},    // 2   Go_Forward_Time(nSpeed,nGoTime,nFactor);4
	{6,20,70,0,0,5000,0},    // 3   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,50,0,0,1000,0,100},    // 4   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{1,100,900,0,2200,0,0},     // 5   Kouqiu_zhuangqiu(nSpeed,nDegree,nGoTime);
	{5,-50,0,0,500,0,100},    // 6   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{6,-20,57,0,0,5000,0},    // 7  Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du

	{3,100,0,0,800,0,0},      // 8   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{5,20,0,0,800,0,100},    // 9   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{3,100,120,0,1000,0,0},  // 10   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{5,-50,0,0,800,0,100},    // 11   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{6,-20,95,0,0,5000,0},    // 12   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,100,0,0,1500,0,100},    // 13   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword


	{6,-20,5,0,0,5000,0},    // 14   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,50,0,0,800,0,100},    // 15   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{6,-20,0,0,0,5000,0},    // 16   Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du

	//{5,50,0,0,500,0,100},    // 17   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{3,30,0,0,1200,0,0},      // 18   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{5,-50,0,0,300,0,100},    // 19   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{3,100,195,0,1000,0,0},      // 20   UpDown_Arm(nSpeed,nDegree,nGoTime);5
	{6,20,1,0,0,5000,0},    // 21  Gyro_Rotation(nDegree,nSpeed,nMaxTime);3//20du
	{5,20,0,0,1000,0,100},    // 22   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{2,100,400,0,1000,0,0},     // 23   Kouqiu_zhuangqiu(nSpeed,nDegree,nGoTime);
	{5,50,0,0,1800,0,100},    // 24   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword
	{5,-100,0,0,500,0,100},    // 25   Go_Forward_Time(nSpeed,nGoTime,nFactor);	6  backword

//*****56-ok*************************************************************************

};

//	nAct,nSpeed,nDegree,nDistance,nGoTime,nMaxTime,nFactor;
void Init_Car();


void Kouqiu_zhuangqiu(int nSpeed,int nDegree,int nDelayTime);

void Kouqiu_fangqiu(int nSpeed,int nDegree,int nDelayTime);

void UpDown_Arm(int nSpeed,int nDegree,int nDelayTime);

void Gyro_Rotation(int nSpeed,int nDegree,int nMaxTime);

void Go_Forward_Distance(int nSpeed,int nDistance,int nMaxTime);

void Go_Forward_Time(int nSpeed, int nDelay,int nFactor);


//main *****************************************************************
task main()
{
	int i;
	 int nAct;    //
   int nSpeed;
	 int nDegree;
	 int nDistance;
	 int nGoTime;
	 int nMaxTime;
	 int nFactor;
	 Init_Car();

//	 UpDown_Arm(100,400,1500);

setTouchLEDColor(TouchLED1, colorRed);     // set touch LED color as Red
waitUntil((getTouchLEDValue(TouchLED1)==1)); // wait touch
setTouchLEDColor(TouchLED1, colorGreen);   // when touch LED, its color change to Green

//	 for(i=0;i<11;i++)
for(i=0;i<11;i++)
	 {
	     nAct=Act[i][0];
       nSpeed=Act[i][1];
	     nDegree=Act[i][2];
	     nDistance=Act[i][3];
	     nGoTime=Act[i][4];
	     nMaxTime=Act[i][5];
	     nFactor=Act[i][6];



	     //while(i==25);//******************************************


	     switch(nAct)
	     {
	         case 1:
	             Kouqiu_zhuangqiu(nSpeed,nDegree,nGoTime);
	         break;
	         case 2:
	             Kouqiu_fangqiu(nSpeed,nDegree,nGoTime);
	         break;
	         case 3:
	             UpDown_Arm(nSpeed,nDegree,nGoTime);
	         break;
	         case 4:
	             Go_Forward_Distance(nSpeed,nDistance, nMaxTime);
	         break;
	         case 5:
	             Go_Forward_Time(nSpeed,nGoTime,nFactor);
	         break;
	         case 6:
	              Gyro_Rotation(nSpeed,nDegree,nMaxTime);
	         break;

	         }
	  delay(50);

	  }

		setTouchLEDColor(TouchLED1, colorRed);     // set touch LED color as Red
		waitUntil((getTouchLEDValue(TouchLED1)==1)); // wait touch
		setTouchLEDColor(TouchLED1, colorGreen);   // when touch LED, its color change to Green

	 for(i=11;i<22;i++)
	 {
	     nAct=Act[i][0];    //
       nSpeed=Act[i][1];
	     nDegree=Act[i][2];
	     nDistance=Act[i][3];
	     nGoTime=Act[i][4];
	     nMaxTime=Act[i][5];
	     nFactor=Act[i][6];



	    // while(i==20);//******************************************


	     switch(nAct)
	     {
	         case 1:
	             Kouqiu_zhuangqiu(nSpeed,nDegree,nGoTime);
	         break;
	         case 2:
	             Kouqiu_fangqiu(nSpeed,nDegree,nGoTime);
	         break;
	         case 3:
	             UpDown_Arm(nSpeed,nDegree,nGoTime);
	         break;
	         case 4:
	             Go_Forward_Distance(nSpeed,nDistance, nMaxTime);
	         break;
	         case 5:
	             Go_Forward_Time(nSpeed,nGoTime,nFactor);
	         break;
	         case 6:
	              Gyro_Rotation(nSpeed,nDegree,nMaxTime);
	         break;
	     }
	  delay(50);

	  }

setTouchLEDColor(TouchLED1, colorRed);     // set touch LED color as Red
waitUntil((getTouchLEDValue(TouchLED1)==1)); // wait touch
setTouchLEDColor(TouchLED1, colorGreen);   // when touch LED, its color change to Green

	 for(i=22;i<47;i++)
	 {
	     nAct=Act[i][0];    //
       nSpeed=Act[i][1];
	     nDegree=Act[i][2];
	     nDistance=Act[i][3];
	     nGoTime=Act[i][4];
	     nMaxTime=Act[i][5];
	     nFactor=Act[i][6];



	     //while(i==43);//******************************************


	     switch(nAct)
	     {
	         case 1:
	             Kouqiu_zhuangqiu(nSpeed,nDegree,nGoTime);
	         break;
	         case 2:
	             Kouqiu_fangqiu(nSpeed,nDegree,nGoTime);
	         break;
	         case 3:
	             UpDown_Arm(nSpeed,nDegree,nGoTime);
	         break;
	         case 4:
	             Go_Forward_Distance(nSpeed,nDistance, nMaxTime);
	         break;
	         case 5:
	             Go_Forward_Time(nSpeed,nGoTime,nFactor);
	         break;
	         case 6:
	              Gyro_Rotation(nSpeed,nDegree,nMaxTime);
	         break;
	     }
	  delay(50);

	  }



}
void Init_Car()
{
//	setMotorEncoderUnits(encoderDegrees);
	resetMotorEncoder(rightarmMotor);
	resetMotorEncoder(leftkouqiuMotor);
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(leftarmMotor);
	resetMotorEncoder(rightkouqiuMotor);
	resetMotorEncoder(leftMotor);
}



void UpDown_Arm(int nSpeed,int nDegree,int nDelayTime)
{
		setMotorTarget(leftarmMotor, nDegree, nSpeed);
		setMotorTarget(rightarmMotor, nDegree, nSpeed);
	  delay(nDelayTime);
		setMotorTarget(leftarmMotor, nDegree, 0);
		setMotorTarget(rightarmMotor, nDegree, 0);
}

void Gyro_Rotation(int nSpeed,int nDegree,int nMaxTime)
{
	int real_degree = 0;
	clearTimer(T1); // Resets timer T1 to start counting at 0
	resetGyro(Gyro);
	real_degree = abs(getGyroHeading(Gyro));
	setMotorSpeed(leftMotor,  nSpeed);
	setMotorSpeed(rightMotor, -nSpeed);
  while(real_degree<nDegree)
  {
  	real_degree = abs(getGyroHeading(Gyro));
		displayTextLine(2, "%d", real_degree);
		if(time1[T1] >nMaxTime)
		{
		  	playNote(noteCSharp, octave2,  200);
		    break;
		}
  }
	setMotorSpeed(leftMotor,  0);
	setMotorSpeed(rightMotor, 0);
}



void Go_Forward_Distance(int nSpeed,int nDistance,int nMaxTime)
{
	int nTarget_Degree;
	int nDegree_Temp;
	clearTimer(T1); // Resets timer T1 to start counting at 0
	nTarget_Degree=(float)nDistance/200*360;
	resetMotorEncoder(leftMotor);
	//setMotorTarget(LeftMotor,nTarget_Degree,nSpeed);
	//setMotorTarget(rightMotor,nTarget_Degree,nSpeed);

	setMotorSpeed(leftMotor, nSpeed);
	setMotorSpeed(rightMotor, nSpeed);
	nDegree_Temp=getServoEncoder(leftMotor);

	while(nDegree_Temp<nTarget_Degree) //while the Sonar Sensor read data greater than '20':
  {
	  nDegree_Temp=abs(getServoEncoder(leftMotor));
		displayTextLine(2, "%d", nDegree_Temp);
		if(time1[T1] >nMaxTime)
		{
		  	playNote(noteCSharp, octave2,  200);
		    break;
		}
  }
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
}


void Go_Forward_Time(int nSpeed, int nDelay,int nFactor)
{
	int nSpeedTemp;
	int nDelayTemp;
	int i;
	float fFactor;
	int nLeftSpeed,nRightSpeed;
	fFactor=(float)nFactor/100;
	nSpeedTemp=nSpeed/5;
	nDelayTemp=nDelay/50;
	for(i=1;i<=5;i++)
	{
		nLeftSpeed=nSpeedTemp*i;
		nRightSpeed=nLeftSpeed*fFactor;
		setMotorSpeed(leftMotor, nLeftSpeed);
		setMotorSpeed(rightMotor, nRightSpeed);
		delay(5);
	}
	delay(nDelay-50);
	for(i=5;i>=1;i--)
	{
		nLeftSpeed=nSpeedTemp*i;
		nRightSpeed=nLeftSpeed*fFactor;
		setMotorSpeed(leftMotor, nLeftSpeed);
		setMotorSpeed(rightMotor, nRightSpeed);
		delay(5);
	}
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	delay(5);
}

void Kouqiu_fangqiu(int nSpeed,int nDegree,int nDelayTime)
{
  	resetMotorEncoder(leftkouqiuMotor);
	  resetMotorEncoder(rightkouqiuMotor);

		setMotorTarget(leftkouqiuMotor, nDegree, nSpeed);
		setMotorTarget(rightkouqiuMotor, nDegree, nSpeed);

	  delay(nDelayTime);
	  setMotorTarget(leftkouqiuMotor, 0, nSpeed);
		setMotorTarget(rightkouqiuMotor, 0, nSpeed);

	  delay(nDelayTime);

  	setMotorSpeed(leftkouqiuMotor, 0);
	  setMotorSpeed(rightkouqiuMotor, 0);
	  delay(5);
}
void Kouqiu_zhuangqiu(int nSpeed,int nDegree,int nDelayTime)
{
		setMotorTarget(leftkouqiuMotor, nDegree, nSpeed);
		setMotorTarget(rightkouqiuMotor, nDegree, nSpeed);
	  delay(nDelayTime);
  	setMotorSpeed(leftkouqiuMotor, 0);
	  setMotorSpeed(rightkouqiuMotor, 0);
	delay(5);
	}
