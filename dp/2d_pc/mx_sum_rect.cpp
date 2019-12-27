#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<int>& a ){
	int n = a.size() ;
	int mx = *max_element(a.begin(),a.end()) ;
	if(mx <= 0) return mx ;
	int ans = 0 , cur = 0;
	for(int i = 0 ; i < n ; i++){
		cur += a[i] ;
		if(cur < 0) cur = 0 ;
		ans = max(cur , ans ) ;
	}
	return ans ;
}


int32_t main(){
	int t; 
	cin >> t ;
	while(t--){	
		int n , m ;
		cin >> n >> m ;
		int row[n+1][m+1] = {} ;
		
		int a[n+1][m+1] ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++) cin >> a[i][j] ;
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++) row[i][j] += row[i-1][j] + a[i][j] ;
		}
		int ans = INT_MIN ;
		for(int i = 1 ; i <= n ; i++){
			vector<int> v(m) ;
			for(int i2 = i ; i2 <= n ; i2++){
				for(int j = 1 ; j <= m ; j++){
					v[j-1] = row[i2][j] - row[i - 1][j] ;
				}
				ans = max(ans,solve(v)) ;	
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}

