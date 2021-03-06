#pragma config(Sensor, port7,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port8,  touchLED,       sensorVexIQ_LED)
#pragma config(Motor,  motor1,          rightArmMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor2,          leftArmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor3,          hookMotor,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor4,          caterpillarMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor5,          rightWheelMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          leftWheelMotor, tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define TURN_RIGHT(degress) turnAction(20, degress, 5000)
#define TURN_LEFT(degress) turnAction(-20, degress, 5000)
#define FORWARD(time) goTimeAction(50, time, 100)
#define BACK(time) goTimeAction(-50, time, 100)

#define ARM(degress) armActionForPosition(50, degress)
#define ARM_LOW ARM(70)
#define ARM_HIGH ARM(360)
#define ARM_INIT ARM(320)
#define ARM_FOR_LOW_TOWER ARM(320)
#define ARM_DOWN armAction(50, 100)

void init();
void goTimeAction(int speed, int delayTime, int factor);
void turnAction(int speed, int degree, int maxTime);
void armAction(int speed, int degree);
void armActionForPosition(int speed, int degree);

int lastArmDegress;

task main(){
	init();

	lastArmDegress = 320;

	setTouchLEDColor(touchLED, colorRed); 
	waitUntil((getTouchLEDValue(touchLED)==1));
	setTouchLEDColor(touchLED, colorGreen);

	ARM_LOW;
	TURN_LEFT(60);
	FORWARD(850);
	TURN_RIGHT(98);
	FORWARD(650);
	ARM_FOR_LOW_TOWER;
	TURN_LEFT(19);
	FORWARD(1380);
	ARM_DOWN;
	BACK(2000);
	ARM_INIT;


	setTouchLEDColor(touchLED, colorRed);
	waitUntil((getTouchLEDValue(touchLED)==1));
	setTouchLEDColor(touchLED, colorGreen);

	ARM_LOW;
	TURN_RIGHT(60);
	FORWARD(850);
	TURN_LEFT(98);
	FORWARD(650);
	ARM_FOR_LOW_TOWER;
	TURN_RIGHT(21);
	FORWARD(1380);
	ARM_DOWN;
	BACK(2000);
	ARM_INIT;

}

void armActionForPosition(int speed, int degree)
{
	setMotorTarget(leftArmMotor, lastArmDegress - degree, speed);
	setMotorTarget(rightArmMotor, lastArmDegress - degree, speed);
	waitUntilMotorStop(leftArmMotor);
	waitUntilMotorStop(rightArmMotor);
	resetMotorEncoder(leftArmMotor);
	resetMotorEncoder(rightArmMotor);
	lastArmDegress = degree;
}

void armAction(int speed, int degree)
{
	setMotorTarget(leftArmMotor, degree, speed);
	setMotorTarget(rightArmMotor, degree, speed);
	waitUntilMotorStop(leftArmMotor);
	waitUntilMotorStop(rightArmMotor);
	resetMotorEncoder(leftArmMotor);
	resetMotorEncoder(rightArmMotor);
	lastArmDegress += -degree;
}

void turnAction(int speed, int degree, int maxTime)
{
	int realDegree = 0;
	clearTimer(T1); // Resets timer T1 to start counting at 0
	resetGyro(gyroSensor);

	realDegree = abs(getGyroHeading(gyroSensor));
	setMotorSpeed(leftWheelMotor, speed);
	setMotorSpeed(rightWheelMotor, -speed);

	while(realDegree < degree)
	{
		realDegree = abs(getGyroHeading(gyroSensor));
		displayTextLine(2, "%d", realDegree);

		if(time1[T1] > maxTime)
		{
			playNote(noteCSharp, octave2,  200);
			break;
		}
	}

	setMotorSpeed(leftWheelMotor,  0);
	setMotorSpeed(rightWheelMotor, 0);
	delay(100);
}

void goTimeAction(int speed, int delayTime, int factor)
{
	int tempSpeed;
	int tempDelay;

	int i;
	float realFactor;

	int leftSpeed, rightSpeed;

	realFactor = (float)factor/100;

	tempSpeed = speed/5;
	tempDelay = delayTime/50;

	for(i=1;i<=5;i++)
	{
		leftSpeed = tempSpeed * i;
		rightSpeed = leftSpeed * realFactor;

		setMotorSpeed(leftWheelMotor, leftSpeed);
		setMotorSpeed(rightWheelMotor, rightSpeed);
		delay(5);
	}

	delay(delayTime-50);

	for(i=5;i>=1;i--)
	{
		leftSpeed= tempSpeed*i;
		rightSpeed=leftSpeed * factor;
		setMotorSpeed(leftWheelMotor, leftSpeed);
		setMotorSpeed(rightWheelMotor, rightSpeed);
		delay(5);
	}

	setMotorSpeed(leftWheelMotor, 0);
	setMotorSpeed(rightWheelMotor, 0);
	delay(5);
}

void init()
{
	resetMotorEncoder(leftArmMotor);
	resetMotorEncoder(rightArmMotor);
	resetMotorEncoder(rightWheelMotor);
	resetMotorEncoder(leftWheelMotor);
	resetMotorEncoder(hookMotor);
}
