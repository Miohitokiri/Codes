#include<iostream>
using namespace std;
int main(){
	long long n, m, big = 0, small = 0;
	cin >> n;
	long long array[n];
	for ( int i = 0 ; i < n ; i++ )
		cin >> array[i];
	cin >> m;
	for ( int i = 0 ; i < n ; i++ ){
		if ( array[i] > m )
			big++;
		if ( array[i] < m )
			small++;
	}
	cout << big << " " << small << endl;

}