#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t;
	while(t--){
		int n , g , b ;
		cin >> n >> g >> b ;
		int tc = (n+1)/2 ;
		int cnt = (tc + g - 1)/g ;
		cout << max(n,tc+(cnt-1)*b) << endl;
	}
	return 0 ;
}

