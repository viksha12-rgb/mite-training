#include <stdio.h>
void displayAges(short int* ages,int length,int index)
{
 if(index >= length)
 {
  return;
}
 printf("%d ",ages[index]); 
 displayAges(ages,5,index+1);
}
void travelBackwardAges(short int* ages,int length,int index) {
 if(index >= length)
 {
  return;
 }
 travelBackwardAges(ages,5,index+1);
 printf("%d ",ages[index]); 
}
int main()
{
  short int ages[]={45,34,20,70,68};
  displayAges(ages,5,0);
  printf("\n");
  travelBackwardAges(ages,5,0);
  return 0;
}
