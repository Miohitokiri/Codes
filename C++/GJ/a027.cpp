#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	cout << n;
	for ( int i = n - 1 ; i >= 0 ; i-- )
		cout << " " << i;
	cout << endl;
}