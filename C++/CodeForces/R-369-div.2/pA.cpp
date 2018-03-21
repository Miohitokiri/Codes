#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );


	int n;
	bool ans = false;
	cin >> n;
	vector < string > sit;
	string stop;
	while ( n-- ){
		cin >> stop;

		if ( stop[0] == stop[1] && stop[1] == 'O' && !ans ){
			ans = true;
			stop[0] = stop[1] = '+';
		}
		if ( stop[3] == stop[4] && stop[3] == 'O' && !ans ){
			ans = true;
			stop[3] = stop[4] = '+';
		}

		sit.push_back ( stop );
	}

	if ( !ans )
		cout << "NO\n";
	else{
		cout << "Yes\n";
		for ( auto i: sit )
			cout << i << '\n';
	}
}