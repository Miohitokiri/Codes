#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, cnt = 0, ans = 0;
	string str;
	cin >> n >> str;
	for ( auto i: str )
		if ( i == '>' )
			cnt++;
		else{
			ans += ( cnt + 1 ) * cnt / 2;
			cnt = 0;
		}

	ans += ( cnt + 1 ) * cnt / 2;
	cout << ans << '\n';
}