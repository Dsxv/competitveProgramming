#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int l = 0 , sum = 0 , ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum += a[i] ;
		while(l < i && sum > x){
			sum -= a[l++] ;
		}
		if(sum < x) continue ;
		ans++ ;
	}
	cout << ans ;
	return 0 ;
}



