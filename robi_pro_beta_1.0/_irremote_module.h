#ifdef IRREMOTE_MODULE

//=======INIT=====================================================================
int receiver = 21;
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results' 



//=======FUNCTIONS================================================================

void IRREMOTE_INIT(){
	attachInterrupt(2,CHECK_IR,CHANGE); //FOR MEGA
	irrecv.enableIRIn(); // Start the receiver
}

void CHECK_IR(){

	IR_PREV_COMMAND = IR_COMMAND;

	while(irrecv.decode(&results)){

	  	switch(results.value){

			case 0xFF629D: IR_COMMAND = 11; break; //FORWARD
			case 0xFF22DD: IR_COMMAND = 22; break; //LEFT
			case 0xFF02FD: IR_COMMAND = 33; break; //OK
			case 0xFFC23D: IR_COMMAND = 44; break; //RIGHT
			case 0xFFA857: IR_COMMAND = 55; break; //BACK
			case 0xFF6897: IR_COMMAND = 1; break; //1
			case 0xFF9867: IR_COMMAND = 2; break; //2
			case 0xFFB04F: IR_COMMAND = 3; break; //3
			case 0xFF30CF: IR_COMMAND = 4; break; //4
			case 0xFF18E7: IR_COMMAND = 5; break; //5
			case 0xFF7A85: IR_COMMAND = 6; break; //6
			case 0xFF10EF: IR_COMMAND = 7; break; //7
			case 0xFF38C7: IR_COMMAND = 8; break; //8
			case 0xFF5AA5: IR_COMMAND = 9; break; //9
			case 0xFF42BD: IR_COMMAND = 77; break; //*
			case 0xFF4AB5: IR_COMMAND = 88; break; //0
			case 0xFF52AD: IR_COMMAND = 99; break; //#

		}

	irrecv.resume();

	#ifdef DEBUG_MODE
		Serial.print("IR_PREV_COMMAND: ");
		Serial.print(IR_PREV_COMMAND);
		Serial.print(" | IR_COMMAND:");
		Serial.println(IR_COMMAND);
	#endif
 	}
 	
}


// OLD FUNCTIONS
/*
boolean IRREMOTE_RECEIVE(){
	if (irrecv.decode(&results)){return true;}
	else {return false;}
}

void IRREMOTE_RESUME(){
	irrecv.resume();
}

byte IRREMOTE_TRANSLATE_IR() {

	byte result = 0;

  switch(results.value){

	case 0xFF629D:  result = 11; break; //FORWARD
	case 0xFF22DD:  result = 22; break; //LEFT
	case 0xFF02FD:  result = 33; break; //OK
	case 0xFFC23D:  result = 44; break; //RIGHT
	case 0xFFA857:  result = 55; break; //BACK
	case 0xFF6897:  result = 1; break; //1
	case 0xFF9867:  result = 2; break; //2
	case 0xFFB04F:  result = 3; break; //3
	case 0xFF30CF:  result = 4; break; //4
	case 0xFF18E7:  result = 5; break; //5
	case 0xFF7A85:  result = 6; break; //6
	case 0xFF10EF:  result = 7; break; //7
	case 0xFF38C7:  result = 8; break; //8
	case 0xFF5AA5:  result = 9; break; //9
	case 0xFF42BD:  result = 77; break; //*
	case 0xFF4AB5:  result = 88; break; //0
	case 0xFF52AD:  result = 99; break; //#
	  //default: 
	   // Serial.println("unknown");
	}

delay(50);
return result;

}
*/
#endif /*IRREMOTE_MODULE*/
