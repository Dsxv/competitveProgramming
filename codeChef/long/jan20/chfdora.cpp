#include <bits/stdc++.h>
using namespace std ;

#define int long long


bool check(int x1 , int y1 , int x2 , int y2 , int n , int m ){
	return x1 >= 0 && x2 >= 0 && y1 < m && y2 < n ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--) {
		int n , m ;
		cin >> n >> m ;
		int a[n][m] ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> a[i][j] ;
			}
		}
		int sum = n*m ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				int x1 , y1 , x2 , y2 ;
				x1 = j - 1 ;
				x2 = i - 1 ;
				y1 = j + 1 ;
				y2 = i + 1 ;
				while(check(x1,y1,x2,y2,n,m)){
					if(a[i][x1] == a[i][y1] && 
						a[x2][j] == a[y2][j]) sum++ ;
					else break ;
					x1-- , x2-- , y1++ , y2++ ;
				}
			}
		}
		cout << sum << '\n';
	}

	return 0 ;
}

