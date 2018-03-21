#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	long long t;
	cin >> t;
	for ( long long times = 0 ; times < t ; t++ ){
		long long N, W, ans = 0;
		cin >> N >> W;
		long long w[N], v[N];
		for ( long long i = 0 ; i < N ; i++ )
			cin >> v[i] >> w[i];
		long long P;
		cin >> P;
		for ( long long i = 0 ; i < P ; i++ ){
			long long p, ma;
			cin >> p;
			long long dp[N][p];
			memset ( dp, 0, sizeof ( dp ) );
			for ( long long i = 0 ; i < N ; i++ )
				for ( long long j = W - w[i] ; j >= 0 ; j-- ){
					dp[i][j] = max ( dp[i - 1][j], dp[i - 1][j - w[i]] + v[i] );
					ma = max ( ma, dp[i][j] );
				}
			ans += ma;
		}
		cout << ans << endl;
	}
}