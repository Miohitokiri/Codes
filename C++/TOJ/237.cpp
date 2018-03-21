#include<iostream>
using namespace std;
int main(){
	long long A[3], B[3], C[3], ans = 0;
	for ( int i = 0 ; i < 3 ; i++ )
		cin >> A[i];
	for ( int i = 0 ; i < 3 ; i++ )
		cin >> B[i];
	for ( int i = 0 ; i < 3 ; i++ )
		cin >> C[i];
	ans += B[1];
	ans += C[1];
	ans -= A[0];
	ans -= A[2];
	ans /= 2;
	cout << "4 " << ans << endl;
	return 0;
}