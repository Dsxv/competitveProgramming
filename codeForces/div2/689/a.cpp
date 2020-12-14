#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		string s = "" ;
		string x = "abc" ;
		for(int i = 0 ; i < n ; i++){
			s += x[i % 3] ;
		}
		cout << s << '\n' ;
	}
	return 0 ;
}

