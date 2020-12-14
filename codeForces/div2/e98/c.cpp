#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int a = 0 , b = 0 ;
		int ans = 0 ;
		for(auto i : s){
			if(i == '('){
				a++ ;
			} else if(i == '['){
				b++ ;
			} else if(i == ')'){
				if(a) ans++ , a-- ;
			} else {
				if(b) ans++ , b-- ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

