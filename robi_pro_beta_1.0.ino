//==========================MAIN CODE FILE=======================================
//===============================================================================

/*MODULES DEFINITIONS*/
#define TFT_MODULE
#define MOTORS_MODULE
#define IRREMOTE_MODULE
#define ULTRASONIC_MODULE
#define SERVO_MODULE
#define ENCODERS_MODULE
#define WALL_MODULE
#define BUZZER_MODULE
#define VOICE_MODULE
#define LINE_MODULE
#define MIC_MODULE

/*MODES*/
//#define DEBUG_MODE	//uncomment for debug
#define STARTUP_MODE

/*LIBRARIES AND INCLUDES*/
#include <IRremote.h>				// IR Remote library
#include <Adafruit_GFX.h>    		// Core graphics library
#include <Adafruit_ST7735.h> 		// Hardware-specific library
#include <SPI.h>					// SPI bus library for TFT display
#include <Servo.h>					// Standart servo library
#include <SoftwareSerial.h> 		// Software serial for VoiceRecognition
#include <VoiceRecognitionV3.h> 	// VoiceRecognition library

/*GLOBAL VARIABLES*/
byte IR_COMMAND = 0;
byte PREV_IR_COMMAND = 0;
byte MODE = 0;
byte PREV_MODE = 0;
byte IR_PREV_COMMAND = 0;
int LEFT_ENC_COUNT = 0;
int RIGHT_ENC_COUNT = 0;
byte LEFT_SPEED = 0;
byte RIGHT_SPEED = 0;
byte WALL_STATE = 0;
long LEFT_PING = 0;
long CENTER_PING = 0;
long RIGHT_PING	= 0;
byte MODE1_SPEED = 120;
boolean UPDATE_MODE_ON_TFT = false;

//VARIABLES FOR LINE READINGS
byte SS1_STATUS = 0;
byte SS2_STATUS = 0;
byte SS3_STATUS = 0;
byte SS4_STATUS = 0;
byte SS5_STATUS = 0;
byte NEAR_STATUS = 0;
byte CLP_STATUS = 0;

/*FUNCTIONS DECLARATIONS*/
	#include "__funcs.h";

//===============================================================================
//================================== SETUP ======================================
//===============================================================================
void setup(){

	#include "__init.h";

} //END OF SETUP
//===============================================================================
//========================= MAIN LOOP FUNCTION ==================================
//===============================================================================
void loop(){

/*===================== IRREMOTE MODULE COMMANDS ======================= */

	#ifndef IRREMOTE_MODULE
		#ifndef TFT_MODULE
			TFT_PRINT_ERROR("IR REMOTE DISABLED!");
		#endif
	#endif

	#ifdef IRREMOTE_MODULE

			PREV_MODE = MODE; //save previous mode

			//check if on IR command to change mode
				if (IR_COMMAND == 1){MODE = 1;}
				if (IR_COMMAND == 2){MODE = 2;}
				if (IR_COMMAND == 3){MODE = 3;}
				if (IR_COMMAND == 4){MODE = 4;}

			// if no new command, update disable
			if (PREV_MODE == MODE){UPDATE_MODE_ON_TFT = false;}
			else {UPDATE_MODE_ON_TFT = true;}

	#endif

/*================== END OF IRREMOTE MODULE COMMANDS ==================== */
//MODE1:MANUAL	
	if (1 == MODE){
			#ifdef TFT_MODULE
				if (true == UPDATE_MODE_ON_TFT){
					TFT_PRINT_DIRECTION("MANUAL", 3);
					UPDATE_MODE_ON_TFT == false;}
			#endif

		#include "__mode_manual.h"; //MANUAL MODE
	}	
//MODE2:DISCOVER LOGICS
	if (2 == MODE){	
			#ifdef TFT_MODULE
				if (true == UPDATE_MODE_ON_TFT){
					TFT_PRINT_DIRECTION("DISCVR", 3);
					UPDATE_MODE_ON_TFT == false;}
			#endif

		#include "__mode_discover.h"; //DISCOVER MODE
		//#include "__mode_follow_me.h"; //FOLLOWING MODE
	}
//MODE3:VOICE MOVEMENT LOGICS			
	if (3 == MODE){
			#ifdef TFT_MODULE
				if (true == UPDATE_MODE_ON_TFT){
					TFT_PRINT_DIRECTION("VOICE", 3);
					UPDATE_MODE_ON_TFT == false;}
			#endif
					
		//#include "__mode_voice_commands.h";
	}
//MODE4: LINE FOLLOWING			
	if (4 == MODE){
			#ifdef TFT_MODULE
				if (true == UPDATE_MODE_ON_TFT){
				TFT_PRINT_DIRECTION("FOLLOW", 3);
				UPDATE_MODE_ON_TFT == false;}
			#endif

		//#include "__mode_line_following.h";
	}

//UPDATE TFT COMMANDS
#ifdef ENCODERS_MODULE
	LEFT_ENC_COUNT = ENCODERS_GET_LEFT_COUNT();
	RIGHT_ENC_COUNT = ENCODERS_GET_RIGHT_COUNT();
#endif
	
#ifdef TFT_MODULE
	#ifdef ULTRASONIC_MODULE
		TFT_PRINT_ENCODERS_STATUS(LEFT_ENC_COUNT/2, RIGHT_ENC_COUNT/2);
	#endif
	#ifdef ULTRASONIC_MODULE
		TFT_PRINT_DISTANCE(ULTRASONIC_1X_PING());
	#endif
#endif

//CODE FOR MIC MODULE
//#ifdef DEBUG_MODE
	//Serial.print("MIC STATUS: ");
	//Serial.println(MIC_MODULE_DIGITAL_DETECT());
//#endif




} //END OF LOOP

//===============================================================================
//==============================FUNCTIONS========================================
//===============================================================================

//SOME ADDITIONAL FUNCTION HERE

