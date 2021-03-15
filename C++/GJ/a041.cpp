#include <iostream>
using namespace std;
int main() {
  long long n, ans = 0;
  cin >> n;
  ans += n;
  while (n >= 5) {
    n -= 5;
    n++;
    ans++;
  }
  cout << ans << endl;
}
