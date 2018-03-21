#include<bits/stdc++.h>

using namespace std;

int main(){
	int cntA, cntB, dp[5005][4];
	string in;
	cin >> in;

	memset ( dp, 0x8f, sizeof dp );

	dp[0][1] = 0;

	for ( int i = 1 ; i <= in.size() ; i++ ){
		cntA = cntB = 0;
		for ( int j = i ; j > 0 ; j-- ){
			in[j - 1] == 'a' ? cntA++ : cntB++;

			dp[i][2] = max ( dp[i][2], dp[j - 1][1] + cntB );
			dp[i][3] = max ( dp[i][3], dp[j - 1][2] + cntA );
		}
		dp[i][1] = cntA;
		dp[i][2] = max ( dp[i][2], dp[i][1] );
		dp[i][3] = max ( dp[i][3], dp[i][2] );
	}

	cout << dp[in.size()][3] << '\n';
}