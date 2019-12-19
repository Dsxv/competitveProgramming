#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int n , int m , int x){
	int ans = 0 ;
	for(int i = 1 ; i <= n ; i++) ans += min(x/i,m) ;
	return ans ;
}

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	int lo = 1 , hi = n*m ;
	while(lo <= hi) {
		int mid = (lo + hi) / 2 ;
		int count = solve(n,m,mid) ; //strictly smaller than mid
		//cout << mid <<" " << count << endl ;
		if(count >= k) {
			if(solve(n,m,mid-1) < k) {
				cout << mid ; return 0;
			}
			hi = mid - 1 ;
		} else {
			lo = mid + 1 ;
		}
	}	
	return 0 ;
}

