#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 1 , v = 4e3 + 1 ;
bool dp1[N][v]  , dp2[N][v];

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , q ;
	cin >> n >> m >> q ;
	for(int i = 1 ; i <= n ; i++){
		int x ; cin >> x ;
		for(int j = 1 ; j < v ; j++){
			int y = dp1[i-1][j] ;
			y += (j == x) ;
			dp1[i][j] = y%2;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		int x ; cin >> x ;
		for(int j = 1 ; j < v ; j++){
			int y = dp2[i-1][j] ;
			y += (j == x) ;
			dp2[i][j] =  y%2 ;
		}
	} 
	for(int i = 0 ; i < q ; i++){
		int l1 ,r1 , l2 , r2 ;
		cin >> l1 >> r1 >> l2 >> r2 ;
		int count = 0 ;
		for(int j = 0 ; j < v ; j++){
			int val = (dp1[r1][j] - dp1[l1-1][j] + 2) % 2 ;
			int val2 = (dp2[r2][j] - dp2[l2-1][j] + 2 ) % 2;
			count += (val + val2) % 2 ;
		}
		cout << count << '\n' ;
	}
	return 0 ;
}

