/* Q579 Clock Hands: by yatsen */
#include <stdio.h>

main()
{ 
 int hour,min,totalmin;
 float hourdegree,mindegree,angel;
while(1)
{  
   scanf("%d:%d",&hour,&min);
   if (hour==0) break;
   totalmin=hour*60+min;
   hourdegree=totalmin*0.5;
   mindegree=min*6.0;

   angel=hourdegree-mindegree;
   if (angel<0) angel=-angel;
   if (angel>180) angel=360-angel;
   printf("%-7.3f\n",angel);
} /* while */
return 0;
}
