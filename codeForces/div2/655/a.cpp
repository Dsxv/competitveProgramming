#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		for(int i = 1 ; i <= n ; i++){
			cout << ((i+1)/2)*2 - 1 << " " ;
		}
		cout << '\n' ;
	}
	return 0 ;
}

