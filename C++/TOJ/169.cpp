#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef pair < int , int > pii;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, in;
	vector < pii > data;
	while ( cin >> n ){
		data.clear();
		cin >> in;
		data.pb ( pii ( in, 0 ) );
		cout << 0;
		for ( int i = 1 ; i < n ; i++ ){
			cin >> in;

			while ( !data.empty() && in > ( data.end() - 1 ) -> x )
				data.pop_back();

			cout << ' ';
			if ( data.empty() )
				cout << i;
			else
				cout << i - ( data.end()  - 1 ) -> y - 1;
			data.pb ( pii ( in, i ) );
		}

		cout << '\n';
	}
}