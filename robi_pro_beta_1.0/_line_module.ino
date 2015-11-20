#ifdef LINE_MODULE

//PIN VARIABLES
const byte SS1 = 37;	//LEFT 1
const byte SS2 = 38;	//LEFT 2
const byte SS3 = 39;	//CENTER SENSOR
const byte SS4 = 40;	//RIGHT 2
const byte SS5 = 41;	//RIGHT 1
const byte NEAR = 42;	//NEAR SENSOR
const byte CLP = 43;	//SW1 SWITCH


//INIT
void LINE_MODULE_INIT(){
	pinMode(SS1, INPUT);
	pinMode(SS2, INPUT);
	pinMode(SS3, INPUT);
	pinMode(SS4, INPUT);
	pinMode(SS5, INPUT);
	pinMode(NEAR, INPUT);
	pinMode(CLP, INPUT);
}

void LINE_MODULE_READ(){

	SS1_STATUS = digitalRead(SS1);
	SS2_STATUS = digitalRead(SS2);
	SS3_STATUS = digitalRead(SS3);
	SS4_STATUS = digitalRead(SS4);
	SS5_STATUS = digitalRead(SS5);

	NEAR_STATUS = digitalRead(NEAR);
	CLP_STATUS = digitalRead(CLP);

}

void LINE_MODULE_GET_UPDATE_STATUS(){
	CLP_STATUS = digitalRead(CLP);
}

void LINE_MODULE_STATUS_SERIAL_PRINT(){

	Serial.print("SS_STATUS ");
	Serial.print("SS1:");
	Serial.print(SS1_STATUS);

	Serial.print(" | SS2:");
	Serial.print(SS2_STATUS);

	Serial.print(" | SS3:");
	Serial.print(SS3_STATUS);

	Serial.print(" | SS4:");
	Serial.print(SS4_STATUS);

	Serial.print(" | SS5:");
	Serial.print(SS5_STATUS);

	Serial.print(" | Near:");
	Serial.print(NEAR_STATUS);

	Serial.print(" | CLP:");
	Serial.println(CLP_STATUS);
}


#endif
