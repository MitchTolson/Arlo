/**
* This is the main Blank Simple C++ Project program file.
*/

/*
 *
signed char	-127 to 127
char	0 to 255
int	-2,147,483,647 to 2,147,483,647
unsigned int	0 to 4,294,967,295
long	same as int
unsigned long	same as unsigned int
float	approx: 3.4X10-38 to 3.4X1038 with 6 digits of precision
*/

#include <stdio.h>            // Recommended over iostream for saving space
#include <propeller.h>        // Propeller-specific functions
#include <simpletools.h>


int main(){
  // Add your code here
  int a = 23;
  int b = 21;
  int c = a+b;
  int d = a%b;
  print("c = %d ",c);
  print("\na = %d,b= %d",a,b);
  print("\na+b=%d",c);
  print("\na mod b= %d");
  print("\n%d",a % b);
  float r = 1.0;
  float cir = 2.0 * PI * r;
  print("circumference = %f \n",cir);
  int aa = 1000;
  int bb = aa >> 1;
  print("\%d",bb);
  int p[]= {1,2,3,4,5,6,7,11};
  print("p[0] = %d\n",p[0]);
  print("p[3] = %d\n",p[3]);
  if(p[0] > p[3])
  {
    print("p[0] is greater than p[3]\n");
  } else {
    print("p[3] might be greater than p[0]\n");
  }    
  while(a > b)
  {
    b+=1;
    print("current b %d\n",b);
    if(b==100) break;
  }     
  for(int i =1;i<5;i++)
  {
    print("%d",i);
    pause(20);
  }
  print("\nsize of array p in bytes %d\n",sizeof(p));
  print("size of int %d\n",sizeof(int));
  
  for(int i=0;i<sizeof(p)/sizeof(int);i++) //sizeof(p) gets the total number of bytes in the array. sizeof(int) gets the number of bytes used by one int element in the array. 
  {
    print("values of array p[] %d at index i %d\n",p[i],i);
   
  }  
  int variable = 123;
  int var2 = 321;
  print("variable value %d \n",variable);
  print("variable location in RAM %d \n", &variable);
  print("var2 value %d \n", var2);
  print("var2 loc in RAM %d \n", &var2);
  print("modifying variable");
  variable = 1234;   
  var2 = 4321; 
  print("updaded variable value %d \n", variable);
  print("updated variable loc in RAM %d \n", &variable);
  print("updated var2 value %d \n", var2);
  print("updated var2 loc in RAM %d \n", &var2);
  print("value of array p[3] = %d\n",p[3]);
  for(int i =0; i<sizeof(p)/sizeof(int);i++)
  {
    print("address in RAM of array element p[%d] = %d\n",i,&p[i]);
  }    
  
  int scanVal;
  print("enter a value: ");
  scan("%d\n", &scanVal); //<--- notice here how we're telling it where to place the value in ram. Scan function gets data from the console
  print("counting up to thus num %d\n",scanVal);
  for(int n=1;n<=scanVal;n++)
  {
    print("n = %d\n",n);
  }    
  
  /*
   *  %d – Decimal integer
      %f – floating point value
      %c – character
      %s – string
  */

  char text[16];
  print("enter up to 16 chars:");
  getStr(text, 15);               //function to get strings. note how print reference uses %s
  print("you typed: %s\n",text);
}
