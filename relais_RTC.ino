#include <RTClib.h>
RTC_DS3231 rtc;

#define SUNDAY    0
#define MONDAY    1
#define TUESDAY   2
#define WEDNESDAY 3
#define THURSDAY  4
#define FRIDAY    5
#define SATURDAY  6

bool isActif=false;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(5, OUTPUT);
 digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW   
 
   Serial.begin(9600);

  if (! rtc.begin()) {
  Serial.println("Couldn't find RTC"); 
  while (1);
  }

 // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
   // manually sets the RTC with an explicit date & time, for example to set
  // January 21, 2021 at 3am you would call:
  // rtc.adjust(DateTime(2022, 10, 19, 20, 14, 00));
}

// the loop function runs over and over again forever
void loop() {

delay(500);
  DateTime now = rtc.now();
   Serial.print("Date & Time: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(now.dayOfTheWeek());
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.println(now.second(), DEC);

    if(isActif==false && (now.day()==MONDAY || now.day()==WEDNESDAY|| now.day()==SATURDAY))
    {    
      isActif=true;

     digitalWrite(5, HIGH);    // turn the LED off by making the voltage LOW  
      delay(5000);                // wait for a second
     digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW      
    }
    
    if(isActif==true && now.day()!=MONDAY && now.day()!=WEDNESDAY && now.day()!=SATURDAY)
    {    
      isActif=false;
    }
       
}
