/* Q591 Box of Bricks: by yatsen*/
#include <stdio.h>
main()
{ int a[50],i,avg,move,s,n,Set=1;
  
while (1)
{ 
  scanf("%d",&n);
  if (n==0) break;
  for (i=0;i<n;i++) scanf("%d",&a[i]);
  for (i=0,s=0;i<n;i++) s=s+a[i];
  avg=s/n;
  for (i=0,move=0;i<n;i++) if (a[i]<avg) move=move+avg-a[i];
  printf("Set #%d\n",Set++);
  printf("The minimum number of moves is %d.\n",move);
} /*while (1)*/
}
