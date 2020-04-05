#include <bits/stdc++.h>
using namespace std ;

//#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	for(int x = 1 ; x <= t ; x++){
		int n ;
		cin >> n; 
		int a[n][n] ;
		int sum = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> a[i][j] ;
				if(i == j) sum += a[i][j] ;
			}
		}
		int cnta = 0 , cntb = 0 ;
		for(int i = 0 ; i < n ; i++){
			map<int,int> mp ;
			for(int j = 0 ; j < n ; j++){
				if(mp.count(a[i][j])) {
					cnta++ ;
					break ;
				}
				mp[a[i][j]] = 1 ;
			}
			mp.clear() ;
			for(int j = 0 ; j < n ; j++){
				if(mp.count(a[j][i])){
					cntb++ ;
					break ;
				}
				mp[a[j][i]] = 1 ;
			}
		}
		printf("Case #%d: %d %d %d\n",x,sum,cnta,cntb) ;
	}
	return 0 ;
}

