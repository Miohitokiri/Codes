// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define maxN 1000005

bitset < maxN > num;
bool used[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	vector < int > bubble, prime, past;
	num[0] = num[1] = true;
	for ( int i = 2 ; i < maxN ; i++ )
		if ( !num[i] ){
			prime.push_back ( i );
			for ( int j = i ; j < maxN ; j += i )
				num[j] = true;
		}
	int n, T, p, sz = prime.size(), now;
	cin >> T;
	while ( T-- ){
		cin >> n >> p;
		if ( p == 1 ){
			cout << "1\n";
			continue;
		}
		used[now] = true;
		for ( int i = 1 ; i < sz ; i++ ){
			if ( prime[i] > p )
				break;
			now = prime[i] * ( ( int ) n / prime[i] );
			while ( used[now] )
				now -= prime[i];
			used[now] = true;
		}

		cout << now << '\n';
		memset ( used, 0, sizeof used );
	}
}