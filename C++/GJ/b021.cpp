#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct pii{
	int a, b, c;
};

inline bool cmp ( pii a, pii b ){
	if ( a.b == b.b )
		return a.c > b.c;
	return a.b > b.b;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, in, swp, sum, id;
	vector < pii > data;
	pii stp;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stp.a;
		sum = 0;
		for ( int i = 0 ; i < 5 ; i++ ){
			cin >> in;
			sum += in;
			if ( i == 2 ){
				swp = in;
			}
		}
		stp.b = sum, stp.c = swp;
		data.push_back ( stp );
	}
	sort ( data.begin(), data.end(), cmp );
	for ( int i = 0 ; i < n ; i++ ){
		cout << data[i].a << '\n';
	}
}