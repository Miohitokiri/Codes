#include <iostream>
using namespace std;

void step1(int n, int m=0){
   char ch;
   for (int i=n; i>m; i--){
      if (n>25){
         cout << '#';
      }
      else {
         ch = 65+i;
         cout << ch;
      }
   }
   for (int j=m; j<=n; j++){
      if (n>25)
          cout << '#';
      else {
         ch = 65 + j;
         cout << ch;
      }
   }
   cout << endl;
}
void step2(int n){
   char ch;
   if(n>25)
       ch=35;
    else
        ch =65+n;
    for(int j=0; j<n-2; j++){
       cout << ch;
       for (int i=0; i<2*n-1; i++)
       {
           cout << ' ';
       }
       cout << ch;
       cout << endl;
    }
}

int main() {
    
    int n;
    while(cin >> n){
       step1(n);
       step2(n);
       step1(n);
       for (int i=0; i<=n; i++){
          for (int j=0; j<i; j++) {
             cout << ' ' ;
          }
          step1(n,i);
       }
    }
    return 0;
}