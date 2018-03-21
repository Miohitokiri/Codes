#include<bits/stdc++.h>

using namespace std;

int cnt, n;
string str;

inline void dfs ( int Index ){
	cnt++;
	for ( int i = Index ; i < n ; i++ ){
		if ( str[i] == ' ' )
			break;
		str[i] = ' ';
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	while ( getline ( cin, str ) ){
		if ( str == "" )
			break;
		cnt = 0;
		n = str.size();
		for ( int i = 0 ; i < n ; i++ ){
			if ( ( 'A' <= str[i] && str[i] <= 'Z' ) || ( 'a' <= str[i] && str[i] <= 'z' ) )
				continue;
			str[i] = ' ';
		}
		for ( int i = 0 ; i < n ; i++ )
			if ( str[i] != ' ' )
				dfs ( i );

		cout << cnt << '\n';
	}
}