#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	if(n < m){
		cout << n ;
		return 0;
	}
	int lo = 0 , hi = sqrt(LLONG_MAX-10) ;
	int ans = 0 ;
	while( lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(n <= (mid*(mid+1)/2) || n <= (mid*(mid-1)/2 + m + mid)){
			hi = mid - 1 ;
			ans = mid ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << m + ans ;
	return 0 ;
}

