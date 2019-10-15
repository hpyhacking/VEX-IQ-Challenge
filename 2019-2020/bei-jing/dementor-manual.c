#pragma config(Sensor, port7,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port8,  touchLED,       sensorVexIQ_LED)
#pragma config(Motor,  motor1,          rightArmMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor2,          leftArmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor3,          hookMotor,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor4,          caterpillarMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor5,          rightWheelMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          leftWheelMotor, tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int lowerLimit = 20;
	int leftSpeed = 0;
	int rightSpeed = 0;

	while(true)
	{
		leftSpeed = 1.27 * getJoystickValue(ChA) + getJoystickValue(ChC) * 1.27;
		rightSpeed = 1.27 * getJoystickValue(ChA) - getJoystickValue(ChC) * 1.27;

		if (leftSpeed > lowerLimit || leftSpeed < -lowerLimit)
		{
			setMotorSpeed(leftWheelMotor, leftSpeed);
		}
		else
		{
			setMotorSpeed(leftWheelMotor, 0);
		}

		if (rightSpeed > lowerLimit || rightSpeed < -lowerLimit)
		{
			setMotorSpeed(rightWheelMotor, rightSpeed);
		}
		else
		{
			setMotorSpeed(rightWheelMotor, 0);
		}

		// arm motor
		if (getJoystickValue(BtnFUp) == 1)
		{
			setMotorTarget(leftArmMotor, 0, 100);
			setMotorTarget(rightArmMotor, 0, 100);
		}
		else if (getJoystickValue(BtnFDown) == 1)
		{
			setMotorTarget(leftArmMotor, 410, 50);
			setMotorTarget(rightArmMotor, 410, 50);
		}
		else
		{
			setMotorSpeed(leftArmMotor, 0);
			setMotorSpeed(rightArmMotor, 0);
		}

		// hook motor
		if (getJoystickValue(BtnEUp) == 1)
		{
			setMotorTarget(hookMotor, 400, 100);
		}
		else if (getJoystickValue(BtnEDown) == 1)
		{
			setMotorTarget(hookMotor, 0, 30);
		}
		else
		{
			setMotorSpeed(hookMotor, 0);
		}

		// caterpillar motor
		if (getJoystickValue(BtnLUp) == 1)
		{
			setMotorSpeed(caterpillarMotor, 100);
		}
		else if (getJoystickValue(BtnLDown) == 1)
		{
			setMotorSpeed(caterpillarMotor, -100);
		}
		else
		{
			setMotorSpeed(caterpillarMotor, 0);
		}
	}
}
