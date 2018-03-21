#include<iostream>
#include<cmath>

using namespace std;

int main(){
	long long a = 0, b = 0, ans = 0;

	cin >> a >> b;

	if ( a != b ){
		( a % 2 != 0 ) ? a++ : a;
		( b % 2 != 0 ) ? b-- : b;
		ans += a;
		ans += b;
		ans *=  ( fabs( b - a  ) ) / 2 + 1;
		( ans == 0 ) ? ans : ans /= 2 ;
	}
	else
		( a % 2 != 0 ) ? ans : ans = a;

	cout << ans << endl;
	
	return 0;
}