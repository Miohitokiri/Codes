#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define pb push_back

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	long long ans = -1, first, in, idx;
	vector < long long > lib;
	lib.pb ( 1 );
	lib.pb ( 1 );
	for ( int i = 1 ; i < 64 ; i++ ){
		lib.pb ( *( lib.end() - 1 ) + *( lib.end() - 2 ) );
	}

	// for ( int i = 0 ; i < lib.size() ; i++ ){
	// 	cout << lib[i] << ' ';
	// }
	// cout << '\n';

	cin >> in;
	idx = lower_bound ( lib.begin(), lib.end(), in ) - lib.begin();
	if ( lib[idx] != in ){
		cout << in << '\n';
		if ( in == 0 ){
			cout << 64 << '\n';
			return 0;
		}
		return 0;
	}
	first = idx;
	lib.erase ( lib.begin() + idx );
	while ( cin >> in ){
		if ( in > 1000000000 ){
			cout << 64 << '\n';
			return 0;
		}
		idx = lower_bound ( lib.begin(), lib.end(), in ) - lib.begin();
		if ( lib[idx] != in ){
			if ( !in ){
				cout << 64 << '\n';
				return 0;
			}
			cout << in << '\n';
			return 0;
		}
		lib.erase ( lib.begin() + idx );
	}
	if ( first + 1 == 0 ){
		cout << 64 << '\n';
		return 0;
	}
	cout << first + 1 << '\n';
}