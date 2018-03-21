#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a, b, ma;
	vector < int > stop, tmp;
	stop.push_back ( 1 );
	stop.push_back ( 2 );
	stop.push_back ( 7 );
	while ( *stop.rbegin() < 1000000005 ){
		for ( auto i: stop ){
			tmp.push_back ( i * 10 + 1 );
			tmp.push_back ( i * 10 + 2 );
			tmp.push_back ( i * 10 + 7 );
		}
		for ( auto i: tmp )
			stop.push_back ( i );
		tmp.clear();
	}

	cout << "111\n";

	for ( auto i: stop )
		cout << i << ' ';
	cout << '\n';
}