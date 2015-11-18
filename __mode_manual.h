//IR REMOTE COMMANDS AND LOGICS

				//MOVEMENT
				if (11 == IR_COMMAND){
					LEFT_SPEED = MODE1_SPEED;
					RIGHT_SPEED = MODE1_SPEED - 30;
					ROBI_FORWARD(LEFT_SPEED, RIGHT_SPEED);

						#ifdef TFT_MODULE
							if (PREV_IR_COMMAND != IR_COMMAND){
								TFT_PRINT_DIRECTION("FORWARD", 3);
								TFT_PRINT_SPEED(LEFT_SPEED, RIGHT_SPEED);}
						#endif
				}
				if (55 == IR_COMMAND){
					ROBI_BACK(75,75);

						#ifdef TFT_MODULE
							if (PREV_IR_COMMAND != IR_COMMAND){
							TFT_PRINT_DIRECTION(" BACK", 3);}
						#endif	
				}
				if (33 == IR_COMMAND) {
					ROBI_STOP();
						#ifdef TFT_MODULE
							if (PREV_IR_COMMAND != IR_COMMAND){
							TFT_PRINT_SPEED(0, 0);
							TFT_PRINT_DIRECTION(" STOP", 3);}
						#endif
				}
				if (44 == IR_COMMAND) {
						#ifdef TFT_MODULE
							if (PREV_IR_COMMAND != IR_COMMAND){
							TFT_PRINT_DIRECTION(" RIGHT", 3);}
						#endif
					ROBI_FORWARD(100,0);
				}
				if (22 == IR_COMMAND) {
						#ifdef TFT_MODULE
							if (PREV_IR_COMMAND != IR_COMMAND){
							TFT_PRINT_DIRECTION(" LEFT", 3);}
						#endif
					ROBI_FORWARD(0,100);
				}
