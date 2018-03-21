#include<iostream>
using namespace std;
int main(){
	long long k,ans = 0;
	cin >> k;
	for ( int i = 0 ; i < k ; i++ ){
		long long x,c;
		cin >> x >> c;
		if ( c == 1 ){
			ans += 1;
		}
	}
	cout << ans << endl;
	return 0;
}
