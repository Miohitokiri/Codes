#include<bits/stdc++.h>
using namespace std;

#define maxN 200005

const int mod = 998244353;
int pos[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, k, in;
	long long ans = 0, tms = 1;
	vector < int > data;
	cin >> n >> k;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		pos[in] = i;
	}
	if ( n == k ){
		for ( int i = 1 ; i <= n ; i++ ){
			ans += i;
		}
		cout << ans << " 1\n";
		return 0;
	}
	if ( k == 1 ){
		cout << n << " 1\n";
		return 0;
	}

	for ( int i = n, cnt = 0 ; cnt < k ; i--, cnt++ ){
		ans += i;
		data.push_back ( pos[i] );
	}
	sort ( data.begin(), data.end() );
	for ( int i = 1 ; i < data.size() ; i++ ){
		// cout << data[i] - data[i - 1] << '\n';
		tms *= ( data[i] - data[i - 1] );
		tms %= mod;
	}

	cout << ans << ' ' << tms << '\n';
}