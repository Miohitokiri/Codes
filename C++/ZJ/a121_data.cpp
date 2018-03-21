#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	long long n = sqrt ( 100000000 ), count++;
	bool data[n + 1];
	memset ( data, true, sizeof ( data ) );
	for ( int i = 1 ; i < n + 1 ; i++ )
		for ( int j = 0 ; j < i ; j++ ){
			( i % j == 0 ) ? data[i] = false : data[i] = true;
		}
	for ( int i = 1 ; i <= n ; i++ )
		if ( data[i] ){
			cout << i << ", ";
			count++;
		}
	cout << endl << count << endl;
}