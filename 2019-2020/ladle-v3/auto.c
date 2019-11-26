#pragma config(Sensor, port3,   touchLED, sensorVexIQ_LED)
#pragma config(Sensor, port2,   gyro, sensorVexIQ_Gyro)
#pragma config(Motor,  motor4,  leftLiftMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor5,  ladleMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,  fixatorMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor10, rightLiftMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor11, leftWheelMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor12, rightWheelMotor, tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define LGC 2
#define WGC 9

#define SPIN_SPEED 15
#define TURN_SPEED 40
#define AIM_SPEED 5

#define FORWARD(cm) move(cm, cm, leftWheelSpeed, rightWheelSpeed);
#define BACK(cm) move(0 - cm, 0 - cm, leftWheelSpeed, rightWheelSpeed);
#define SPIN_LEFT(degress) spinLeft(degress, true);
#define SPIN_RIGHT(degress) spinRight(degress, true);
#define SPIN_L(degress) spinLeft(degress, false);
#define SPIN_R(degress) spinRight(degress, false);
#define TURN_LEFT(degress) turnLeft(degress);
#define TURN_RIGHT(degress) turnRight(degress);
#define SET_HIGH_SPEED setSpeed(60);

#define SET_LOW_SPEED setSpeed(15);

#define SET_NORMAL_SPEED setSpeed(40);
#define FIXATOR_OPEN fixator(150);
#define FIXATOR_ON fixator(260);
#define FIXATOR_OFF fixator(0);
#define LIFT_RESET lift(-30, true);
#define LIFT_HIGH lift(-30, false);
#define LIFT_MIDDLE lift(530, false);
#define LIFT_LOW lift(1200, false);
#define WAIT_LED waitTouchLED();

int leftWheelSpeed;
int leftWheelTarget;
int rightWheelSpeed;
int rightWheelTarget;

int ladleTarget;

void init();
void ladleShoot();
void ladlePick();
void setSpeed(int speed);
void move(int leftDiff, int rightDiff, int leftSpeed, int rightSpeed);
void spinLeft(int degress, bool aim);
void spinRight(int degress, bool aim);
void turnLeft(int degress);
void turnRight(int degress);
void resetWheel();
void fixator(int degress);
void lift(int degress, bool sync);
void waitTouchLED();

void readyForGreenQube() {
	LIFT_LOW
	FIXATOR_OFF
	WAIT_LED
}

void takeLeftGreenQube() {
	SET_NORMAL_SPEED
	FORWARD(7)
	SPIN_RIGHT(45)
	TURN_LEFT(88)
	SET_LOW_SPEED
	FORWARD(15)
	SET_NORMAL_SPEED
	FIXATOR_ON
	LIFT_MIDDLE


	TURN_RIGHT(50)

	FORWARD(33)
	FIXATOR_OFF
	SET_HIGH_SPEED
	BACK(35)
}

void takeRightGreenQube() {
	SET_NORMAL_SPEED
	FORWARD(5)
	SPIN_LEFT(45)
	TURN_RIGHT(88)
	SET_LOW_SPEED
	FORWARD(15)
	SET_NORMAL_SPEED
	FIXATOR_ON
	LIFT_MIDDLE
	TURN_LEFT(68)
	FORWARD(34)
	FIXATOR_OFF
	SET_HIGH_SPEED
	BACK(40)
}

void takeMedialGreenQube() {
	SET_NORMAL_SPEED
	FIXATOR_OFF

	TURN_LEFT(110)
	FORWARD(16)
	TURN_RIGHT(65)

	FORWARD(18)
	FIXATOR_ON
	LIFT_HIGH

	SPIN_LEFT(126)
	FORWARD(30)
	FIXATOR_OFF

	SET_HIGH_SPEED
	BACK(20)
}

task main()
{
	init();

	readyForGreenQube();
	takeRightGreenQube();

	readyForGreenQube();
	takeMedialGreenQube();

	readyForGreenQube();
	takeLeftGreenQube();

	WAIT_LED
	FIXATOR_OFF
	LIFT_RESET
}

void spinLeft(int degress, bool aim) {
	resetGyro(gyro);

	repeatUntil(getGyroDegrees(gyro) > degress) {
		setMotorSpeed(leftWheelMotor, -SPIN_SPEED);
		setMotorSpeed(rightWheelMotor, SPIN_SPEED);
	}

	setMotorSpeed(leftWheelMotor, 0);
	setMotorSpeed(rightWheelMotor, 0);

	if (aim == true) {
		repeatUntil(getGyroDegrees(gyro) == degress) {
			int d = getGyroDegrees(gyro);

		  if (d > degress) {
				setMotorSpeed(leftWheelMotor, AIM_SPEED);
				setMotorSpeed(rightWheelMotor, -AIM_SPEED);
		  }

		  if (d < degress) {
		  	setMotorSpeed(leftWheelMotor, -AIM_SPEED);
				setMotorSpeed(rightWheelMotor, AIM_SPEED);
			}
		}

		setMotorSpeed(leftWheelMotor, 0);
		setMotorSpeed(rightWheelMotor, 0);
	}

	resetWheel();
}

void spinRight(int degress, bool aim) {
	resetGyro(gyro);

	repeatUntil(getGyroDegrees(gyro) < 0 - degress) {
		setMotorSpeed(leftWheelMotor, SPIN_SPEED);
		setMotorSpeed(rightWheelMotor, -SPIN_SPEED);
	}

	setMotorSpeed(leftWheelMotor, 0);
	setMotorSpeed(rightWheelMotor, 0);

	if (aim == true) {
		repeatUntil(getGyroDegrees(gyro) == 0 - degress) {
			int d = getGyroDegrees(gyro);

		  if (d < 0 - degress) {
				setMotorSpeed(leftWheelMotor, -AIM_SPEED);
				setMotorSpeed(rightWheelMotor, AIM_SPEED);
		  }

		  if (d > 0 - degress) {
		  	setMotorSpeed(leftWheelMotor, AIM_SPEED);
				setMotorSpeed(rightWheelMotor, -AIM_SPEED);
			}
		}

		setMotorSpeed(leftWheelMotor, 0);
		setMotorSpeed(rightWheelMotor, 0);
	}

	resetWheel();
}

void turnLeft(int degress) {
  resetGyro(gyro);

  repeatUntil(abs(getGyroDegrees(gyro)) > degress) {
    setMotorSpeed(rightWheelMotor, TURN_SPEED);
  }

  setMotorSpeed(rightWheelMotor, 0);

  repeatUntil(abs(getGyroDegrees(gyro)) == degress) {
    int d = abs(getGyroDegrees(gyro));

    if (d > degress) {
      setMotorSpeed(rightWheelMotor, -AIM_SPEED);
    }

    if (d < degress) {
      setMotorSpeed(rightWheelMotor, AIM_SPEED);
    }
  }

  setMotorSpeed(rightWheelMotor, 0);
  resetWheel();
}

void turnRight(int degress) {
  resetGyro(gyro);

  repeatUntil(abs(getGyroDegrees(gyro)) > degress) {
    setMotorSpeed(leftWheelMotor, TURN_SPEED);
  }

  setMotorSpeed(leftWheelMotor, 0);

  repeatUntil(abs(getGyroDegrees(gyro)) == degress) {
    int d = abs(getGyroDegrees(gyro));

    if (d > degress) {
      setMotorSpeed(leftWheelMotor, -AIM_SPEED);
    }

    if (d < degress) {
      setMotorSpeed(leftWheelMotor, AIM_SPEED);
    }
  }

  setMotorSpeed(leftWheelMotor, 0);
  resetWheel();
}

void setSpeed(int speed) {
	leftWheelSpeed = speed;
	rightWheelSpeed = speed;
}

void move(int leftDiff, int rightDiff, int leftSpeed, int rightSpeed) {
	leftWheelTarget += leftDiff * WGC;
	rightWheelTarget += rightDiff * WGC;

	setMotorTarget(leftWheelMotor, leftWheelTarget, leftSpeed);
	setMotorTarget(rightWheelMotor, rightWheelTarget, rightSpeed);
	waitUntilMotorStop(leftWheelMotor);
	waitUntilMotorStop(rightWheelMotor);
}

void ladleShoot() {
	ladleTarget += 170 * LGC;
	setMotorTarget(ladleMotor, ladleTarget, 100);
	waitUntilMotorStop(ladleMotor);
	ladleTarget -= 170 * LGC;
	setMotorTarget(ladleMotor, ladleTarget, 100);
	waitUntilMotorStop(ladleMotor);
}

void ladlePick() {
	ladleTarget += 360 * LGC;
	setMotorTarget(ladleMotor, ladleTarget, 100);
	waitUntilMotorStop(ladleMotor);
}

void init() {
  // init speed
  leftWheelSpeed = 0;
  rightWheelSpeed = 0;

  // init target
  leftWheelTarget = 0;
  rightWheelTarget = 0;
	ladleTarget = 0;

  resetMotorEncoder(rightWheelMotor);
  resetMotorEncoder(leftWheelMotor);

  resetMotorEncoder(ladleMotor);
  setMotorTarget(ladleMotor, 0, 0);

  setMotorBrakeMode(leftWheelMotor, motorBrake);
	setMotorBrakeMode(rightWheelMotor, motorBrake);
	setMotorBrakeMode(ladleMotor, motorHold);
	setMotorBrakeMode(fixatorMotor, motorHold);
	setMotorBrakeMode(leftLiftMotor, motorHold);
	setMotorBrakeMode(rightLiftMotor, motorHold);

	setGyroSensitivity(gyro, gyroHighSensitivity);
}

void fixator(int degress) {
	setMotorTarget(fixatorMotor, degress, 100);
	waitUntilMotorStop(fixatorMotor);
}

void lift(int degress, bool sync) {
	setMotorTarget(leftLiftMotor, degress, 100);
	setMotorTarget(rightLiftMotor, degress, 100);
	if (sync == true) {
		waitUntilMotorStop(leftLiftMotor);
		waitUntilMotorStop(rightLiftMotor);
	}
}

void resetWheel() {
	leftWheelTarget = 0;
  rightWheelTarget = 0;
  resetMotorEncoder(leftWheelMotor);
  resetMotorEncoder(rightWheelMotor);
}

void waitTouchLED() {
	setTouchLEDColor(touchLED, colorBlueGreen);
	waitUntil((getTouchLEDValue(touchLED) == 1));
	setTouchLEDColor(touchLED, colorRed);
}
