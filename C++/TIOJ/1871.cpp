#include"lib1871.h"

#include<utility>

using namesapce std;

int main(){
   int n = futa::init();

   int *A = futa::momo_gives_you_list_of_futa();

   int q = futa::momo_tells_you_q();

   while(q--){

	  pair<int,int> a = futa::momo_asks();

	  futa::you_tell_momo(A[a.first]);

   }

   return 0;

}