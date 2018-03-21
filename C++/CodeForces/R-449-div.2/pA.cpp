#include<bits/stdc++.h>

using namespace std;

#define int long long

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, t, l, r;
	string str;
	char chr1, chr2;

	cin >> n >> t >> str;
	while ( t-- ){
		cin >> l >> r >> chr1 >> chr2;
		l--, r--;
		for ( int i = l ; i <= r ; i++ )
			if ( str[i] == chr1 )
				str[i] = chr2;
	}

	cout << str << '\n';
}