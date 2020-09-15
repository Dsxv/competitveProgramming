#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 5e5 ;
int a[N];

int32_t main(){
	int n; 
	cin >> n ;
	int pos[n] = {} ;
	int val[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		string s; 
		cin >> s ;
		int mn = 0 ;
		int cnt = 0 ;
		for(auto j : s){
			if(j == '(') cnt++ ;
			else cnt-- ;
			mn = min(mn , cnt) ;
		}
		if(cnt >= 0){
			if(mn >= 0) pos[i] = true ;
			if(cnt == 0 && mn >= 0){
				a[cnt]++ ;
			}
			val[i] = cnt ;
		} else {
			mn *= -1 ;
			cnt *= -1 ;
			if(mn <= cnt){
				a[cnt]++ ;
			}
		}
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(!pos[i]) continue ;
		ans += a[val[i]] ;
	}
	cout << ans ;
	return 0 ;
}

