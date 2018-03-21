#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long a, b;
	cin >> a >> b;
	double ans = log10 ( a );
	ans *= b;
	ans++;
	long long p = ans;
	cout << p << endl;
}