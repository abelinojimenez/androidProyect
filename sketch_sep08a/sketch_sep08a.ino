int directiony=A7;
int directionx=A6;
int switchbutton=2;
void setup() {
  pinMode(directiony,INPUT);
  pinMode(directionx,INPUT);
  pinMode(switchbutton,INPUT);

  for(int i=12;i>=9;i--)pinMode(i,OUTPUT);
  for(int i=6;i>=3;i--)pinMode(i,OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
 float val_y=analogRead(directionx);
 float val_x=analogRead(directiony);
 int  val_switch=digitalRead(switchbutton);

if(val_switch==1){
  digitalWrite(12,HIGH);
  delay(100);
  digitalWrite(12,LOW);
  }


if(val_x<500){
 
  digitalWrite(6,LOW);
  digitalWrite(4,LOW);
 digitalWrite(3,HIGH);
 }else if(val_x>600){
  digitalWrite(6,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
 }else{
  digitalWrite(6,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  }

if(val_y<500){
 
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
 }else if(val_y>600){
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
 }else{
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  }


  
  
 /*Serial.print("value x = ");
 Serial.println(val_x);
 Serial.print("value y = ");
 Serial.println(val_y);*/
 Serial.print("state button = ");
 Serial.println(val_switch);
// Serial.println("-----------------------------------------------------");
 

}
