#include <bits/stdc++.h>
using namespace std ;

#define int long long

int ans ;

int solve(int x , int y , int z){
	return (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z) ;
}

int ff(int l , int m , int n , int * a , int * b , int * c){
	int x = 0 , y = 0 ;
	int ans = LLONG_MAX ;
	for(int i = 0 ; i < l ; i++){
		while(x < m && b[x] <= a[i]) x++ ;
		if(x){
			int f1 = (a[i]+b[x-1]) / 2 ;
			int tp = lower_bound(c,c+n,f1) - c ;
			tp = min(tp,n-1) ;
			ans = min(ans,solve(a[i],c[tp],b[x-1])) ;
		}
	}
	return ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
			int l , m , n ;
			cin >> l >> m >> n ;
			int a[l] , b[m] , c[n] ;
			for(int i = 0 ; i < l ; i++) cin >> a[i] ;
			for(int i = 0 ; i < m ; i++) cin >> b[i] ;
			for(int i = 0 ; i < n ; i++) cin >> c[i] ;
			sort(a,a+l) ; sort(b,b+m) ; sort(c,c+n) ;
			ans = LLONG_MAX ;
			ans = min(ans , ff(l,m,n,a,b,c)) ;
			ans = min(ans , ff(l,n,m,a,c,b)) ;
			ans = min(ans , ff(m,l,n,b,a,c)) ;
			ans = min(ans , ff(m,n,l,b,c,a)) ;
			ans = min(ans , ff(n,l,m,c,a,b)) ;
			ans = min(ans , ff(n,m,l,c,b,a)) ;
			cout << ans << '\n';
	}
	return 0 ;
}

