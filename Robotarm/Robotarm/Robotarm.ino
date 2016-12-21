/*
 Name:		Robotarm.ino
 Created:	12/19/2016 12:59:28 PM
 Author:	Maxsimilian Schmitt-Egenolf

 important links: http://playground.arduino.cc/ComponentLib/Servo
*/

#include <math.h>
#include <Servo.h>
using namespace std;
double l;     // holds the length  
double buttonL;
double h;     // holds the heigth 
double buttonH;
double hypotenuse;
double v1; // holds the angle fot the first v
double v2; // holds the angle fot the secand v
double v3; // holds the angle of the claw
int savedH;
int clawInput;
#define _USE_MATH_DEFINES
#define M_PI  3.14159265358979323846  /*  PI  π  */
#define get_degrees 180 / M_PI        /*  translate radians to degrees  */
Servo shoulderServo;   // this servo holds the angle v1
Servo elbowServo;      // v2
Servo clawServo;       // v3

// the setup function runs once when you press reset or power the board
void setup() {
	shoulderServo.attach(1);  // attaches serväo to pin (x)
	elbowServo.attach(2);
	clawServo.attach(3);


// the loop function runs over and over again until power down or reset
void loop() {
    // get buttonstates and valeaues from x-controller
	/*
	if (true) {

	}else if (true) {
		savedH = read();
	}else if (true) {

	}
	*/

	// make new l / h with c-controlller valeaues
	h = h + buttonH;
	l = l + buttonL;
	// if button gets pressed get new mode for claw

	// calculate new angles for the robotarm
	hypotenuse = sqrt(l*l + h*h);
	v2 = (2 * asin(hypotenuse / 40)) * get_degrees;
	v1 = ((180 - v2) / 2) + ((asin(l / hypotenuse))) * get_degrees;
	v3 = v3 + clawInput;
	
	// digitalprint new angles to 1st and 2nd-servo
	shoulderServo.write(v1);
	elbowServo.write(v2);
	clawServo.write(v3);
}