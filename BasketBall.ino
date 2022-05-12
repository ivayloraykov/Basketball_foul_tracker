// Home team
const int ledPin1 = 2; //   1 fall LED PIN
const int ledPin2 = 3; //   2 fall LED PIN
const int ledPin3 = 4; //   3 fall LED PIN
const int ledPin4 = 5; //   4 fall LED PIN
const int ledPin5 = 6; //   5 fall LED PIN
int homePins[] = {2,3,4,5,6};
const int buttonHome = 12; //   Button PIN
int buttonReadHome;
int ledFlagHome = 0;//   variable counter


// Guest Team
const int ledPin6 = 7; //   1 fall LED PIN
const int ledPin7 = 8; //   2 fall LED PIN
const int ledPin8 = 9; //   3 fall LED PIN
const int ledPin9 = 10; //   4 fall LED PIN
const int ledPin0 = 11; //   5 fall LED PIN
int guestPins[] = {7,8,9,10,11};
const int buttonGuest = 13; //   Button PIN
int buttonReadGuest; //   Button status on/off
int dt = 300;   //   delay time
int ledFlagGuest = 0; //   variable counter

void setup()
{
  // Home team
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(buttonHome, INPUT);

  // Guest Team
  Serial.begin(9600);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin0, OUTPUT);
  pinMode(buttonGuest, INPUT);
}


void loop()
{
  Serial.print("\nHomeBTN = ");Serial.print(buttonReadHome);
  Serial.print("\nGuestBTN = ");Serial.print(buttonReadGuest);

  int lastPressedHomeValue = 5;
  int lastPressedGuestValue = 5;
 
  if(digitalRead(buttonHome) == 0)
  {
    lastPressedHomeValue = 0;
    ledFlagHome++;
    Serial.print("\nledFlagHome after addition = ");Serial.print(ledFlagHome);
    if(ledFlagHome>5)
    {
      Serial.print("ledFlagHome inside the >5\n ");
      for (int i = 0; i < ledFlagHome; i++)
      {digitalWrite(homePins[i], LOW);}
      ledFlagHome=0;
      Serial.print("\nledFlagHome after zeroing = ");Serial.print(ledFlagHome);
    }
    else
    {
      for (int i = 0; i < ledFlagHome; i++)
      {digitalWrite(homePins[i], HIGH);}
    }           

     while(lastPressedHomeValue == digitalRead(buttonHome)){}
  }
  else if(digitalRead(buttonGuest) == 0)
  {
    lastPressedGuestValue = 0;
    ledFlagGuest++;
    Serial.print("\nledFlagGuest after addition = ");Serial.print(ledFlagGuest);
    if(ledFlagGuest>5)
    {
      Serial.print("ledFlagGuest inside the >5\n ");
      for (int i = 0; i < ledFlagGuest; i++)
      {digitalWrite(guestPins[i], LOW);}
      ledFlagGuest=0;
      Serial.print("\nledFlagGuest after zeroing = ");Serial.print(ledFlagGuest);
    }
    else
    {
      for (int i = 0; i < ledFlagGuest; i++)
      {digitalWrite(guestPins[i], HIGH);}
    }
    while(lastPressedGuestValue ==digitalRead(buttonGuest)){}        
  }
}
