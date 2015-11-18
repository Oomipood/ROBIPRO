#ifdef ENCODERS_MODULE

	volatile int left_enc_counter = 0;
	volatile int right_enc_counter = 0;

void ENCODERS_SETUP(){
	attachInterrupt(0, ENCODERS_RIGHT_COUNT, CHANGE);
	attachInterrupt(1, ENCODERS_LEFT_COUNT, CHANGE);
}

void ENCODERS_LEFT_COUNT(){
	left_enc_counter++;
}
void ENCODERS_RIGHT_COUNT(){
	right_enc_counter++;
}

int ENCODERS_GET_LEFT_COUNT(){
	return left_enc_counter;
}

int ENCODERS_GET_RIGHT_COUNT(){
	return right_enc_counter;
}


#endif /*ENCODERS_MODULE*/
