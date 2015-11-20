#ifdef VOICE_MODULE

//=======INIT=====================================================================

VR myVR(A8,A9);    // 2:RX 3:TX, you can choose your favourite pins.
uint8_t records[7]; // save record
uint8_t buf[64];

#define forwardRecord (0)
#define backRecord   (1)
#define stopRecord   (2) 
#define rightRecord   (3) 
#define leftRecord   (4) 

//=======FUNCTIONS================================================================

boolean VOICE_INIT(){

	myVR.begin(9600);
	byte voice_init_try_count;
	boolean result; 

		if(myVR.clear() == 0){

			#ifdef DEBUG_MODE
				DEBUG_MODE Serial.println("Recognizer cleared."); 
			#endif

				if(myVR.load((uint8_t)forwardRecord) >= 0){
					#ifdef DEBUG_MODE
				    	Serial.println("forwardRecord loaded");
				    #endif
				}
				  
				if(myVR.load((uint8_t)backRecord) >= 0){
				 	#ifdef DEBUG_MODE
				    	Serial.println("backRecord loaded");
				    #endif
				}

				if(myVR.load((uint8_t)stopRecord) >= 0){
				 	#ifdef DEBUG_MODE
				    	Serial.println("stopRecord loaded");
				    #endif
				}

				if(myVR.load((uint8_t)rightRecord) >= 0){
				 	#ifdef DEBUG_MODE
				    	Serial.println("rightRecord loaded");
				    #endif
				}
				
				if(myVR.load((uint8_t)leftRecord) >= 0){
				 	#ifdef DEBUG_MODE
				    	Serial.println("leftRecord loaded");
				    #endif
				}

		    result = true;
		}

		else{

			#ifdef DEBUG_MODE
			    Serial.println("Not find VoiceRecognitionModule.");
			    Serial.println("Please check connection and restart Arduino.");
			#endif

		    result = false;
		}

return result;
}

byte VOICE_DETECT(){

	int ret;
	byte retun_voice;
  	ret = myVR.recognize(buf, 50);

  		if(ret>0){

		    switch(buf[1]){

		    	case forwardRecord:
		            //Serial.println("ROBI FORWARD");
		            retun_voice = 0;
		       	break;
		      	case backRecord:
		            //Serial.println("ROBI BACK");
		            retun_voice = 1;
		        break;
		      	case stopRecord:
		            //Serial.println("ROBI STOP");
		            retun_voice = 2;
		        break;
		      	case rightRecord:
		            //Serial.println("ROBI RIGHT");
		            retun_voice = 3;
		        break;
		      	case leftRecord:
		            //Serial.println("ROBI LEFT");
		            retun_voice = 4;
		            
		        break; 

		      	default:
		        //Serial.println("Record function undefined");
		        retun_voice = 255;
		        break;
		    }
		}

	return retun_voice;
}



#endif /*VOICE MODULE*/
