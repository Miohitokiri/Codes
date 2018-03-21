#include<bits/stdc++.h>
using namespace std;
inline int solve ( short a, short b, int plus );
int dp[100005][100005];
int main(){
	// ios::sync_with_stdio ( false );
	// cin.tie ( 0 );

	int t, a, b;
	cin >> t;
	while ( t-- ){
		cin >> a >> b;
		cout << solve ( a, b ) + 1 << '\n';
	}
}

inline int solve ( short a, short b, int plus ){
	cout << a << ' ' << b << '\n';
	if ( a == b )
		return 0;
	else{
	}
}