#include<iostream>
using namespace std;
int main(){
	long long n, m, t = 0;
	cin >> n >> m;
	while ( n < m ){
		t++;
		n *= 3;
	}
	cout << t << endl;
}