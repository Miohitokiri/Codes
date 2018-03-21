#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	char data[200];
	bool flag;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> data[i];
		if ( 'a' <= data[i] && data[i] <= 'z' )
			flag = false;
	}

	if ( flag )
		cout << 0;
	else{
		int ans, stop;
		vector < char > s;
		for ( int i = 0 ; i < n ; i++ ){
			stop = 1;
			for ( ; i < n ; i++ ){
				if ( 'a' <= data[i] && data[i] <= 'z' )
					s.push_back ( data[i] );
				else
					break;
			}

			if ( s.size() ){
				sort ( s.begin(), s.end() );
				for ( int i = 1 ; i < s.size() ; i++ )
					s[i] != s[i - 1] ? stop++ : stop;

				ans = max ( ans, stop );
			}

			if ( !s.empty() )
				s.clear();
		}

		cout << ans;
	}

	cout << '\n';
}