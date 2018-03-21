#include <iostream>
#include <cmath>
using namespace std;

const long double EPS = pow(2,(1E-3));
long double a,b,useless;
int num;
int run_time;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> run_time;
    while(run_time --)    {
        a = 1;
        b = 1;
        cin >> num;
        for(int i = 1;i <= num;i ++) {
            cin >> useless; 
            a *= useless;
        }    
        cin >> num;
        for(int i = 1;i <= num;i ++) {
            cin >> useless; 
            b *= useless;
        }
        if( a * b >= 0 && max(abs(a),abs(b)) / min(abs(a),abs(b)) <= EPS)    {
            cout << 0 << "\n";
        }
        else if(a > b)    cout << 1 << "\n";
        else cout << -1 << "\n";
//        cout << a << endl << b << endl; 
//        cout << "EPS: " << EPS << "\n\n";
    }
    
    
    return 0;
}