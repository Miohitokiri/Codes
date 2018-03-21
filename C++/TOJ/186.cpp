#include<bits/stdc++.h>

using namespace std;

#define int long long

vector < int > basic;
int n;

inline int check ( int p ){
	int j = 0, res = 0;
	for ( int i = 0 ; i < n ; i++ ){
		while ( basic[j] - basic[i] <= p && j < n )
			j++;
		res += ( j - i - 1 );
	}

	return res;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int m, stop, l = 0, r, p = 0;
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		basic.push_back ( stop );
	}

	sort ( basic.begin(), basic.end() );

	r = *( basic.end() - 1 ) - basic[0];

	while ( r >= l ){
		p = ( l + r ) >> 1;
		check ( p ) < m ? l = p + 1 : r = p - 1;
	}

	while ( check ( p ) < m )
		p++;

	cout << p << '\n';
}