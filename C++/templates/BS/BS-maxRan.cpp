#incldue<bits/stdc++.h>
#define w first
#define v second

using namespace std;

vector < pait < int, int > > data;
vector < double > y[1005];
int n, k;

inline bool test ( double x ){
	for ( int i = 0 ; i < n ; i++ )
		y[i] = data[i].v - x * data[i].w;

	sort ( y.begin(), y.end() );

	double sum = 0;
	for ( int i = 0 ; i < k ; i++ )
		sum += y[n - i - 1];

	return sum >= 0;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int w, v;
	double l, r, mid;
	while ( cin >> n >> k ){
		if ( !n && !k )
			break;

		while ( n-- ){
			cin >> w >> v;
			data.push_back ( make_pair ( w, v ) );
		}

		l = 0, u = n - 1;
		for ( int i = 0 ; i < 100 ; i++ ){
			mid = ( l + r ) / 2;
			if ( test ( mid ) )
				l = mid;
			else
				r = mid;
		}

		cout << mid << '\n';
	}
}