#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	multiset < int > data;
	while ( cin >> n && n )
		if ( 0 < n )
			data.insert ( n );
		else if ( data.empty() )
			continue;
		else if ( n == -1 ){
			cout << *data.begin() << ' ';
			data.erase ( data.find ( *data.begin() ) );
		}
		else{
			cout << *data.rbegin() << ' ';
			data.erase ( data.find ( *data.rbegin() ) );
		}

	cout << '\n';
}