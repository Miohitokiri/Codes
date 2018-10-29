// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define maxN 1000000

bitset < maxN > lib;
vector < LL > prime;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );
	#define int LL

	lib[0] = lib[1] = true;
	for ( int i = 2 ; i < maxN ; i++ ){
		if ( !lib[i] ){
			prime.push_back ( i );
			for ( int j = i ; j < maxN ; j += i )
				lib[j] = true;
		}
	}
	// PIO ( prime );

	int a, b, len = prime.size();
	LL ans, stp;
	while ( cin >> a >> b ){
		if ( a > b )
			swap ( a, b );
		ans = upper_bound ( prime.begin(), prime.end(), a ) - prime.begin();
		stp = 1;
		for ( int i = a + 1 ; i <= b ; i++ ){
			stp *= i;
		}
		stp++;
		for ( int i = 0 ; i < ans ; i++ ){
			while ( stp % prime[i] == 0 ){
				stp /= prime[i];
			}
		}

		for ( int i = ans ; i < len ; i++ ){
			if ( !( stp % prime[i] ) ){
				ans++;
				while ( stp % prime[i] == 0 )
					stp /= prime[i];
			}
		}

		if ( stp > maxN )
			ans++;

		cout << ans << '\n';
	}
}