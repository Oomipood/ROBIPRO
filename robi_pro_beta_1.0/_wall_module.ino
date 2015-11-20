#ifdef WALL_MODULE

#define LEFT_WALL_SENSOR 35
#define RIGHT_WALL_SENSOR 34

void WALL_MODULE_INIT(){
	pinMode(LEFT_WALL_SENSOR, INPUT);
	pinMode(RIGHT_WALL_SENSOR, INPUT);
}

byte WALL_MODULE_DETECT(){

	if (1 != digitalRead(LEFT_WALL_SENSOR) and 1 != digitalRead(RIGHT_WALL_SENSOR)){
		return 3;
	}

	else if (1 != digitalRead(LEFT_WALL_SENSOR)){
		return 1;
	}
	else if (1 != digitalRead(RIGHT_WALL_SENSOR)){
		return 2;
	}
	else {
		return 0;
	}


}

#endif /*WALL_MODULE*/
