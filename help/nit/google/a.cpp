#include <bits/stdc++.h>
using namespace std ;

#define int long long

char xr = 'r' ^ 'p' ;

int solve(string &s , int x , int y){
	if(y > x){
		swap(x,y) ;
		for(auto &i : s) i ^= xr ;
	}
	int cnt = 0 ;
	int p = 0 ;
	int ans = 0 ;
	for(int i = s.size() - 1 ; i >= 0 ; i--){
		if(s[i] == 'r') {
			cnt++ ;
			continue ;
		} else {
			p++ ;
			if(cnt > 0) {
				ans += x ;
				p-- ; cnt-- ;
			}
		}
	}
	cnt = min(cnt , p) ;
	return ans + y*cnt ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string a ;
		cin >> a ;
		int x , y ;
		cin >> x >> y ;
		string b = "" ;
		int ans = 0 ;
		for(auto i : a){
			if(i != 'r' && i != 'p'){
				ans += solve(b,x,y) ;
				b = "" ;
			} else {
				b += i ;
			}
		}
		ans += solve(b,x,y) ;
		cout << ans << '\n' ;
	}
	return 0 ;
}

