#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string str, data[100005];
	long long cnt = 0, p, num[100005], res, n, c = 0, mod, zero = 0;
	for ( cnt = 0 ; cnt < 9 ; cnt++ ){
		str = "";
		str += ( char ) ( cnt + '0' ) + 1;
		data[cnt] = str;
	}

	while ( cnt <= 90005 ){
		c = p;
		p = cnt;
		for ( int i = c ; i < p ; i++ )
			for ( char j = '0' ; j <= '9' ; j++ ){
				// j != '0' ? zero++ : zero;
				str = j + data[i] + j;
				data[cnt++] = str;
			}
	}
	cin >> n >> mod;

	p = 0;
	for ( int i = 0 ; i <= cnt ; i++ )
		if ( data[i][0] != '0' ){
			res = 0;
			for ( int j = 0 ; j < data[i].size() ; j++ ){
				res *= 10;
				res += ( int ) data[i][j] - '0';
				// res %= mod;
			}
			num[p++] = res;
		}

	sort ( num, num + p );

	res = cnt = 0;
	// cout << p << '\n';
	for ( int i = 1 ; i <= n ; i++ ){
		res += num[i];
		res %= mod;
	}
	cout << res << '\n';
}