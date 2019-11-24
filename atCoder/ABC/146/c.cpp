#include <bits/stdc++.h>
using namespace std ;

#define int long long

int gd(int n){
	return n?gd(n/10)+1:0;
}

int32_t main(){
	int a , b , x ;
	cin >> a >> b >> x ;
	int f = 1 , s = 1e9 ;
	int ans = 0 ;
	while(f <=s ){
		int mid = (f+s)/2 ;
		if(a*mid + b*gd(mid) <= x){
			ans = mid ;
			f = mid + 1 ;
		}else{
			s = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

