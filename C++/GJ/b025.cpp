#include<iostream>

using namespace std;

long long dp[35][35];

int main(){
	int x, y;
	cin >> x >> y;
	for ( int i = 1 ; i <= x ; i++ )
		dp[i][0] = 1;
	for ( int i = 1 ; i <= y ; i++ )
		dp[0][i] = 1;

	for ( int i = 1 ; i <= x ; i++ ){
		for ( int j = 1 ; j <= y ; j++ ){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	cout << dp[x][y] << '\n';
}