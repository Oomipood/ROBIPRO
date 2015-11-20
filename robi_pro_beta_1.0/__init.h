// INIT FILE

	#ifdef DEBUG_MODE
		Serial.begin(9600);
		Serial.println("ROBI 2 - DEBUG MODE ON");
	#endif

	#ifdef TFT_MODULE	

		TFT_INIT();
		TFT_DRAW_LOGO();
		TFT_DRAW_LINE();

	#endif

	#ifdef MOTORS_MODULE

		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("Motors init...", 1, ST7735_WHITE, 0, 62);
		#endif
			MOTORS_SETUP();
			ROBI_STOP();
			delay(500);
		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 62);
		#endif

	#endif

	#ifdef IRREMOTE_MODULE

		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("IRremote init...", 1, ST7735_WHITE, 0, 72);
		#endif		
			IRREMOTE_INIT();
		#ifdef TFT_MODULE
			delay(500);
			TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 72);
		#endif

	#endif

	#ifdef ULTRASONIC_MODULE

		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("Ultrasonic init...", 1, ST7735_WHITE, 0, 82);
		#endif	
			ULTRASONIC_INIT();
			boolean u_test = ULTRASONIC_TEST();
			delay(500);
			if (true == u_test){
				#ifdef TFT_MODULE
					TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 82);
				#endif	
			}
			else 
				#ifdef TFT_MODULE
					TFT_PRINT_TEXT("ERR", 1, ST7735_RED, 110, 82);
				#endif
			#ifdef DEBUG_MODE
				Serial.print("Ultrasonic test: ");
				Serial.println(long(ULTRASONIC_1X_PING()));
			#endif
				
	#endif

	#ifdef SERVO_MODULE

		SERVO_INIT();
		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("Servo Init...", 1, ST7735_WHITE, 0, 92);
		#endif
			
//Servo turning right and left

			SERVO_TURN(0);
			delay(200);

			for (byte i=0; i<=180; i++){
				SERVO_TURN(i);
				delay(7);
			}
			for (byte j=180; j>=4; j--){
				SERVO_TURN(j);
				delay(7);
			}

			SERVO_TURN(90);


		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 92);
		#endif
			#ifdef DEBUG_MODE
				Serial.print("Servo testing...");
				//SERVO_TEST();
				Serial.println(" done!");
			#endif

	#endif

	#ifdef ENCODERS_MODULE

		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("Encoders init...", 1, ST7735_WHITE, 0, 102);
		#endif
			ENCODERS_SETUP();
			delay(200);
		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 102);
		#endif

	#endif

	#ifdef WALL_MODULE

		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("Wall modl init...", 1, ST7735_WHITE, 0, 112);
		#endif
			WALL_MODULE_INIT();
			delay(200);
		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 112);
		#endif

	#endif

	#ifdef VOICE_MODULE

		#ifdef TFT_MODULE		
			TFT_PRINT_TEXT("Voice modl init...", 1, ST7735_WHITE, 0, 122);
		#endif
			boolean v_test = VOICE_INIT();
			delay(500);
		#ifdef TFT_MODULE
			if (1==v_test) {TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 122);}
			else {TFT_PRINT_TEXT("ERR", 1, ST7735_RED, 110, 122);}	
		#endif	

	#endif	

	#ifdef BUZZER_MODULE

		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("Buzzer test...", 1, ST7735_WHITE, 0, 132);
		#endif
			BUZZER_MODULE_INIT();
			BUZZER_MODULE_TEST();
			delay(500);
		#ifdef TFT_MODULE
			TFT_PRINT_TEXT("OK", 1, ST7735_GREEN, 115, 132);
		#endif	

	#endif		

delay(2000); //test delay

//delay(3000);
#ifdef TFT_MODULE			
	TFT_CLEAR_WORK_AREA();
	TFT_PRINT_DIRECTION(" READY", 3);
	TFT_FUNC_AREA();
	TFT_PRINT_SPEED(LEFT_SPEED, RIGHT_SPEED);
#endif
