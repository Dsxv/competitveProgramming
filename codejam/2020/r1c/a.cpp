#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int x , y ;
	cin >> x >> y ;
	string s ;
	cin >> s ;
	int ans = -1 ;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'E'){
			x++ ;
		}
		if(s[i] == 'W'){
			x-- ;
		}
		if(s[i] == 'N'){
			y++ ;
		}
		if(s[i] == 'S'){
			y-- ;
		}
		if((i+1) >= abs(x) + abs(y)){
			ans = i+1 ;
			break ;
		}
	}
	if(~ans){
		cout << ans << '\n' ;
	} else {
		cout << "IMPOSSIBLE\n" ;
	}
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


