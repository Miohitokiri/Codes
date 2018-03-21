#include<bits/stdc++.h>
using namespace std;
vector < int >  dataX[1000005];
struct XY{
	int x, y, fly;
} data[1000005];
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, c, x1, x2, y1, y2;
	double delta;
	cin >> n >> c;
	for ( int times = 0 ; times < n ; times++ ){
		cin >> x1 >> y1 >> x2 >> y2;
		delta = ( y2 - y1 ) / ( x2 - x1 );
		x1++, x2++;
		if ( delta > 0 ){
			for ( int j = x1 ; j != x2 ; j++ ){
				data[j].fly = x2;
				dataX[x2].push_back ( j );
			}
		}
		else if ( delta < 0 ){
			for ( int j = x1 ; j != x2 ; j++ ){
				data[j].fly = x1;
				dataX[x1].push_back ( j );
			}
		}
		else{
			for ( int j = x1 ; j != x2 ; j++ ){
			}
		}
	}
}