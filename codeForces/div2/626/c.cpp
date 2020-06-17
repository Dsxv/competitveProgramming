#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	string s ;
	cin >> s; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '(') a[i] = 1 ;
		else a[i] = -1 ;
	}
	int l = -1 ;
	int ans = 0 , sum = 0 ;
	bool active = false ;
	for(int i = 0 ; i < n ; i++){
		sum += a[i] ;
		if(sum == -1 && !active){
			l = i ;
			active = true ;
		}
		if(l != -1 && sum == 0){
			ans += (i-l+1) ;
			l = -1 ;
			active = false ;
		}
	}
	if(sum){
		cout << -1 ;
	} else {
		cout << ans ;
	}
	return 0 ;
}

