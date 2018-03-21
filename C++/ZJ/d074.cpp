#include<iostream>
using namespace std;
int main(){
	long long a,max = 0;
	cin >> a;
	for ( int i = 0 ; i < a ; i++ ){
		long long data;
		cin >> data;
		if ( data > max ){
			max = data;
		}
	}
	cout << max << endl;
	return 0;
}
