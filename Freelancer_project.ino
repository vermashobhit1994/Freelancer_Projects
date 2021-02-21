


#include<MFRC522.h>

/* Change according to your board . Here I am assuming that I am using Arduino UNO board */
#define RFID_MOSI_PIN_NO    11
#define RFID_MISO_PIN_NO    12
#define RFID_SS_PIN_NO      10
#define RFID_SCK_PIN_NO     13
#define RFID_RST_PIN_NO     9

//create an object of MFRC522 library
MFRC522 mfrc522(RFID_SS_PIN_NO, RFID_RST_PIN_NO);   // Create MFRC522 instance.

/* If using the L293D then high the motor pin ENABLE */
#define MOTOR1_PIN1         1
#define MOTOR1_PIN2         2

#define MOTOR2_PIN1         3
#define MOTOR2_PIN2         4

#define MOTOR3_PIN1         5
#define MOTOR3_PIN2         6

#define MOTOR4_PIN1         7
#define MOTOR4_PIN2         8


/* Consider that you are using the IR module */
/* Program that will move the motor on black line and if RFID card is detected then stop for some time and then move again until the next 
 *  card is being detected
 */

#define IR_LED_LEFT_PIN_OUT     14
#define IR_LED_RIGHT_PIN_OUT    15

//INitialize the array to store the RFID card No 
byte NUID_RFID[4];

//motor functions
//Here we are assuming that 4 motors are connected.
#define MOTOR1_FORWARD     digitalWrite(MOTOR1_PIN1, 1);digitalWrite(MOTOR1_PIN2, 0); 
#define MOTOR1_BACKWARD    digitalWrite(MOTOR1_PIN1, 0);digitalWrite(MOTOR1_PIN2, 1);
#define MOTOR1_STOP        digitalWrite(MOTOR1_PIN1, 0);digitalWrite(MOTOR1_PIN2, 0);


#define MOTOR2_FORWARD     digitalWrite(MOTOR2_PIN1, 1);digitalWrite(MOTOR2_PIN2, 0); 
#define MOTOR2_BACKWARD    digitalWrite(MOTOR2_PIN1, 0);digitalWrite(MOTOR2_PIN2, 1);
#define MOTOR2_STOP        digitalWrite(MOTOR2_PIN1, 0);digitalWrite(MOTOR2_PIN2, 0);


#define MOTOR3_FORWARD     digitalWrite(MOTOR3_PIN1, 1);digitalWrite(MOTOR3_PIN2, 0); 
#define MOTOR3_BACKWARD    digitalWrite(MOTOR3_PIN1, 0);digitalWrite(MOTOR3_PIN2, 1);
#define MOTOR3_BACKWARD    digitalWrite(MOTOR3_PIN1, 0);digitalWrite(MOTOR3_PIN2, 0);

#define MOTOR4_FORWARD     digitalWrite(MOTOR4_PIN1, 1);digitalWrite(MOTOR4_PIN2, 0); 
#define MOTOR4_BACKWARD    digitalWrite(MOTOR4_PIN1, 0);digitalWrite(MOTOR4_PIN2, 1);
#define MOTOR4_BACKWARD    digitalWrite(MOTOR4_PIN1, 0);digitalWrite(MOTOR4_PIN2, 0);






void setup() {
  // put your setup code here, to run once:

  //setting the mode of IR LED
  pinMode(IR_LED_LEFT_PIN_OUT, INPUT);
  pinMode(IR_LED_RIGHT_PIN_OUT, INPUT);

  //setting the mode of Motor
  pinMode( MOTOR1_PIN1, OUTPUT);
  pinMode( MOTOR1_PIN2, OUTPUT);
  pinMode( MOTOR2_PIN1, OUTPUT);
  pinMode( MOTOR2_PIN2, OUTPUT);
  pinMode( MOTOR3_PIN1, OUTPUT);
  pinMode( MOTOR3_PIN2, OUTPUT);
  pinMode( MOTOR4_PIN1, OUTPUT);
  pinMode( MOTOR4_PIN2, OUTPUT);


  //setting the RFID
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 


  

  
  

  
  
    
  
}

void loop() {
  // put your main code here, to run repeatedly:

  
  //If high on both the sensor pins then move forward all the motors
  if( digitalRead(IR_LED_LEFT_PIN_OUT) && digitalRead(IR_LED_RIGHT_PIN_OUT))
  {
      MOTOR1_FORWARD;
      MOTOR2_FORWARD;
      MOTOR3_FORWARD;
      MOTOR4_FORWARD;
  }
  //turn right 
  if( !digitalRead(IR_LED_LEFT_PIN_OUT) && digitalRead(IR_LED_RIGHT_PIN_OUT))
  {
    MOTOR1_STOP;
    MOTOR3_FORWARD;
    MOTOR2_FORWARD;
    MOTOR4_STOP;
  }

//turn left
  if( digitalRead(IR_LED_LEFT_PIN_OUT) && !digitalRead(IR_LED_RIGHT_PIN_OUT))
  {
    MOTOR1_FORWARD;
    MOTOR3_STOP;
    MOTOR2_STOP;
    MOTOR4_FORWARD;
  }
  //RFID reader logic 
  
}
