/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h"

  static volatile int scanValPan;                            //static volatile is for a global var between cogs
  static volatile int scanValTilt;
  static volatile int timeBetweenCycle=1000;
  static volatile int panPin = 12;
  static volatile int tiltPin = 13;
  unsigned int stackPan[40 + 25];  //stack vars for other cog -- 40 long is base for new cog, + 25 is extra memory
  unsigned int stackTilt[70 + 25];
  void rotateTilt(); //forward declaration
  void rotatePan(); //void *par);
  int *cogRotatePan;
  int *cogRotateTilt;
  
int main()                                    // Main function
{
  // Add startup code here.
  servo_angle(panPin, 900);                   //(pin, angle - 0, 900, 1800)
  servo_angle(tiltPin, 900);
  print("Pan & Tilt has been centered\n");
  
  print("Please select the position of the Pan & Tilt:\n");
  print("Center: 1\n");
  print("45 deg left: 2\n");
  print("45 deg right: 3\n");
  print("Full left: 4\n");
  print("Full right: 5\n");
  print("Sweap left to right: 6\n");
  print("Sweap right to left: 7\n");
    
  /*
   int cogRotatePan = cogstart(rotatePan, NULL, stackPan, sizeof(stackPan)); //cogstart returns the ID of the cog. this both launches and stores that val
              //(address of the function, extra value, address of stack array, stack size)
    print("started Pan cog ID: %d\n",cogRotatePan);
    int cogRotateTilt = cogstart(rotateTilt, NULL, stackTilt, sizeof(stackTilt));
    print("started Tilt cog ID: %d\n",cogRotateTilt);
  */
  while(1)
  {
    // Add main loop code here.
    // int cogRotateTilt = 
     
 
    print("Enter your selection for pan and tilt with a space between: ");
    scan("%d %d\n", &scanValPan, &scanValTilt);
    print("You entered: %d for Pan and %d for tilt\n\n",scanValPan, scanValTilt);
     
    cogRotatePan = cog_run(rotatePan,sizeof(stackPan));
    cogRotateTilt = cog_run(rotateTilt,sizeof(stackTilt)); 
    
    
    //int *rotatePan = cog_run(rotatePan,128);
    //int *rotateTilt = cog_run(rotateTilt,128); 
    print("value of Pan and Tilt: %d %d\n",cog_num(cogRotatePan), cog_num(cogRotateTilt));
    //pause(6000);

    
    
    //cog_end(2);
    //cog_end(3);
    
    /*
    //TODO - currently below executes pan then tilt. if I include defination of cogs in loop here,
    // both execute simultaniously. Need to figure out how to have each cog execute independently
    // 
    rotatePan(), rotateTilt();
    */


  }  
}

void rotateTilt()
{
    
    
    while(scanValTilt!=0)
    {
    
    switch(scanValTilt)
    {
      case 1: 
        servo_angle(tiltPin, 900);
        pause(timeBetweenCycle);
        break;
      case 2:
        servo_angle(tiltPin, 450);
        pause(timeBetweenCycle);
        break;
       case 3:
        servo_angle(tiltPin, 1350);
        pause(timeBetweenCycle);
        break;
       case 4:
        servo_angle(tiltPin, 100); //50 instead of 0 to account for misaligned servo
        pause(timeBetweenCycle);
        break;
       case 5:
        servo_angle(tiltPin, 1800);
        pause(timeBetweenCycle);
        break;
       case 6:
        servo_angle(tiltPin,0);
        for(int i=0; i<1800; i+=100)
        {
          servo_angle(tiltPin,i);
          //print("%d",i);
          pause(100);
        }
        pause(timeBetweenCycle);
        break;
       case 7:
        servo_angle(tiltPin,1800);
        for(int i=1800; i>0;i-=100)
        {
          //print("%d",i);
          servo_angle(tiltPin,i);
          pause(100);
        }
        pause(timeBetweenCycle);
        break;   
                   
     }       
     scanValTilt=0;
   }     
  cog_end(cogRotateTilt);
} 

void rotatePan()
{
while(scanValPan!=0)
{
    
    switch(scanValPan)
    {
      case 1: 
        servo_angle(panPin, 900);
        pause(timeBetweenCycle);
        break;
      case 2:
        servo_angle(panPin, 450);
        pause(timeBetweenCycle);
        break;
       case 3:
        servo_angle(panPin, 1350);
        pause(timeBetweenCycle);
        break;
       case 4:
        servo_angle(panPin, 100); //50 instead of 0 to account for misaligned servo
        pause(timeBetweenCycle);
        break;
       case 5:
        servo_angle(panPin, 1800);
        pause(timeBetweenCycle);
        break;
       case 6:
        servo_angle(panPin,0);
        for(int i=0; i<1800; i+=100)
        {
          servo_angle(panPin,i);
          //print("%d",i);
          pause(100);
        }
        pause(timeBetweenCycle);
        break;
       case 7:
        servo_angle(panPin,1800);
        for(int i=1800; i>0;i-=100)
        {
          //print("%d",i);
          servo_angle(panPin,i);
          pause(100);
        }
        pause(timeBetweenCycle);
        break;   
                   
     }    
     scanValPan=0;
   }        
   cog_end(cogRotatePan);

}  
