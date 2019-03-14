#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
typedef long long LL;
typedef pair < int, int > pii;
typedef pair < LL, LL > pLL;
// template < class T > using vec < T > = vector < t >;
typedef vector < int > vi;
typedef set < int > si;
typedef vector < LL > vl;
#define REPP(i,s,t) for ( int i = s ; i < t ; i++ )
#define REPALL(i,data) for ( auto &i: data )

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int ans = 0;
	set < pii > lib;
	double n, h = 0, m = 0, swp;
	cin >> n;
	if ( n >= 360 )
		n -= 360.0;
	n = min ( n, 360 - n );
	REPP ( i, 0, 12 ){
		REPP ( j, 1, 61 ){
			h += 0.5;
			m += 6;
			swp = fabs ( h - m );
			swp = min ( swp, 360 - swp );
			if ( swp == n ){
				ans++;
				lib.insert ( pii ( i, j ) );
			}
			if ( m == 360 ){
				m = 0;
				swp = fabs ( h - m );
				swp = min ( swp, 360 - swp );
				if (  swp == n ){
					lib.insert ( pii ( i, j ) );
				}
			}
		}
	}
	cout << lib.size() * 2 << '\n';
}