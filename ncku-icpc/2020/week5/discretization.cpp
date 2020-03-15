#include<bits/stdc++.h>

using namespace std;

#define pb push_back

int main(){
	int n, in;
	vector < int > data, lib;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> in;
		data.pb ( in );
	}
	lib = data;
	sort ( lib.begin(), lib.end() );
	lib.erase ( unique ( lib.begin(), lib.end() ), lib.end() );

	for ( auto i: data )
		cout << i << ' ';
	cout << '\n';
	for ( auto &i: data )
		i = lower_bound ( lib.begin(), lib.end(), i ) - lib.begin();
	for ( auto i: data )
		cout << i << ' ';
	cout << '\n';
}