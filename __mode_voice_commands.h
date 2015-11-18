//MODE3:VOICE MOVEMENT LOGICS FILE

#ifdef VOICE_MODULE

	byte voice_byte = 255;
	voice_byte = VOICE_DETECT();

		if (0 == voice_byte){
			ROBI_FORWARD(255,225);
			delay(1000);
		}
		
		if (1 == voice_byte){
			ROBI_BACK(255,255);
			delay(1000);
		}
		
		if (3 == voice_byte){
			ROBI_FORWARD(255,0);
			delay(600);
		}
		
		if (4 == voice_byte){
			ROBI_FORWARD(0,255);
			delay(600);
		}
	ROBI_STOP();
#endif
