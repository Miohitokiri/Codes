#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long data[n];
	for ( int i = 0 ; i < n ; i++ )
		cin >> data[i];
	n--;
	cout << data[n];
	n--;
	for ( int i = n ; i >= 0 ; i-- )
		cout << ' ' << data[i];
	cout << endl;
}