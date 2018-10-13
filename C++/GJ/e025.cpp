#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, t;
	multiset < int > data;
	cin >> t;
	while ( t-- ){
		data.clear();
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
}