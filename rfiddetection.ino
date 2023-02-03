#include <SPI.h>
#include <MFRC522.h>



#define SS_PIN 10
#define RST_PIN 9
//int ex=5;
int GREEN = 4;  // red wire
int YELLOW = 3; //blue wire
int RED = 2;  //blACK wire

int GREEN1 = 7;  // red wire
int YELLOW1 = 6; //blue wire
int RED1 = 5;  //blACK wire

int DELAY_GREEN = 10000;
int DELAY_YELLOW = 3000;
int DELAY_RED = 10000;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  pinMode(GREEN1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(RED1, OUTPUT);
  
 
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}

void loop() 
{
   red_light();

   if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "7C 26 C9 6D") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Suramya Deshpande, MH31 AZ5544");
    Serial.println();
    delay(3000);
  }
 
 else if(content.substring(1) == "6C 93 DA 6E"){
    Serial.println("Arihant Rode, MH31 AJ2254");
    delay(3000);
  }
  else 
  {
     Serial.println("Jethalal Gada, MH31 AJ6969");
    delay(3000);
  }
   
  delay(DELAY_RED);
  yellow_light();
  delay(DELAY_YELLOW);
  green_light();
  delay(DELAY_GREEN);
  // Look for new cards

}
void green_light()
{

  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);

  digitalWrite(RED1, HIGH);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(GREEN1, LOW);
}

void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);

  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, HIGH);
  digitalWrite(RED1, LOW);
}

void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);

  digitalWrite(GREEN1, HIGH);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, LOW);
}

 
