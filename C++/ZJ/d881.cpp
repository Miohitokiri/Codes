#include<iostream>
using namespace std;
int main(){
	long long d, ans = 0;
	long long data[50];
	data[0] = 1;
	while ( cin >> d ){
		for ( int i = 1 ; i < 50 ; i++ ){
			long long s = 1 + d * ( i - 1 );
			data[i] = ( 1 + s ) * i / 2;
			ans += data[i];
		}
		cout << ans << endl;
	}
	return 0;
}