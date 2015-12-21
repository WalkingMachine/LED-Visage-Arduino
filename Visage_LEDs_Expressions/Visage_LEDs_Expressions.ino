#include <Adafruit_NeoPixel.h>
#include <ros.h>
#include <std_msgs/UInt8.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS   81
#define EYEPIXELS  14
#define BASE_BOUCHE EYEPIXELS*2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 5; // delay for half a second

void emo_content()
{
  /*Émotion : Content*********************************************/
  eye_1(50,50,50);
  eye_2(50,50,50);
  //bouche_vide(); //Changer LED3 et LED45
  smile(50,50,50);
  delay(1000);
}

void emo_triste()
{
  /*Émotion : Triste*********************************************/
  bouche_vide();
  eye_1(0,0,50);
  eye_2(0,0,50);
  sad(0,0,50);
}

void emo_ciconspect()
{
  /*Émotion : Circonspect *********************************************/
  delay(1000);
  bouche_vide();
  eye_1(50,50,50);
  eye_2(50,50,50);
  bouche_fermee(50,50,50);
}

void emo_fache()
{
  /*Émotion : Faché*********************************************/
  delay(1000);
  bouche_vide();
  petite_bouche(50,0,0);
  eye_1(50,0,0);
  eye_2(50,0,0); 
  delay(1000);
}

void emo_surpris()
{
  /*Émotion : Surpris*********************************************/
  bouche_vide();
  eye_1(0,50,0);
  eye_2(0,50,0);
  grande_bouche(0,50,0);
  delay(1000);
  // photo();
}

void emo_coquin()
{
  /*Émotion : Coquin*********************************************/
  bouche_vide();
  eye_1(50,50,50);
  eye_2(50,50,50);
  smile(50,50,50);
  delay(500);
  eye_1(0,0,0);
  delay(500);
  eye_1(50,50,50);
  delay(500);
}

void emo_party()
{
  /*Émotion : Party*********************************************/
  eye_1(255,20,147);
  eye_2(255,20,147);
  bouche_fermee(255,20,147);
  delay(100);
  bouche_vide();
  eye_1(0,245,255);
  eye_2(0,245,255);
  petite_bouche(0,245,255);
  delay(100);
  bouche_vide();
  eye_1(127,255,0);
  eye_2(127,255,0);
  grande_bouche(127,255,0);
  delay(100);
  bouche_vide();
  theaterChase(pixels.Color(127, 127, 127), 100); // White
  theaterChase(pixels.Color(127, 0, 0), 100); // Red
  theaterChase(pixels.Color(0, 0, 127), 100); // Blue
}

void eye_1(uint8_t R,uint8_t G,uint8_t B){
for(int i=0; i<EYEPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  pixels.setPixelColor(i, pixels.Color(R,G,B)); 
  pixels.show();
  }
}

void eye_2(uint8_t R,uint8_t G,uint8_t B){
  for(int i=EYEPIXELS; i<EYEPIXELS*2; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
    pixels.show();
    }
  }

void smile(uint8_t R,uint8_t G,uint8_t B){ 
   pixels.setPixelColor(BASE_BOUCHE + 11, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 12, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 34, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 38, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 47, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 46, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 45, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 41, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 24, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 20, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 35, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 37, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 48, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 49, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 50, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 44, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 43, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 42, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 23, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 21, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 23, pixels.Color(R,G,B));
   pixels.show();
}

void sad(uint8_t R,uint8_t G,uint8_t B){ 
   pixels.setPixelColor(BASE_BOUCHE + 12, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 13, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 14, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 15, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 16, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 17, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 18, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 19, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 20, pixels.Color(R,G,B));
   pixels.show();
}

void bouche_vide(){
    for(int i=EYEPIXELS*2; i<NUMPIXELS; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); 
    pixels.show();
    }
  
  }

void petite_bouche(uint8_t R,uint8_t G,uint8_t B){
   pixels.setPixelColor(BASE_BOUCHE + 12, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 34, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 38, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 47, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 46, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 45, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 41, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 24, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 20, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 12, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 13, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 14, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 15, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 16, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 17, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 18, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 19, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 20, pixels.Color(R,G,B));
   pixels.show();
  }
void grande_bouche(uint8_t R,uint8_t G,uint8_t B){
   pixels.setPixelColor(BASE_BOUCHE + 1, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 2, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 3, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 4, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 5, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 6, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 7, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 8, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 9, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 11, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 35, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 37, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 48, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 49, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 50, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 44, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 43, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 42, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 23, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 21, pixels.Color(R,G,B));
   pixels.show();
  }

  void bouche_fermee(uint8_t R,uint8_t G,uint8_t B){
   pixels.setPixelColor(BASE_BOUCHE + 20, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 25, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 26, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 27, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 29, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 30, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 32, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 33, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 12, pixels.Color(R,G,B));
   pixels.show();
  }

  void photo(){
    for(int i=EYEPIXELS*2; i<NUMPIXELS; i++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,255,255)); 
    pixels.show();
    }
  }
  

  //Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, c);    //turn every third pixel on
      }
      pixels.show();

      delay(wait);

      for (int i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//void control_eye(const std_msgs::UInt8& emo){}
//void control_emo(const std_msgs::UInt8& emo){}

void control_emo(const std_msgs::UInt8& emo)
{
	switch (emo.data) 
	{
	    case 1:
	      emo_content();
	      break;
	    case 2:
	      emo_triste();
	      break;
	    case 3:
	      emo_ciconspect();
	      break;
	    case 4:
	      emo_fache();
	      break;
	    case 5:
	      emo_surpris();
	      break;
	    case 6:
	      emo_coquin();
	      break;
	    case 7:
	      emo_party();
	      break;
	    default:
	      emo_content();
	}
}

ros::NodeHandle nh;
//ros::Subscriber<std_msgs::uint8_t> subMouth("control_mouth", control_mouth );
//ros::Subscriber<std_msgs::uint8_t> subEye("control_eye", control_eye );
ros::Subscriber<std_msgs::UInt8> subEmo("control_emo", control_emo );

void setup() 
{
  // put your setup code here, to run once:
  pixels.begin(); // This initializes the NeoPixel library.

  nh.initNode();
  //nh.subscribe(subMouth);
  //nh.subscribe(subEye);
  nh.subscribe(subEmo);
}

void loop() 
{
  
nh.spinOnce();

}



