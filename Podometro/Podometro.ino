#include <M5Stack.h>
#include <Adafruit_NeoPixel.h>
#include "utility/MPU9250.h"

#define M5STACK_FIRE_NEO_NUM_LEDS 10
#define M5STACK_FIRE_NEO_DATA_PIN 15
#define NOTE_DH2 661



float accX = 0.0F;  // Define variables for storing inertial sensor data
float accY = 0.0F;  
float accZ = 0.0F;
bool acqprima,stato=false, completo_calib = false;
float accelerazione, alpha = 0.85,filtered_acc = 0;
int numeroPassi=0;

//calibrazione
float total = 0;
int count;
float avg ;
float width ;
float step_length;
int giri;
float accTot=0;

// dimensioni schermo 
int alt, largh;




Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
    M5STACK_FIRE_NEO_NUM_LEDS, M5STACK_FIRE_NEO_DATA_PIN, NEO_GRB + NEO_KHZ800);



void step_counted()
{
    pixels.fill(pixels.Color(0, 7, 0));// colora verde i led
    M5.Lcd.fillScreen(GREEN);// cambia colore display
    pixels.show();
    delay(100);
    pixels.fill(pixels.Color(0, 0, 0));// colora bianco i led
    pixels.show();
    M5.Lcd.fillScreen(BLACK);
}

void calib_completata ()
{
        avg = total / count;
        width = avg / 7;
        total = avg;
        M5.Speaker.tone(NOTE_DH2);
        delay(1000);
        M5.Speaker.end();
        completo_calib = true;
        Serial.println("calib completata");
}

void setup() {
    M5.begin();        // Init M5Core.
    M5.Power.begin(); 
    pixels.begin(); 
    M5.IMU.Init();  // Init IMU sensor.  
    M5.Lcd.fillScreen(BLACK);  // Set the screen background color to black.
    M5.Lcd.setTextColor(GREEN, BLACK);  // Sets the foreground color and background color of the
    M5.Lcd.setTextSize(6);  // Set the font size.
    //M5.Speaker.setVolume(11);
}
double low_pass_filter(double prev_value,double new_value) {
    return alpha * prev_value + (1 - alpha) * new_value;
}

void loop()
 {
    M5.IMU.getAccelData(&accX, &accY,&accZ);  // Stores the triaxial accelerometer. 
    accelerazione= sqrt((accX)*(accX)+ (accY)*(accY) +(accZ)*(accZ));
    accTot+=accZ;
    giri +=1;
    float mean=accTot/giri;

    //step_length=0.98*pow(mean,1/3);
    //Serial.println(step_length);
    if(giri >2){
    filtered_acc = low_pass_filter(filtered_acc, accelerazione);
    Serial.println(filtered_acc);}
    //Serial.println(accelerazione);
    // Calibration for average acceleration.
      if (count < 1000) 
      {
        total += accelerazione;
        count += 1;
        //Serial.println(count);
      } 
      else if(count >= 1000 && completo_calib == false)
      {
        calib_completata();
      }
     if(accelerazione>avg+width && completo_calib)
     {
       stato=true;
       acqprima=stato;
     }
     if(accelerazione<avg+width && completo_calib){
       stato=false;
     }
    
     if(stato == false && acqprima == true && completo_calib)
     {
       numeroPassi +=1;
       step_counted();
       acqprima = false;
     }
     M5.Lcd.setCursor((int)(M5.Lcd.width()/2)-155, (int)(M5.Lcd.height()/2)-25);
     M5.Lcd.printf("%5i" ,numeroPassi);
     // after the calibration, starts to wait 0.1 seconds for each cycle.
     //this allows 10 checks for each second, 
     if (completo_calib == true)
     {
     delay(100);
     }
 }