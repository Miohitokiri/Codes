#include<iostream>
using namespace std;
int main(){
	long long n, data, max;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		long long stop;
		cin >> stop;
		if ( max < stop ){
			max = stop;
			data = i;
		}
	}
	data++;
	cout << data << " " << max << endl;
}