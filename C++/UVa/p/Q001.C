/* q001GCD by Alex Lee */
#include <stdio.h>
main()
{
 long a,b,temp;
 while (1)
 {
  scanf("%ld %ld",&a,&b);
  if (a==0 && b==0) break;
  printf("GCD(%ld,%ld)=",a,b);
  while (a%b!=0)
  {
	temp=a;
	a=b;
	b=temp%b;
  }
  printf("%ld\n",b);
 }
}