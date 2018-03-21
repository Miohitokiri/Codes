#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	double x1, x2, r1, r2, y1, y2;
	while ( cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 )
		cout << ( sqrt ( pow ( ( x1 - x2 ), 2 ) + pow ( ( y1 - y2 ), 2 ) ) <= ( r1 + r2 ) ? "Quick in" : "Nearly" ) << '\n';
}