#ifdef SERVO_MODULE

//=======INIT=====================================================================
int sc = -4; 				// servo calibration
Servo robi_servo;

void SERVO_INIT(){

  robi_servo.attach(A0);  // attaches the servo on pin 9 to the servo object
}

void SERVO_TURN(int angle){

	robi_servo.write(angle + sc);
}

void SERVO_TEST(){

	robi_servo.write(45 + sc);
		delay(300);
	robi_servo.write(90 + sc);
		delay(300);
	robi_servo.write(135 + sc);
		delay(300);
	robi_servo.write(90 + sc);
		delay(500);

}

#endif /*SERVO_MODULE*/
