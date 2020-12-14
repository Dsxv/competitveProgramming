#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int n , s , k ;
	cin >> n >> k >> s ;
	cout << min((n - s) + (k - s) , n) + k << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}


