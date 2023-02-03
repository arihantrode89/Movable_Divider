
#include<Servo.h>

//for IR sensors
int IR1=2;
int IR2=4;
int IR3=3;
int IR4=5;
int IR5=6;
int IR6=7;
int IR7=8;
int IR8=9;



//for Motor
int IN1=11;
int IN2=12;
int EN=10;

//lane 1
int count=0;
bool found=false;
bool gone=false;
bool found1=false;
bool gone1=false;
bool lane1=false;

//lane2
int count1=0;
bool found2=false;
bool gone2=false;
bool found3=false;
bool gone3=false;
bool lane2=false;

//motor
int motor = 10;
bool rotate =false;
Servo serv;



void setup() {
  // put your setup code here, to run once:
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);
  pinMode(IR5,INPUT);
  pinMode(IR6,INPUT);
  pinMode(IR7,INPUT);
  pinMode(IR8,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(EN,OUTPUT);
//  pinMode(S1,OUTPUT);
//  pinMode(S2,OUTPUT);
  Serial.begin(9600);
  
}



void loop() {

 
  // put your main code here, to run repeatedly:
  int v1 =  digitalRead(IR1);
  int v2 = digitalRead(IR2);
  int v3 = digitalRead(IR3);
  int v4 = digitalRead(IR4);
  int v5 =  digitalRead(IR5);
  int v6 = digitalRead(IR6);
  int v7 = digitalRead(IR7);
  int v8 = digitalRead(IR8);
  digitalWrite(10,HIGH);
  Irfunc(v1,v2,v3,v4,v5,v6,v7,v8);
  
  
 }

int Irfunc(int val1,int val2,int val3,int val4,int val5,int val6,int val7,int val8){
  
 // first two things for road starting
 
  if (val1 == 1 && found==false){
    count+=1;
    found=true;
    Serial.println(count);
  }
  else if(val1==0 && found==true){
    found=false;
  }

  if (val3 == 1 && found1==false){
    count+=1;

    
    found1=true;
    Serial.println(count);
  }
  else if(val3 ==0 && found1==true){
    found1=false;
  }


  //below functinallity for ending IR's
  if (val2==1 and gone==false){
    count-=1;
    gone=true;
    Serial.println(count);
  }
  else if(val2==0 and gone==true){
    gone=false;
  }

  if (val4==1 and gone1==false){
    count-=1;
    gone1=true;
    Serial.println(count);
  }
  else if(val4==0 and gone1==true){
    gone1=false;
  }


  // 2nd lane code

  if (val5 == 0 && found2==false){
    count1+=1;
    found2=true;
    Serial.println(count1);
  }
  else if(val5==1 && found2==true){
    found2=false;
  }

  if (val6 == 0 && found3==false){
    count1+=1;
    found3=true;
    Serial.println(count1);
  }
  else if(val6 ==1 && found3==true){
    found3=false;
  }


  //below functinallity for ending IR's
  if (val7==1 and gone2==false){
    count1-=1;
    gone2=true;
    Serial.println(count1);
  }
  else if(val7==0 and gone2==true){
    gone2=false;
  }

  if (val8==0 and gone3==false){
    count1-=1;
    gone3=true;
    Serial.println(count1);
  }
  else if(val8==1 and gone3==true){
    gone3=false;
  }
  
  movement(count,count1);
  
}


int movement(int count,int count1){
  if (count>8 || count1>8){
    
//    Serial.println(111);
    if (count>count1 and lane2==false){
      
          //shift towards lane2
          digitalWrite(IN1,HIGH) ;
          digitalWrite(IN2,LOW) ;
          analogWrite(EN,300);
          lane2=true;
          lane1=false;
          delay(3000);
          digitalWrite(IN1,LOW) ;
          digitalWrite(IN2,LOW);
      }
    else if(count<count1 and lane1==false){
      //shift towards lane1
          digitalWrite(IN1,LOW) ;
          digitalWrite(IN2,HIGH);
          analogWrite(EN,300);
          lane1=true;
          lane2=false;
          delay(3000);
          digitalWrite(IN1,LOW) ;
          digitalWrite(IN2,LOW);
      }    
    }
  return 0;
 }
