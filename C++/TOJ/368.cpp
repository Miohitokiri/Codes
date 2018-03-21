#include<bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

inline int cnt ( int n ){
	int res = 0;
	while ( n ){
		n % 10 == 7 ? res++ : res;
		n /= 10;
	}

	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	vector < int > data;
	int p = 0;
	for ( int i = 7 ; i < 1000000000000 ; i++ ){
		data.push_back ( cnt ( i ) );
		cout << i << '\n';
	}
	cout << data.size() << '\n';
}