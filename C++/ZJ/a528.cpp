#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		long long data[n];
		for ( int i = 0 ; i < n ; i++ ){
			cin >> data[i];
		}
		sort ( data,data + n);
		for ( int i = 0 ; i < n ; i++ ){
			cout << data[i] << endl;
		}
	}
	return 0;
}
