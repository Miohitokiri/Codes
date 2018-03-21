/* Better Solution: Dynamic programming */
/* Q136 Ugly number: by yatsen */
#include<stdio.h>
main()
{
 long u[1501];
 long count=0,last,k,next2,next3,next5,nowbig;
 u[1]=1; u[2]=2; u[3]=3; u[4]=4; u[5]=5;

 for (count=6;count<=1500;count++)
 { nowbig=2147483647; /* the maxmum of int */
   for (k=1;k<=count-1;k++)
    {
      next2=2*u[k]; next3=3*u[k]; next5=5*u[k];
      if (next2>u[count-1] && next2<nowbig) nowbig=next2;
      else if (next3>u[count-1] && next3<nowbig) nowbig=next3;
	   else if (next5>u[count-1] && next5<nowbig) nowbig=next5;
    }
  u[count]=nowbig;
  /* printf("%ld: %ld\n",count,nowbig); */

 }
 printf("The 1500'th ugly number is %ld.\n",u[1500]);
}
