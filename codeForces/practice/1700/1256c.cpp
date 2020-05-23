#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m , d ;
	cin >> n >> m >> d ;
	int a[m] ;
	for(int i = 0 ; i < m ; i++) cin >> a[i] ;
	int ans[n+1] = {} ; 
	int sum = accumulate(a,a+m,0LL) ;
	int cur = 1 ;
	d-- ;
	for(int i = 0 ; i < m ; i++){
		int x = 0 ;
		while(x < d && sum < n){
			sum++ ;
			x++ ;
			cur++ ;
		}
		for(int j = 0 ; j < a[i] ; j++){
			ans[cur] = i+1 ;
			cur++ ;
		}
	}
	if(cur + d <= n){
		cout << "NO" ;
	} else {
		cout << "YES\n" ;
		for(int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
	}
	return 0 ;
}

