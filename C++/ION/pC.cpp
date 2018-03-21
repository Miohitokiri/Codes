#include<bits/stdc++.h>
using namespace std;
struct stear{
	int h, t, a;
} data[405], stop[405];

int dp[405][15];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int k, ma = 0;
	cin >> k;
	for ( int i = 1 ; i <= k ; i++ )
		cin >> data[i].h >> data[i].t >> data[i].a;

	for ( int i = 1 ; i <= k ; i++ ){
		for ( int j = 1 ; j <= data[i].a ; j++ )
	}

	cout << dp[k][data[k].a] << '\n';
}