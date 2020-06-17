#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int a[n][m] ;
		pair<int,int> val[n+m-1] = {} ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> a[i][j] ;
				if(a[i][j]) val[i+j].second++ ;
				else val[i+j].first++ ;
			}
		}
		int l = n + m - 2 ;
		int ans = 0 ;
		for(int i = 0 ; i <= l / 2 ; i++){
			int j = l - i ;
			if(i == j) continue ;
			ans += min(val[i].first + val[j].first , val[i].second + val[j].second) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

