#include<bits/stdc++.h>
using namespace std;
int A[20], B[20], C[20], D[20];
bool dp ( int a, int b, int c, int d ) {
	if ( a < 0 || b < 0 || c < 0 || d < 0 ) return false;
	if ( a == 0 && b == 0 && c == 0 && d == 0 ) return true;
	if ( A[a] == B[b] && dp ( a - 1, b - 1, c, d ) ) return true;
	if ( A[a] == C[c] && dp ( a - 1, b, c - 1, d ) ) return true;
	if ( A[a] == D[d] && dp ( a - 1, b, c, d - 1 ) ) return true;
	if ( B[b] == C[c] && dp ( a, b - 1, c - 1, d ) ) return true;
	if ( B[b] == D[d] && dp ( a, b - 1, c, d - 1 ) ) return true;
	if ( C[c] == D[d] && dp ( a, b, c - 1, d - 1 ) ) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while ( cin>>A[1] ) {
		for ( int i = 2 ; i <= 13 ; i++ )
			cin >> A[i];
		for ( int i = 1 ; i <= 13 ; i++ )
			cin >> B[i];
		for ( int i = 1 ; i <= 13 ; i++ )
			cin >> C[i];
		for ( int i = 1 ; i <= 13 ; i++ )
			cin >> D[i];
		cout << ( dp ( 13, 13, 13, 13 ) ? "YES" : "NO" ) << '\n';
	}
	return 0;
}