#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s ;
		cin >> s ;
		int cnt = 0 ;
		int val = 0 ;
		for(auto i : s){
			if(i == ')') cnt-- ;
			else cnt++ ;
			if(cnt < 0) val = max(val , -cnt) ;
		}
		cout << val << '\n' ;
	}
	return 0 ;
}

