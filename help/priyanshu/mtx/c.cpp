#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[10] ;
		for(int i = 1 ; i <= 9 ; i++){
			cin >> a[i] ;
		}
		int mn = 1e5 ;
		int id = 9 ;
		for(int i = 9 ; i >= 1 ; i--){
			if(mn > a[i]){
				id = i ;
				mn = a[i] ;
			}
		}
		int l = n / mn ;
		int rem = n % mn ;
		if(l == 0){
			cout << -1 << '\n' ;
			continue ;
		}
		string ans(l , id + '0') ;
		for(int i = 0 ; i < l ; i++){
			for(int j = 1 ; j <= 9 ; j++){
				if((rem + a[ans[i] - '0']) >= a[j]){
					rem += a[ans[i] - '0'] ;
					rem -= a[j] ;
					ans[i] = j + '0' ;
				}
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

