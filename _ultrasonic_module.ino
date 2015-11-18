#ifdef ULTRASONIC_MODULE

//=======INIT=====================================================================
//DISTANCE VARIABLES
int MAX_DISTANCE = 3000;
int MIN_DISTANCE = 10;
const int trigPin = A2;
const int echoPin = A1;
int dist_check1, dist_check2, dist_check3;
long duration, distance, distance_all;
int dist_result;
int dist_check_sum;


//=======FUNCTIONS================================================================

void ULTRASONIC_INIT(){
	
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

boolean ULTRASONIC_TEST(){

	digitalWrite(trigPin, 0);
	delayMicroseconds(2);
	digitalWrite(trigPin, 1);
	delayMicroseconds(10);
	digitalWrite(trigPin, 0);
	duration = pulseIn(echoPin, 1);
	distance = duration/58;

	if (distance > 0) {return true;}
	else return false;
}

int ULTRASONIC_1X_PING_2(){

	digitalWrite(trigPin, 0);
	delayMicroseconds(2);
	digitalWrite(trigPin, 1);
	delayMicroseconds(10);
	digitalWrite(trigPin, 0);
	duration = pulseIn(echoPin, 1);
	dist_result = duration/58;


		if (dist_result > MAX_DISTANCE) {return 3000;}
		else if(dist_result < 5){return 0;}
		else {return dist_result;}


}

long ULTRASONIC_1X_PING(){

	digitalWrite(trigPin, 0);
	delayMicroseconds(2);
	digitalWrite(trigPin, 1);
	delayMicroseconds(10);
	digitalWrite(trigPin, 0);
	duration = pulseIn(echoPin, 1);
	distance = duration/58;

		return distance; 

}

int ULTRASONIC_3X_PING(){                      //CHECK DISTANCE FUNCTION (3x)

	digitalWrite(trigPin, 0);
	delayMicroseconds(2);
	digitalWrite(trigPin, 1);
	delayMicroseconds(10);
	digitalWrite(trigPin, 0);
	duration = pulseIn(echoPin, 1);
	distance = duration/58;
  
	dist_check1 = distance;
  
	digitalWrite(trigPin, 0);
	delayMicroseconds(2);
	digitalWrite(trigPin, 1);
	delayMicroseconds(10);
	digitalWrite(trigPin, 0);
	duration = pulseIn(echoPin, 1);
	distance = duration/58;
  
	dist_check2 = distance;
  
	digitalWrite(trigPin, 0);
	delayMicroseconds(2);
	digitalWrite(trigPin, 1);
	delayMicroseconds(10);
	digitalWrite(trigPin, 0);
	duration = pulseIn(echoPin, 1);
	distance = duration/58;
  
	dist_check3 = distance;
  
	dist_check_sum = dist_check1 + dist_check2 + dist_check3;
	dist_result = dist_check_sum/3;

	return dist_result; 

}

#endif /*ULTRASONIC MODULE*/
