#include<bits/stdc++.h>
using namespace std;
#define maxN 10000007
bitset < maxN > lib;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	for ( int i = 2 ; i < maxN ; i++ ){
		if ( lib[i] )
			continue;
		for ( int j = i * 2 ; j <= maxN ; j += i )
			lib[j] = true;
	}

	int n;
	cin >> n;
	for ( int i = 4 ;  ; i++ ){
		if ( lib[i] && lib[i + n] ){
			cout << i + n << ' ' << i << '\n';
			return 0;
		}
	}
}