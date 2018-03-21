#include<bits/stdc++.h>
#define int long long

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, a, b, c, dataI;
	double dataD;
	cin >> n;
	while ( n-- ){
		cin >> a >> b >> c;
		dataD = sqrt ( b * b - 4 * a * c );
		dataI = ( int ) dataD;
		cout << ( dataI == dataD ? "Yes" : "No" ) << '\n';
	}
	return 0;
}