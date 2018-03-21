#include<bits/stdc++.h>
using namespace std;
void pow3 ( void );
long long a, b;
short c;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cin >> a >> b >> c;
	a %= c;
	pow3();
}
inline void pow3 ( void ){
	long long ans = 1, base = a;
	while ( b != 0 ){
		if ( b & 1 ){
			ans %= c;
			ans *= base;
		}
		base *= base;
		base %= c;
		b >>= 1;
	}
	cout << ans % c << endl;
}