#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	long long x1, x2, y1, y2, x, y;
	double ans;
	cin >> x1 >> y1 >> x2 >> y2;
	x = fabs ( x1 - x2 );
	y = fabs ( y1 - y2 );
	ans = sqrt ( x * x + y * y );
	cout << fixed <<  setprecision ( 3 ) << ans << endl;
}