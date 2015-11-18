#ifdef MOTORS_MODULE

const byte IN1 = 4; //MOT1 REVERSE
const byte IN2 = 5; //MOT1 PWM PIN
const byte IN3 = 6; //MOT2 PWM PIN
const byte IN4 = 7; //MOT2 REVERSE

byte ROBI_SPEED = 200;


void MOTORS_SETUP(){
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
}

void ROBI_STOP(){
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}

void ROBI_FORWARD(byte LEFT_WHELL_SPEED, byte RIGHT_WHELL_SPEED){

	digitalWrite(IN1, LOW);
	analogWrite(IN2, RIGHT_WHELL_SPEED);
	analogWrite(IN3, LEFT_WHELL_SPEED);
	digitalWrite(IN4, LOW);

}

void ROBI_BACK(byte LEFT_WHELL_SPEED, byte RIGHT_WHELL_SPEED){

	analogWrite(IN1, RIGHT_WHELL_SPEED);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	analogWrite(IN4, LEFT_WHELL_SPEED);

}



#endif /*MOTORS_MODULE*/
