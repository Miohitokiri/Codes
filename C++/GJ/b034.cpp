#include<iostream>
#include<vector>

using namespace std;

#define pb push_back

int dp[100005];

int main(){
	int n;
	cin >> n;
	dp[1] = 1;
	vector < int > coin;
	coin.pb ( 1 );
	coin.pb ( 5 );
	coin.pb ( 10 );
	coin.pb ( 50 );
	coin.pb ( 100 );
	coin.pb ( 500 );
	coin.pb ( 1000 );
	coin.pb ( 5000 );
	coin.pb ( 10000 );
	memset ( dp, 0x3f3f3f3f, sizeof dp );
	dp[0] = 0;

	for ( int i = 1 ; i <= n ; i++ ){
		for ( int j = 0 ; j < 9 && i >= coin[j] ; j++ )
			dp[i] = min ( dp[i - coin[j]] + 1, dp[i] );
	}

	cout << dp[n] << '\n';
}