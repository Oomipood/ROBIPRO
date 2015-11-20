#ifdef BUZZER_MODULE

#define BUZZER_PIN A5

void BUZZER_MODULE_INIT(){

	pinMode(BUZZER_PIN, OUTPUT);
	digitalWrite(BUZZER_PIN, HIGH);

}

void BUZZER_MODULE_TEST(){

		digitalWrite(BUZZER_PIN, LOW);
		delay(150);
		digitalWrite(BUZZER_PIN, HIGH);
		delay(50);
		digitalWrite(BUZZER_PIN, LOW);
		delay(150);
		digitalWrite(BUZZER_PIN, HIGH);
}

void BUZZER_MODULE_BEEP(int beep_delay){

		digitalWrite(BUZZER_PIN, LOW);
		delay(beep_delay);
		digitalWrite(BUZZER_PIN, HIGH);

}

void BUZZER_MODULE_BEEP_ON(){
	digitalWrite(BUZZER_PIN, LOW);
}
void BUZZER_MODULE_BEEP_OFF(){
	digitalWrite(BUZZER_PIN, HIGH);
}




#endif /*BUZZER_MODULE*/
