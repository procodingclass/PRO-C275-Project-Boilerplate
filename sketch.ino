#include <IRremote.h>

//frequencies of musical notes
const int c=262;
const int d=294;
const int e=330;
const int f=349;
const int g=392;
const int a=440;
const int b=494;
const int C=523;

//add receiver pin for IR receiver here 
const byte recv_pin=;

const byte buzzer_pin=10;

//initiate the IR receiver


void setup() {

  Serial.begin(9600);

  //write code to enable the IR receiver here
  


  pinMode(buzzer_pin, OUTPUT);

}

void loop() {

  if(receiver.decode()){

    //write code to store the decoded IR receiver data in response variable
    int response=
    Serial.println(response);

    // map the keys 1-8 with the following notes
    //example for key 1 is given below. Complete the rest.
    if(response==48) play_tone(c);
    else if(response==  ) play_tone(d);
    else if(response==  ) play_tone(e);
    else if(response==  ) play_tone(f);
    else if(response==  ) play_tone(g);
    else if(response==  ) play_tone(a);
    else if(response==  ) play_tone(b);
    else if(response==  ) play_tone(C);
    else receiver.resume();

  }
  
}

void play_tone(int pitch){

  /*The enableIRIn() and tone() function uses the 
  same timer. 
  
  This causes problems and the tone() function
  does not work properly when the IR receiver is enabled.

  So, we disable the IR receiver before 
  using the tone() function*/

  receiver.disableIRIn();

  tone(buzzer_pin , pitch);
  delay(300);
  noTone(buzzer_pin);

  /* After the tone() functions task is comepleted, 
  we enable the IR receiver again so that it can detect 
  the next signal*/

  receiver.enableIRIn();
}
