#include <Adafruit_NeoPixel.h>
#include <ros.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/String.h>


#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS   81
#define EYEPIXELS   14
#define BASE_BOUCHE EYEPIXELS*2

#define DEFAULT_BRIGHTNESS 75



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 5; // delay for half a second
int luminosite = 1;
int mode = 1; // 0 = wait, 1 = start, 2 = loading, 3 = green, 4 = yellow, 5 = red, 6 = wait for answer
bool talking = false;

void openFade()
{
  for(int i = 0; i < 60; i++)
  {
    for(int oeil = 0; oeil < EYEPIXELS*2; oeil++)
    {
      pixels.setPixelColor(oeil, pixels.Color(i,i,i));
    }  
    pixels.show();
    delay(20);
    smile(i,i,i);
    pixels.show();
  }  
  delay(1000);
}

// Fonction animation bouche en fonction des voyelles
// Non-fonctionnelle
void talk2(const std_msgs::String& word)
{
  String phrase = "";

  if(!talking)
  {
    talking = true;
    
    int nbWords = 1;
    
    // const char* to string
    for(int i=0; i<strlen(word.data);i++)
    {
      phrase += word.data[i];
    }
    
    boolean findSpace = false;
    int index = 0;
    
    // boucler pour chaque mots
    while(index != -1)
    {
      index = phrase.indexOf(" ");
      String word1 = phrase.substring(0,index);
      
      // enlever le premier mot de la phrase, garder le reste
      phrase = phrase.substring(index, phrase.length());
      
      int nbVoyelles = 0;
      
      // compter le nombre de voyelles
      for(int j = 0; j < word1.length(); j++)
      {
        if(word1.charAt(j) == 'a')
          nbVoyelles++;
        else if(word1.charAt(j) == 'e')
          nbVoyelles++;
        else if(word1.charAt(j) == 'i')
          nbVoyelles++;
        else if(word1.charAt(j) == 'o')
          nbVoyelles++;
        else if(word1.charAt(j) == 'u')
          nbVoyelles++;
      }
    
      
      int delais = 80;
      
      for(int j=0; j<nbVoyelles; j++)
      {
        
        bouche_vide_no_show();
        bouche_fermee(60,60,60);
        delay(delais/nbVoyelles);
        bouche_vide_no_show();
        petite_bouche(60,60,60);
        delay(delais/nbVoyelles);
        bouche_vide_no_show();
        grande_bouche(60,60,60);
        delay(delais/nbVoyelles);
        bouche_vide_no_show();
        petite_bouche(60,60,60);
        delay(delais/nbVoyelles);
        bouche_vide_no_show();
        bouche_fermee(60,60,60);
        delay(delais/nbVoyelles);
        bouche_vide_no_show();
        smile(60,60,60);
        
        delay(10/nbVoyelles);
      }
      talking=false;
    }
  }
}

// Fonction animation bouche en fonction du nombre de mots
void talk(const std_msgs::String& word)
{
  int r=0, g=0, b=0;
  if(!talking)
  {
    talking = true;
    int nbWords = 1;
    for(int i=0; i<strlen(word.data);i++)
    {
      if(word.data[i] == ' ')
      {
        nbWords++;
      }
    }

    if(mode == 0)
    {

    }
    else if (mode == 1)
    {
      r=50;
      g=50;
      b=50;
    }
    else if(mode == 2)
    {
      r=50;
      g=50;
      b=50;
    }
    else if(mode == 3)
    {
      r=0;
      g=50;
      b=0;
    }
    else if(mode == 4)
    {
      r=50;
      g=50;
      b=0;
    }
    else if(mode == 5)
    {
      r=50;
      g=0;
      b=0;
    }
    else if (mode == 6)
    {
      r=0;
      g=0;
      b=50;
    }
    
    int delais = 50;

    for(int j=0; j<nbWords; j++)
    {
      bouche_vide_no_show();
      bouche_fermee(r,g,b);
      delay(delais);
      bouche_vide_no_show();
      petite_bouche(r,g,b);
      delay(delais);
      bouche_vide_no_show();
      grande_bouche(r,g,b);
      delay(delais);
      bouche_vide_no_show();
      petite_bouche(r,g,b);
      delay(delais);
      bouche_vide_no_show();
      bouche_fermee(r,g,b);
      delay(delais);
      bouche_vide_no_show();

      if(mode == 0)
      {

      }
      else if (mode == 1)
      {
        openFade();
      }
      else if(mode == 2)
      {
        loadingRoll2();
        smile(60,60,60);
      }
      else if(mode == 3)
      {
        emo_content();
      }
      else if(mode == 4)
      {
        emo_ciconspect();
      }
      else if(mode == 5)
      {
        emo_fache();
      }
      else if (mode == 6)
      {
        emo_wait();
      }
      
      delay(10);
    }
    talking=false;
  }
}

void loadingFade()
{
  int OEIL_1 = 0;
  int OEIL_2 = 14;
  int wait = 5;
  for(int j = 0; j <= 150; j++)
  {
    for(int i=OEIL_1; i<(OEIL_1+14); i++)
    {
      pixels.setPixelColor(i, pixels.Color(j,j,j)); 
    }
    for(int i=OEIL_2; i<(OEIL_2+14); i++)
    {
      pixels.setPixelColor(i, pixels.Color(j,j,j));
    }
    pixels.show();
    delay(wait);
  }
  for(int j = 150; j >= 0; j--)
  {
    for(int i=OEIL_1; i<(OEIL_1+14); i++)
    {
      pixels.setPixelColor(i, pixels.Color(j,j,j)); 
    }
    for(int i=OEIL_2; i<(OEIL_2+14); i++)
    {
      pixels.setPixelColor(i, pixels.Color(j,j,j));
    }
    pixels.show();
    delay(wait);
  }
}

void loadingRoll2()
{
  int OEIL_1 = 0;
  int OEIL_2 = 14+7;
  int wait = 100;
    
  for(int PositionCercle = 14; PositionCercle > 0; PositionCercle--)
  {  
    // Oeil droit
    for(int i = 0; i < 14; i++)
    {
      pixels.setPixelColor((i+PositionCercle)%14, pixels.Color(i*5,i*5,75)); 
    }
    // Oeil gauche
    for(int i = 0; i < 14; i++)
    {
      int pos = (i+PositionCercle)%14;
      
      if(pos >= 7)
      {
        pixels.setPixelColor(pos + 7, pixels.Color(i*5,i*5,75)); 
      }
      else 
      {
        pixels.setPixelColor(pos + 21, pixels.Color(i*5,i*5,75)); 
      }
    }
    
    pixels.show();
    delay(wait);
  }
}

void xMouth()
{
   
  
}

// cercle séparé en 2, fonction non complete
void loadingRoll3()
{
  int OEIL_1 = 0;
  int OEIL_2 = 14+7;
  int wait = 100;
    
  for(int PositionCercle = 14; PositionCercle > 0; PositionCercle--)
  {  
    for(int i = 0; i < 14; i++)
    {
      pixels.setPixelColor((i+PositionCercle)%14, pixels.Color(i*5,i*5,75)); 
    }
    for(int i = 0; i < 14; i++)
    {
      if(i >= 7)
      {
        pixels.setPixelColor((i+PositionCercle+EYEPIXELS/2)%14, pixels.Color(i*5,i*5,75)); 
      }
      else
      {
        pixels.setPixelColor((i+PositionCercle+EYEPIXELS)%14, pixels.Color(i*5,i*5,75)); 
      }
    }
    
    pixels.show();
    
    delay(wait);
  }
}

void loadingRoll()
{
  int OEIL_1 = 0;
  int OEIL_2 = 14+7;
  int wait = 25;
  for(int j = 0; j < 14; j++)
  {  
    pixels.setPixelColor(OEIL_1+j, pixels.Color(j*5,j*5,50)); 
    if(j>=7)
    {
      pixels.setPixelColor(7+j, pixels.Color(j*5,j*5,50)); 
    }
    else
    {
      pixels.setPixelColor(OEIL_2+j, pixels.Color(j*5,j*5,50)); 
    }
    pixels.show();
    delay(wait);
  }
  for(int j = 0; j < 14; j++)
  {  
    pixels.setPixelColor(OEIL_1+j, pixels.Color(70+j*4,70+j*4,50)); 
    
    if(j>=7)
    {
      pixels.setPixelColor(7+j, pixels.Color(70+j*4,70+j*4,50)); 
    }
    else
    {
      pixels.setPixelColor(OEIL_2+j, pixels.Color(70+j*4,70+j*4,50)); 
    } 
    pixels.show();
    delay(wait);
  }
  for(int j = 0; j < 14; j++)
  {  
    pixels.setPixelColor(OEIL_1+j, pixels.Color(70+j/4,70+j/4,50)); 
    
    if(j>=7)
    {
      pixels.setPixelColor(7+j, pixels.Color(70+j/4,70+j/4,50)); 
    }
    else
    {
      pixels.setPixelColor(OEIL_2+j, pixels.Color(70+j/4,70+j/4,50)); 
    } 
    pixels.show();
    delay(wait/2);
  }
  for(int j = 0; j < 14; j++)
  {  
    pixels.setPixelColor(OEIL_1+j, pixels.Color(j/5,j/5,50)); 
    if(j>=7)
    {
      pixels.setPixelColor(7+j, pixels.Color(j/5,j/5,50)); 
    }
    else
    {
      pixels.setPixelColor(OEIL_2+j, pixels.Color(j/5,j/5,50)); 
    }
    pixels.show();
    delay(wait/2);
  }
}

void emo_content()
{
  /*Émotion : Content*********************************************/
  clearPixels();
  eye_1(50,50,50);
  eye_2(50,50,50);
  //bouche_vide(); //Changer LED3 et LED45
  smile(50,50,50);
  delay(1000);
}

void emo_wait()
{
  /*Émotion : wait*********************************************/
  clearPixels();
  eye_1(0,0,50);
  eye_2(0,0,50);
  //bouche_vide(); //Changer LED3 et LED45
  smile(0,0,50);
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
  eye_1(50,50,0);
  eye_2(50,50,0);
  bouche_fermee(50,50,0);
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
  
void bouche_vide_no_show(){
  for(int i=EYEPIXELS*2; i<NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  pixels.setPixelColor(i, pixels.Color(0,0,0)); 
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
  
  void clearPixels()
  {
    for(int i=0; i < NUMPIXELS; i++)
    {
     pixels.setPixelColor(i,pixels.Color(0,0,0)); 
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

void set_brightness(const std_msgs::UInt8& value)
{
 pixels.setBrightness(value.data);
 pixels.show(); 
  
}
void set_mode(const std_msgs::UInt8& modeVal)
{
    mode = modeVal.data;
}

ros::NodeHandle nh;

ros::Subscriber<std_msgs::UInt8> subEmo("control_emo", control_emo );
ros::Subscriber<std_msgs::UInt8> setBright("face_bright", set_brightness );
ros::Subscriber<std_msgs::UInt8> setMode("face_mode", set_mode);
ros::Subscriber<std_msgs::String> subTalk("SaraVoice", talk);


void setup() 
{
  // put your setup code here, to run once:
  pixels.begin(); // This initializes the NeoPixel library.

  nh.initNode();
  //nh.subscribe(subMouth);
  //nh.subscribe(subEye);
  nh.subscribe(subEmo);
  nh.subscribe(setBright);
  nh.subscribe(setMode);
  nh.subscribe(subTalk);
  pixels.setBrightness(DEFAULT_BRIGHTNESS);
  clearPixels(); 
  pixels.show();
}

void loop() 
{
  if(mode == 0)
  { 
    
  }
  else if (mode == 1)
  {
    openFade();
    mode = 3;
  }
  else if(mode == 2)
  {
    loadingRoll2();
    smile(60,60,60);
  }
  else if(mode == 3)
  {
    emo_content();
    mode = 0;
  }
  else if(mode == 4)
  {
    emo_ciconspect();
    mode = 0;
  }
  else if(mode == 5)
  {
    emo_fache();
    mode = 0;
  }
  else if (mode == 6)
  {
    emo_wait();
    mode = 0;
  }
  nh.spinOnce();
}



