const int soundout            = 4;
const int vibro               = 12;
int randnum                   = 0;
unsigned long currentMillis   = 0; 
unsigned long previousMillis  = 0;
int randNumber                = 0;
int   voltage                 = 0;
int sensorValue               = 0;
int UVIndex                   = 0;
const long interval           = 1000;  
const int UV                  = A0; 

void setup() {
  Serial.begin(9600);
  pinMode(UV, INPUT);
  pinMode(vibro,OUTPUT);
  pinMode(soundout, OUTPUT);
//######## power on beep 
digitalWrite(vibro,HIGH);
tone(soundout, 500,50);
delay(500);
noTone(soundout);
digitalWrite(vibro, LOW);
//######## end beep   
}


void stalker_beep(){
  for(int i=0; i <= 1; i++){ 
tone(soundout, 500,50);
delay(200);
noTone(soundout); 
  }
}

void loop() {
  unsigned long currentMillis = millis();
  sensorValue = analogRead(UV); 
 int voltage = (sensorValue * (6.5 / 1023.0))*1000;
 // int Voltage = sensorValue/1024*5.0;
// int UV_index = sensorValue *.1;
  
   if(voltage<50)
  {
    randnum = 1250;
    UVIndex = 0;
  }else if (voltage>50 && voltage<=227)
  {
    randnum = 1250;
    UVIndex = 0;
  }else if (voltage>227 && voltage<=318)
  {
    randnum = 750;
    UVIndex = 1;
  }
  else if (voltage>318 && voltage<=408)
  {
    randnum = 700;
    UVIndex = 2;
  }else if (voltage>408 && voltage<=503)
  {
    randnum = 650;
    UVIndex = 3;
  }
  else if (voltage>503 && voltage<=606)
  {
    randnum = 600;
    UVIndex = 4;
  }else if (voltage>606 && voltage<=696)
  {
    randnum = 550;
    UVIndex = 5;
  }else if (voltage>696 && voltage<=795)
  {
    randnum = 300;
    UVIndex = 6;
  }else if (voltage>795 && voltage<=881)
  {
    randnum = 300;
    UVIndex = 7;
  }
  else if (voltage>881 && voltage<=976)
  {
    randnum = 150;
    UVIndex = 8;
  }
  else if (voltage>976 && voltage<=1079)
  {
    randnum = 150;
    UVIndex = 9;
  }
  else if (voltage>1079 && voltage<=1170)
  {
    randnum = 100;
    UVIndex = 10;
  }else if (voltage>1170)
  {
    randnum = 100;
    UVIndex = 11;
  }

if(UVIndex >= 8){stalker_beep(); digitalWrite(vibro,HIGH);} else { digitalWrite(vibro,LOW);}


//Serial.println("Sensor = " + String(sensorValue));
//Serial.println("Volt = " + String(Voltage));
Serial.println("UV = " + String(UVIndex));

if (currentMillis - previousMillis >  randNumber  ){      
        
      if(UVIndex != 0){
        int ranNumVol = random (255);
        digitalWrite(soundout, HIGH);
        randNumber = random(randnum);
        digitalWrite(soundout, LOW); }
        previousMillis = currentMillis; 
       
      } else {
       digitalWrite(soundout, LOW); 
      }
}
