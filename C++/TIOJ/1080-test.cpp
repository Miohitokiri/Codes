#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define maxn 100000
using namespace std;
int a[maxn+2], bit[maxn+2];
int n;
long long ans;

void add(int i, int x){
	while (i <= n){
		bit[i] += x;
		i += i&-i;
	}
};

int sum(int i){
	int s=0;
	while (i > 0){
		s += bit[i];
		i -= i&-i;
	}
	return s;
};

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kase=1;
	while (cin >> n && n){
		//int a -> bit[maxn], 1<=a<=32-bit, 會爆掉
		//離散化 
		vector<int> v;
		for (int i=0; i<n; i++)
			cin >> a[i],
			v.push_back(a[i]);
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());	//unique (return the last element not removed)
		//a[i] 轉換成離散化後的數字 
		for (int i=0; i<n; i++)
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		
		ans = 0;
		memset(bit, 0, sizeof(bit));
		
		for (int i=0; i<n; i++){
			ans += i-sum(a[i]);			
			add(a[i], 1);
		};
		
		cout << "Case #" << kase++ << ": ";
		cout << ans << '\n';
	}

	return 0;
}