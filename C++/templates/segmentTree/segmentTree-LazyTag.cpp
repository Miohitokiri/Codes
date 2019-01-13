#include<bits/stdc++.h>
#define maxn 1000005
#define x first
#define y second

using namespace std;
typedef pair < int, int > lazy;
typedef pair < lazy, int > dLazy;

vector < lazy > seg[maxn * 4];
// first -> q
// second -> x
lazy value;

inline void modify ( int, int, int, int, int );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, type, l, r, x, p, q = 0, count = 0, ans[maxn] = { 0 }, mid;
	vector < dLazy > query;
	// first -> first -> p
	// first -> second -> x
	// second -> count
	vector < lazy > stop;
	// first -> p
	// second -> x
	cin >> n >> m;
	while ( m-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> l >> r >> x;
			value = make_pair ( ++q, x );
			modify ( l, r, 0, n - 1, 1 );
		}
		else{
			cin >> p >> x;
			query.push_back ( make_pair ( make_pair ( p, x ), count++ ) );
		}
	}

	sort ( query.begin(), query.end() );

	for ( auto i: query ){
		cout << 111 << '\n'; // del

		if ( !i.x.x ){
			ans[i.y] = 0;
			continue;
		}

		l = 0, r = n, mid = ( l + r ) / 2, p = 1;

		while ( mid != i.x.y ){
			if ( mid < i.x.y ){
				cout << "r\n"; //del

				l = mid, p *= 2 + 1; // find rightSon
			}
			else if ( i.x.y < mid ){
				cout << "l\n"; //del

				r = mid, p *= 2; // find leftSon
			}

			for ( auto j: seg[p] )
				stop.push_back ( j );

			mid = ( l + r ) / 2;
		}

		sort ( stop.begin(), stop.end() );

		for ( int j = 0 ; stop[j].x < i.x.x ; j++ )
			ans[i.y] ^= stop[j].y;

		stop.clear();
	}

	for ( int i = 0 ; i < count ; i++ )
		cout << ans[i] << '\n';
}

inline void modify ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		seg[n].push_back ( value );
	else{
		int nowMid = ( nowL + nowR ) / 2, leftSon = n * 2, rightSon = n * 2 + 1;

		if ( r <= nowMid )
			modify ( l, r, nowL, nowMid, leftSon );
		else if ( nowMid < l )
			modify ( l, r, nowMid + 1, nowR, rightSon );
		else{
			modify ( l, nowMid, nowL, nowMid, leftSon );
			modify ( nowMid + 1, r, nowMid + 1, nowR, rightSon );
		}
	}
}