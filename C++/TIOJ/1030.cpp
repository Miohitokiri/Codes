#include<iostream>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		if ( n == 0 ){
			break;
		}
		else{
			long long max = 0;
			for ( int i = 0 ; i < n ; i++ ){
				long long data;
				cin >> data;
				if ( max < ( data - 1 ) * 2 ){
					max = ( data - 1 ) * 2;
				}
			}
			cout << max + 2 << endl;
		}
	}
	return 0;
}