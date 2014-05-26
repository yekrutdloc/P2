//Local variables
double reLM_Setpoint = 8;
double reLM_Output;

//Specify the links and initial tuning parameters
PID reLM_PID(preLM_PIDInput, &reLM_Output, &reLM_Setpoint, 17, 0, 0, DIRECT);

// Pin for motor
const int reLM_Pin = 4;

static void Thread5(void *arg) {
	//START of one-run setup program

	//turn the PID on
	reLM_PID.SetMode(AUTOMATIC);

	//Setup PID
	//frLM_PID.SetSampleTime(100);
	reLM_PID.SetControllerDirection(REVERSE);
	reLM_PID.SetOutputLimits(0, 140);

	//Setup motor pin
	pinMode(reLM_Pin, OUTPUT);

	//END of one-run setup program
	while (1){ //Start of infinite loop for thread
		reLM_PID.Compute();
		analogWrite(reLM_Pin, reLM_Output);
	} //END of infinite loop for thread
}

