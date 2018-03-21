#include<bits/stdc++.h>

using namespace std;

int dis[1000010];

inline int find ( int a ){
	return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void u ( int a, int b ){
	dis[find ( a )] = find ( b );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, a, b, an, bn;
	string ask, s, relation;
	cin >> n;
	for ( int i = 1 ; i < 1000010 ; i++ )
		dis[i] = i;
	while ( cin >> ask >> s >> relation >> a >> b ){
		an = a + n, bn = b + n;
		if ( ask == "you" ){
			if ( relation == "friends" ){
				if ( find ( an ) == find ( b ) || find ( a ) == find ( bn ) )
					cout << "angry\n";
				else{
					u ( a, b );
					u ( an, bn );
				}
			}
			else{
				if ( find ( an ) == find ( bn ) || find ( a ) == find ( b ) )
					cout << "angry\n";
				else{
					u ( a, bn );
					u ( b, an );
				}
			}
		}
		else{
			if ( relation == "friends" )
				cout << ( find ( a ) == find ( b ) ? "yeap" : "nope" );
			else
				cout << ( find ( a ) == find ( bn ) || find ( b ) == find ( an ) ? "yeap" : "nope" );
			cout << '\n';
		}
	}
}