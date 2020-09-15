#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n; 
	int x[n] , y[n] ;
	for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i] ;
	vector<int> val(4 , -1e10) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 4 ; j++){
			int a = x[i] , b = y[i] ;
			if(1&j){
				a = -a ;
			}
			if((1 << 1) & j){
				b = -b ;
			}
			val[j] = max(val[j] , a + b) ;
		}
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 4 ; j++){
			int a = x[i] , b = y[i] ;
			if(1&j) a = -a ;
			if((1<<1)&j) b = -b ;
			ans = max(ans , a + b + val[3-j]) ;
		}
	}
	cout << ans;
	return 0 ;
}

