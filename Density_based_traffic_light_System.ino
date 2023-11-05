/* Density Based traffic light System
 *  Author Dr. Rishabh Raj
 */


const int trigPin1 = 13;
const int trigPin2 = 3;
const int trigPin3 = 2;
const int trigPin4 = 9;
const int echoPin1 = 12;
const int echoPin2 = 11;
const int echoPin3 = 10;
const int echoPin4 = 4;
const int ledPinR1 = 8;
const int ledPinR2 = 7;
const int ledPinG1 = 6;
const int ledPinG2 = 5;

int dura1, dura2, dura3, dura4;
int dist1, dist2, dist3, dist4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(ledPinR1, OUTPUT);
  pinMode(ledPinR2, OUTPUT);
  pinMode(ledPinG1, OUTPUT);
  pinMode(ledPinG2, OUTPUT);
    
}
void readSen(){
 //data from ultrasonic sensor1 
  digitalWrite(trigPin1,LOW);
  delay(2);
  digitalWrite(trigPin1,HIGH);
  delay(10);
  digitalWrite(trigPin1,LOW);
  dura1= pulseIn(echoPin1,HIGH);
  dist1= dura1*0.034/2; //for right lane

  //data from ultrasonic sensor2 
  digitalWrite(trigPin2,LOW);
  delay(2);
  digitalWrite(trigPin2,HIGH);
  delay(10);
  digitalWrite(trigPin2,LOW);
  dura2= pulseIn(echoPin2,HIGH);
  dist2= dura2*0.034/2; //for right lane

  //data from ultrasonic sensor3 
  digitalWrite(trigPin3,LOW);
  delay(2);
  digitalWrite(trigPin3,HIGH);
  delay(10);
  digitalWrite(trigPin3,LOW);
  dura3= pulseIn(echoPin3,HIGH);
  dist3= dura3*0.034/2; //for right lane

  //data from ultrasonic sensor4 
  digitalWrite(trigPin4,LOW);
  delay(2);
  digitalWrite(trigPin4,HIGH);
  delay(10);
  digitalWrite(trigPin4,LOW);
  dura4= pulseIn(echoPin4,HIGH);
  dist4= dura4*0.034/2; //for right lane

  //Serial data.
  Serial.print(dist1);
  Serial.print(",");
  Serial.print(dist2);
  Serial.print(",");
  Serial.print(dist3);
  Serial.print(",");
  Serial.println(dist4);
}
void lowled(){
  digitalWrite(ledPinR1, HIGH);
  digitalWrite(ledPinR2, HIGH);
  digitalWrite(ledPinG1, LOW);
  digitalWrite(ledPinG2, LOW);
  delay(10);
}

void loop(){
  readSen();
  Serial.print(dist1);
  Serial.print(",");
  Serial.print(dist2);
  Serial.print(",");
  Serial.print(dist3);
  Serial.print(",");
  Serial.println(dist4);
  //MODE1 = vehicle in lane 1 and 2(left and right) and they are 
  //fewer vechicle in this lane 
  if(dist1<=25 & dist1>15 & dist2<=25 & dist2>15 & dist3>=25 & dist4>=25){
    //fewer obstacle in lane 1 and 2 + no obstacle in lane 3 and 4
  digitalWrite(ledPinR1, LOW);
  digitalWrite(ledPinR2, HIGH);
  digitalWrite(ledPinG1, HIGH);
  digitalWrite(ledPinG2, LOW);
  Serial.println("MODE1");
  //sufficient time for vehicle to pass
  delay(4000);
  lowled();
  }
//MODE2 = vehicle in lane 1 and 2(left and right) and they are 
  //more vechicle in this lane 
  else if(dist1<=15 & dist2<=15 & dist3>=25 & dist4>=25){
  //fewer obstacle in lane 1 and 2 + no obstacle in lane 3 and 4
  digitalWrite(ledPinR1, LOW);
  digitalWrite(ledPinR2, HIGH);
  digitalWrite(ledPinG1, HIGH);
  digitalWrite(ledPinG2, LOW);
  Serial.println("MODE2");
  //sufficient time for vehicle to pass
  delay(4000);
  lowled();
  }
//MODE1 = vehicle in lane 3 and 4(left and right) and they are 
  //fewer vechicle in this lane 
else if(dist1>=25 & dist2>=25 & dist3<=25 & dist3>15 & dist4>15 & dist4<=25){
   //fewer obstacle in lane 3 and 4 + no obstacle in lane 1 and 2
  digitalWrite(ledPinR1, HIGH);
  digitalWrite(ledPinR2, LOW);
  digitalWrite(ledPinG1, LOW);
  digitalWrite(ledPinG2, HIGH);
  Serial.println("MODE3");
  //more time for vehicle to pass away
  delay(8000);
  lowled();
  }
else if(dist1>=25 & dist2>=25 & dist3<=15 & dist4<=15){
   //more obstacle in lane 3 and 4 + no obstacle in lane 1 and 2
  digitalWrite(ledPinR1, HIGH);
  digitalWrite(ledPinR2, LOW);
  digitalWrite(ledPinG1, LOW);
  digitalWrite(ledPinG2, HIGH);
  Serial.println("MODE4");
  //more time for vehicle to pass away
  delay(8000);
  lowled();
  }
else(dist1>=25 & dist2>=25 & dist3>=25 & dist4>=25);{
  digitalWrite(ledPinR1, HIGH);
  digitalWrite(ledPinR2, HIGH);
  digitalWrite(ledPinG1, LOW);
  digitalWrite(ledPinG2, LOW);
  Serial.println("MODE5");
  delay(1000);
}
}


  
