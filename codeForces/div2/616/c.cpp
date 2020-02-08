#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m , k ;
		cin >> n >> m >> k;
		m--;
		if(k > m) k = m ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int ans = INT_MIN ;
		for(int i = 0 ; i <= k ; i++){
			// the uncontrolled people have turn of m - k
			int min_ans = INT_MAX ;
			for(int j = i ; j <= i + m - k ; j++){
					min_ans = min(min_ans , max(a[j],a[n+j-m-1])) ;
			}
			ans = max(min_ans,ans) ;
		}
		cout << ans << endl;
	}
	return 0 ;
}

