#include<iostream>
using namespace std;
int main(){
	long long ans = 0;
	for ( int i = 1 ; i <= 30 ; i++ ){
		ans += i * ( 2 + ( i-1)*1  )* i / 2;
	}
	cout << ans << endl;
	return 0;
}