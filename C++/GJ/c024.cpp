#include<iostream>
using namespace std;
int main(){
	long long n, min = 100000, max;
	cin >> n;
	for ( int dd = 0 ; dd < n ; dd++ ){
		long long stop;
		cin >> stop;
		( max < stop ) ? max = stop : max;
		( min > stop ) ? min = stop : min;
	}
	max -= min;
	cout << max << endl;
}