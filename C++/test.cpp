// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int j, l, r;
	string str, p = "";
	cin >> str;
	while ( p != str && !str.empty() ){
		p = str;
		for ( int i = 0 ; i < str.size() ; i++ ){
			for ( j = i ; j < str.size() ; j++ ){
				if ( str[i] != str[j] )
					break;
			}
			j--;
			if ( i < j ){
				l = i, r = j;
				break;
			}
		}
		str.erase ( str.begin() + l, str.begin() + r + 1 );
	}

	cout << ( str.empty() ? "Yes" : "No" ) << '\n';
}