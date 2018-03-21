#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, cost, num, type;
	vector < pair < int, int > > main, other;
	cin >> n >> m;
	while ( m-- ){
		cin >> cost >> num >> tyoe;
		if ( !type )
			main.push_back ( make_pair ( cost, num ) );
		else
			other.push_back ( make_pair ( cost, num ) );
	}
}