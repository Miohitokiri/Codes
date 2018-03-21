#include<iostream>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		long long data[n];
		for ( int i = 0 ; i < n ; i++ ){
			cin >> data[i];
		}
		for ( int i = 0 ; i < n ; i++ ){
			for ( int j = 0 ; j < i ; j++ ){
				if ( data[i] < data[j] ){
					long long stop;
					stop = data[j];
					data[j] = data[i];
					data[i] = stop;
				}
			}
		}
		for ( int i = 0 ; i < n ; i++ ){
			cout << data[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
