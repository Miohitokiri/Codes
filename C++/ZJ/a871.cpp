#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n;
	cin >> n;
	n++;
	long long data[n][2];
	long long ans = 0;
	for ( int i = 0 ; i < n - 1 ; i++ )
		cin >> data[i][1] >> data[i][0];
	data[n][0] = data[0][0];
	data[n][1] = data[0][1];
	for ( int i = 1 ; i < n ; i++ ){
		ans += data[i][0] * data[i + 1][1];
		ans -= data[i - 1][0] * data[i][1];
	}
	ans /= 2;
	cout << fixed <<  setprecision(2) << fabs ( ans ) << endl;
	return 0;
}