#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		cout << ceil(log2(n+1)) << '\n' ;
	}
	return 0 ;
}

