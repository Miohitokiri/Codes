#include<iostream>
using namespace std;
int main(){
	long long n, k;
	while ( cin >> n >> k ){
		string data[n];
		for ( int i = 0 ; i < n ; i++ )
			cin >> data[i];
		n -= k;
		cout << data[n] << endl;
	}
}