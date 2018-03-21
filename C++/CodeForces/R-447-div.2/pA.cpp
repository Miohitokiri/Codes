#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	string str;
	int cnt = 0;
	cin >> str;
	for ( int i = 0 ; i < str.size() ; i++ )
		if ( str[i] == 'Q' )
			for ( int j = i + 1 ; j < str.size() ; j++ )
				if ( str[j] == 'A' )
					for ( int s = j + 1 ; s < str.size() ; s++ )
						if ( str[s] == 'Q' )
							cnt++;
	cout << cnt << '\n';
}