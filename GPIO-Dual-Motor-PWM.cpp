//Mark Scheidker dual PWM DC motor controller, including gpio implementation

#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

void pulseMotors(int, int, unsigned int, unsigned int);

int main()
{
	
	int pwmSpeed1, pwmSpeed2, countdown_0;
	unsigned int usecs = 2, pulses = 1;
	
	wiringPiSetup();     
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);

	cout<<"-100 - 100: "; //this is all driver code to manually test the pwm logic
	cin>>pwmSpeed1;
	cout<<"-100 - 100: ";
	cin>>pwmSpeed2;
	cout<<endl<<endl;
	
	if(pwmSpeed1 < -100 || pwmSpeed1 > 100 || pwmSpeed2 < -100 || pwmSpeed2 > 100)
	{
		cout<<"pick a valid option"<<endl;
		return 0;
	}

	while(1) //main control loop,
	{		
    		pulseMotors(pwmSpeed1, pwmSpeed2, usecs, pulses); //send motor power pulse to motors
	}	
	return 0;	
}


//motor1 and motor2 = speed and direction of either motor 
//usecs = time between pulses
//pulses = number of pwm pulses sent per function call 
void pulseMotors(int motor1, int motor2, unsigned int usecs, unsigned int pulses)
{
	for(int x = 0; x < pulses; x++ )
	{
		if(motor1 > 0){                   //setup initial conditions before each pwm cycle
		//cout<<"+motor1 true"<<endl;
      		digitalWrite(0,1);
      		digitalWrite(1,0);
			
		}else if(motor1 < 0){
		//cout<<"-motor1 true"<<endl;
      		digitalWrite(0,0);
      		digitalWrite(1,1);	
				
		}else{
		//cout<<"motor1 false"<<endl;	
      		digitalWrite(0,0);
      		digitalWrite(1,0);	
		}
		
		if(motor2 > 0){                
		//cout<<"+motor1 true"<<endl;
      		digitalWrite(3,1);
      		digitalWrite(4,0);
			
		}else if(motor2 < 0){
		//cout<<"-motor1 true"<<endl;
      		digitalWrite(3,0);
      		digitalWrite(4,1);	
				
		}else{
		//cout<<"motor1 false"<<endl;	
     		digitalWrite(3,0);
      		digitalWrite(4,0);	
		}
		
		for(int i = 1 ; i < 100 ; i++) //subdivision of each pulse
		{
			//motor 1
			if(motor1 >= 0) //positive (or zero)
			{
				if(i == motor1){
					//cout<<"+motor1 false"<<endl;
          			digitalWrite(0,0);				
				}

			}else{   //negative
			
				if(i == abs(motor1)){
					//cout<<"-motor1 false"<<endl;
         			digitalWrite(1,0);
				}
			}
					
			//motor 2
			if(motor2 >= 0) //positive (or zero)
			{
				if(i == motor2){
					//cout<<"+motor2 false"<<endl;
          			digitalWrite(3,0);				
				}

			}else{   //negative
			
				if(i == abs(motor2)){
					//cout<<"-motor2 false"<<endl;
          			digitalWrite(4,0);
				}
			}
			usleep(usecs);		
		}	
	}			
}
