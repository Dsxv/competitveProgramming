#include <bits/stdc++.h>
using namespace std ;

#define int long long

int val(int x){
	return x*(x+1)/2 ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >>  m;
		int k = (n-m) ;
		int count = (m+1-k%(m+1))*val(k/(m+1)) + val(k/(m+1) + 1)*(k%(m+1)) ;
		cout << val(n) - count << '\n' ;
	}
	return 0 ;
}

