#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int *a , int n){
	int count = 0 ;
	int pre[n+1] ;
	pre[0] = a[0] ;
	for(int i = 1 ; i <= n ; i++) pre[i] = pre[i-1] + a[i] ;
	//for(int i = 0 ; i <= n ; i++) cout << a[i] ;
	int l = 1 , r = n ;
	while(l < r){
		while(l < r && (a[l] == 0)){
			l++ ;
		}
		while(l < r && (a[r] == 0)){
			r-- ;
		}
		if(l == r) break ;
		assert(a[l] && a[r]) ;
		int one_count = pre[r] - pre[l-1] ;
		int len = (r-l+1) ;
		int z_count = len - one_count ;
		int req = one_count - 1 - z_count ;
		int x = l , y = r ;
		if(req > 0){
			while(req){
				if(a[x-1] && a[y+1]) {
					cout << "impossible\n" ;
					return ;
				}
				if(!a[x-1]) x-- , req-- , count++;
				if(!req) break ;
				if(!a[y+1]) y++ , req-- , count++;
			}
		}
		a[l] = 0 , a[r] = 0 ;
		a[x] = 1 , a[y] = 1 ;
		if(a[x+1] == 0) l++ ;
		if(a[y-1] == 0) r-- ;

	}
	cout << count << endl ;
}
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s ;
		cin >> s ;
		int a[n+2] ;
		a[0] = a[n+1] = 1 ;
		for(int i = 1  ; i <= n ; i++){
			a[i] = (s[i-1] - '0') ;
		}
		solve(a,n) ;
	}

	return 0 ;
}

