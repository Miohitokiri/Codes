#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, key, res, cnt = 0;
	string a, ans;
	vector < int > data;
	cin >> key;
	while ( cin >> a ){
		res = 0;
		for ( auto i: a ){
			i == 'X' ? res += 1 : res;
			res *= 2;
		}
		res /= 2;

		ans += ( char ) res ^ key;
		data.push_back ( res ^ key );
		cnt++;
	}
	cout << ans;
	for ( auto i: data )
		cout << i << ' ';
	cout << '\n';
}