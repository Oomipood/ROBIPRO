#ifdef MIC_MODULE

//VARIABLES
#define MIC_PIN 30

//INIT
void MIC_MODULE_INIT(){
	pinMode(MIC_PIN, INPUT);
}

boolean MIC_MODULE_DIGITAL_DETECT(){
	int MIC_VALUE = digitalRead(MIC_PIN);
	return MIC_VALUE;
}

int MIC_MODULE_ANALOG_DETECT(){
	int MIC_VALUE = analogRead(MIC_PIN);
	if (MIC_VALUE > 0 and MIC_VALUE < 1024) return MIC_VALUE;
	else return 0;
}

#endif
