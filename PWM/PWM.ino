byte PWM_PIN_TURN = 14;
byte PWM_PIN_TRANS = 15;
#define LED_PIN 13

int pwm_value_turn;
int pwm_value_trans;
int pvturn;
int pvtrans;

#include <Wire.h>
#include <ZumoShield.h>

ZumoMotors motors;

 
void setup() {
  pinMode(PWM_PIN_TURN, INPUT);
  pinMode(PWM_PIN_TRANS, INPUT);
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}
 
void loop() {


  // run left motor forward
  //digitalWrite(LED_PIN, HIGH);


  pwm_value_turn = pulseIn(PWM_PIN_TURN, HIGH);
  pwm_value_trans = pulseIn(PWM_PIN_TRANS, HIGH);


  pvturn = map(pwm_value_turn, 900, 2000, -400, 400);
  pvtrans = map(pwm_value_trans, 900, 2000, -400, 400);

  Serial.println(pvtrans);
  Serial.println(pvturn);
  motors.setRightSpeed(-pvtrans - pvturn);
  motors.setLeftSpeed(-pvtrans + pvturn);
  /*
  if(pvturn > 0){
    motors.setRightSpeed(pvturn);
    motors.setLeftSpeed(-1*pvturn);
  }
  else{
    motors.setLeftSpeed(-1 * pvturn);
    motors.setRightSpeed(pvturn);
  }
  if(pvtrans > 0){
    motors.setRightSpeed(-1*pvtrans);
    motors.setLeftSpeed(-1*pvtrans);
  }
  else{
    motors.setLeftSpeed(-1*pvtrans);
    motors.setRightSpeed(-1*pvtrans);
  }
  //motors.setLeftSpeed(0);
 // motors.setRightSpeed(0);
  //exit(0);
  */

}
