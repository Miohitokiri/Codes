#include<iostream>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop;
	double es = 0, ms = 0;
	bool ny = false;
	vector < int > english, math;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		math.push_back ( stop );
		ms += stop;
	}
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		english.push_back ( stop );
		es += stop;
	}

	es /= n, ms /= n;

	for ( int i = 0 ; i < n ; i++ )
		if ( math[i] >= ms && english[i] >= es ){
			cout << i + 1 << ' ';
			ny = true;
		}

	if ( !ny )
		cout << "NO";
	cout << '\n';
}