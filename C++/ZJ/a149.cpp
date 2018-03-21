#include<iostream>
using namespace std;
int main(){
	long long t,a;
	cin >> t;
	for ( int i = 0 ; i < t ; i++ ){
		cin >> a;
		long long ans = a % 10;
		a /= 10;
		while ( a != 0 ){
			ans *= ( a % 10 );
			a -= a % 10;
			a /= 10;
		}
		cout << ans << endl;
	}
	return 0;
}
