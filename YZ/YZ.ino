// connect motor controller pins to Arduino digital pins
// motor one

const int limitswitchY = 2;

int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
//int enB = 5;
int in3 = 7;
int in4 = 6;

int in5 = 12;
//int enC = 11;
int in6 = 13;
String reader;
void setup()
{
  Serial.begin(9600);
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  //pinMode(enC, OUTPUT);
  //pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(limitswitchY, INPUT);
  
  digitalWrite(limitswitchY, LOW);
}
void MoveXleft(){
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  
  //analogWrite(enC,255);
  delay(3000);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
}
void MoveXright(){
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  //analogWrite(enC,255);
  delay(3000);
  digitalWrite(in5,LOW);
  digitalWrite(in6,LOW);
}
void MoveYup()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(500);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}
void MoveYdown()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(500);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}
void MoveYmaxDown()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  do{
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }while(digitalRead(limitswitchY) == HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}
void MoveYmaxUp()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  do{
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }while(digitalRead(limitswitchY) == HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}
void MoveTrayFront()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 48);
  delay(1500);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);   
  //delay(1500);
}

void MoveTrayBack()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 48);
  delay(1500);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);   
  //delay(1500);
}
void demoTwo()
{
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
  // by your hardware
  // turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
 // digitalWrite(in3, LOW);
  //digitalWrite(in4, HIGH); 
  // accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    //analogWrite(enB, i);
    delay(20);
  } 
  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    //analogWrite(enB, i);
    delay(20);
  } 
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);  
}
void loop()
{
  reader = Serial.readString();
  Serial.println(reader);
  if(reader == "0"){
    MoveTrayFront();
  }else if(reader == "1"){
    MoveTrayBack(); 
  }else if(reader == "2"){
    
    MoveYdown();
  }else if(reader == "3"){
    MoveYup();
  }else if(reader == "4"){
    for(int i =0;i<5;i++){
      MoveYdown();
    }
  }else if(reader == "5"){
    for(int i =0;i<5;i++){
      MoveYup();
    }
  }else if(reader=="6"){
    MoveXleft();
  }else if(reader =="7"){
    MoveXright();
  }else if(reader == "8"){
    MoveYmaxDown();
  }else if(reader == "9"){
    MoveYmaxUp();
  }
  //exit(0);
  //demoTwo();
  //delay(1000);
}
