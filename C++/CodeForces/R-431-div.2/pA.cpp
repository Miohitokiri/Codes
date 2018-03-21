#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, data[105] = { 0 }, size = 0, shape = 0, l, count = 0;
	bool tf[105] = { 0 }, ans = false;
	cin >> n;
	double end = log2 ( n );
	l = ( int ) end;

	for ( int i = 0 ; i < n ; i++ ){
		cin >> data[i];
		tf[i] = data[i] & 1;
		!tf[i] ? count++ : count;
	}

	if ( n & 1 && data[0] & 1 && data[n - 1] & 1 )
		ans = true;
	else if ( l == end  || !( count & 1 ) || ( !( n & 1 ) && ! ( ( n / 2 ) & 1 ) ) || !( data[0] & 1 ) || ! ( data[n - 1] & 1 ) )
		ans = false;

	cout << ( ans ? "Yes" : "No" ) << '\n';
}