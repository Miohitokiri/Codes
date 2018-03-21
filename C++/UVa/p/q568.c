
/* Q568 Just the Facts: by yatsen*/
#include <stdio.h>
main()
{long i,n,p;
 while (scanf("%ld",&n)==1)
 {p=1;
  for (i=1;i<=n;i++)
   { p=p*i;
     while (p%10==0) p=p/10;
     p=p%100000;
   }
  while (p%10==0) p=p/10;
  printf("%5ld -> %ld\n",n,p%10);
 }
}
