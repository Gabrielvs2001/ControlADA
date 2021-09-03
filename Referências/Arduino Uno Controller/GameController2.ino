
int xaxis;
int yaxis;
int strafe;
int forwardbackward;
int rxaxis;
int ryaxis;
int b1 = 12;
int b2 = 11;
int b3 = 10;
int b4 = 9;
int b5 = 8;
int b6 = 7;
int b7 = 6;
int b8 = 5;
int b9 = 4;
int b10 = 3;
int deadzone=100;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(b1,INPUT_PULLUP);
pinMode(b2,INPUT_PULLUP);
pinMode(b3,INPUT_PULLUP);
pinMode(b4,INPUT_PULLUP);
pinMode(b5,INPUT_PULLUP);
pinMode(b6,INPUT_PULLUP);
pinMode(b7,INPUT_PULLUP);
pinMode(b8,INPUT_PULLUP);
pinMode(b9,INPUT_PULLUP);
pinMode(b10,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.print("a");

xaxis = analogRead(A0); //set xaxis integer equal to the analog input signal from analog pin 0
xaxis = map(xaxis,0,1023,200,-200); //remap xaxis integer
if(xaxis>deadzone){ //if xaxis integer is greater than the minimum threshold for movement (deadzone) then set strafe to 2
  strafe = 2;
}
if(xaxis<-deadzone){ //if xaxis integer is less than the minimum threshold for movement (deadzone) then set strafe to 1
  strafe = 1;
}
if(xaxis<deadzone && xaxis>-deadzone){ //if xaxis integer is between the movement thresholds (in the deadzone) then set strafe equal to 0
  strafe = 0;
}
Serial.print(strafe);

yaxis = analogRead(A1);
yaxis = map(yaxis,0,1023,-200,200);
if(yaxis>deadzone){
  forwardbackward = 2;
}
if(yaxis<-deadzone){
  forwardbackward = 1;
}
if(yaxis<deadzone && yaxis>-deadzone){
  forwardbackward = 0;
}
Serial.print(forwardbackward);


Serial.print("b");

rxaxis = analogRead(A2);
rxaxis = map(rxaxis,0,1023,0,8);
Serial.print(rxaxis);

ryaxis = analogRead(A3);
ryaxis = map(ryaxis,0,1023,0,8);
Serial.print(ryaxis);

Serial.print("c");

if(digitalRead(b1)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

if(digitalRead(b2)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

Serial.print("d");

if(digitalRead(b3)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

if(digitalRead(b4)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

Serial.print("e");

if(digitalRead(b5)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

if(digitalRead(b6)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

Serial.print("f");

if(digitalRead(b7)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

if(digitalRead(b8)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

Serial.print("g");

if(digitalRead(b9)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

if(digitalRead(b10)==LOW)
{Serial.print("1");}
else {Serial.print("0");}

Serial.println();
delay (10);

}
