#pragma config(Sensor, port4,  TouchLED1,      sensorVexIQ_LED)
#pragma config(Sensor, port10, Gyro,           sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftarmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor2,          leftMotor,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor3,          ClawMotor,     tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor7,          rightarmMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor8,          rightMotor,    tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor9,          MMotor,        tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int threshold = 20;
	int ls = 0;
	int rs = 0;

	while(true)
	{
		// !!zhixing  zhuangwan
		ls = 1*getJoystickValue(ChA) + getJoystickValue(ChC)*1;
		rs = 1*getJoystickValue(ChA) - getJoystickValue(ChC)*1;


		if (ls > threshold || ls < -threshold)
		{
			setMotorSpeed(leftMotor, ls);
		}
		else
		{
			setMotorSpeed(leftMotor, 0);
		}
		if (rs > threshold || rs < -threshold)

		{
			setMotorSpeed(rightMotor, rs);
		}
		else
		{
			setMotorSpeed(rightMotor, 0);
		}
//armMotor*****************************************************************

		if(getJoystickValue(BtnFUp) == 1)
		{
			setMotorTarget(leftarmMotor, 310, 100);
			setMotorTarget(rightarmMotor, 310, 100);

		}
				else if(getJoystickValue(BtnFDown) == 1)
		{
			setMotorTarget(leftarmMotor, 0, 50);
			setMotorTarget(rightarmMotor, 0, 50);
		}

		else
		{
			setMotorSpeed(leftarmMotor, 0);
			setMotorSpeed(rightarmMotor,0);
		}


//ClawMotor*****************************************************************

		if(getJoystickValue(BtnRUp) == 1)
		{
			setMotorSpeed(ClawMotor,100);
		}
		else if(getJoystickValue(BtnRDown) == 1)
		{
			setMotorSpeed(ClawMotor, -100);
		}
		else if(getJoystickValue(BtnLUp) == 1)
		{
			setMotorSpeed(ClawMotor,100);
		}
		else if(getJoystickValue(BtnLDown) == 1)
		{
			setMotorSpeed(ClawMotor, -100);
		}
		else
		{
			setMotorSpeed(ClawMotor, 0);
		}


//MMotor*****************************************************************

		if(getJoystickValue(BtnEUp) == 1)
		{
			setMotorTarget(MMotor, -120,100);

		}
				else if(getJoystickValue(BtnEDown) == 1)
		{
			setMotorTarget(MMotor, 0,-100);
		}

		else
		{
			setMotorSpeed(MMotor,0);
		}
 //***************************************************************************

}
}
