
//VARIABLES
int scan0 = 0;
int scan23 = 0; 
int scan45 = 0;
int scan68 = 0;

int scan90 = 0;

int scan113 = 0;
int scan135 = 0;
int scan158 = 0;
int scan180 = 0;

int servo_delay = 80;


//SCANING

		SERVO_TURN(23);
		delay(servo_delay);
		scan23 = ULTRASONIC_1X_PING_2();
		scan23 = ( scan23 + ULTRASONIC_1X_PING_2() ) / 2;

		SERVO_TURN(45);
		delay(servo_delay);
		scan45 = ULTRASONIC_1X_PING_2();
		scan45 = ( scan45 + ULTRASONIC_1X_PING_2() ) / 2;

		SERVO_TURN(68);
		delay(servo_delay);
		scan68 = ULTRASONIC_1X_PING_2();
		scan68 = ( scan68 + ULTRASONIC_1X_PING_2() ) / 2;

		SERVO_TURN(90);
		delay(servo_delay);
		scan90 = ULTRASONIC_1X_PING_2();
		scan90 = ( scan90 + ULTRASONIC_1X_PING_2() ) / 2;

		SERVO_TURN(113);
		delay(servo_delay);
		scan113 = ULTRASONIC_1X_PING_2();
		scan113 = ( scan113 + ULTRASONIC_1X_PING_2() ) / 2;

		SERVO_TURN(135);
		delay(servo_delay);
		scan135 = ULTRASONIC_1X_PING_2();
		scan135 = ( scan135 + ULTRASONIC_1X_PING_2() ) / 2;

		SERVO_TURN(158);
		delay(servo_delay);
		scan158 = ULTRASONIC_1X_PING_2();
		scan158 = ( scan158 + ULTRASONIC_1X_PING_2() ) / 2;

/*
#ifdef DEBUG_MODE
		Serial.print("SCANS: ");
		Serial.print(scan23);
		Serial.print(" | ");
		Serial.print(scan45);
		Serial.print(" | ");
		Serial.print(scan68);
		Serial.print(" | ");
		Serial.print(scan90);
		Serial.print(" | ");
		Serial.print(scan113);
		Serial.print(" | ");
		Serial.print(scan135);
		Serial.print(" | ");
		Serial.println(scan158);
	delay(2000);
#endif

*/

//CALCULATIONS


	int left_side = scan23 + scan45 + scan68;
	int center = scan68 + scan90 + scan113;
	int right_side = scan113 + scan135 + scan158;

/*
#ifdef DEBUG_MODE
	Serial.print("CALC: ");
	Serial.print(left_side);
	Serial.print(" | ");
	Serial.print(center);
	Serial.print(" | ");
	Serial.println(right_side);	

	delay(2000);
#endif

Serial.print("DECISION: ");
*/
if (center < right_side and center < left_side){
	ROBI_FORWARD(80,70);
	//delay(300);
	//ROBI_STOP();
	//Serial.println("ROBI_FORWARD");
}
if (left_side < center and left_side < right_side){
	ROBI_FORWARD(80,0);
	//delay(100);
	//ROBI_STOP();
	//Serial.println("ROBI_RIGHT");
}

if (right_side < center and right_side < left_side){
	ROBI_FORWARD(0,80);
	//delay(100);
	//ROBI_STOP();
	//Serial.println("ROBI_LEFT");
}

