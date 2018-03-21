#include<iostream>
#include<cmath>

using namespace std;

class dataStruct{
public:
	void doing ( void ){
		getData();
		countTest();
		printAns();
	}

private:
	long long a, b, c;
	bool ans;
	double countTestData;

	void getData ( void ){
		cin >> a >> b >> c;
	}

	void countTest ( void ){
		double countTestData = 0;
		int stop = 0;

		countTestData += sqrt ( b * b - 4 * a * c );
		
		stop += countTestData;
		
		ans = ( countTestData == stop ) ? true : false;
	}

	void printAns ( void ){
		if ( ans == true )
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
};

int main(){
	long long m;

	cin >> m;

	dataStruct data[m];

	for ( int i = 0 ; i < m ; i++ )
		data[i].doing();

	return 0;
}