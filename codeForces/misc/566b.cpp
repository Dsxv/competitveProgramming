#include <bits/stdc++.h>
using namespace std ;

#define int long long

char ch[505][505] ;
int n , m ;

int solve(int xi , int yi , int dx , int dy){
	if(xi < 0 || xi >= n || yi < 0 || yi >= m || ch[xi][yi] != '*') return 0 ;
	return 1 + solve(xi+dx,yi+dy,dx,dy) ;
}

int32_t main(){
	cin >> n >> m ;
	int cnt = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) {
			cin >> ch[i][j] ;
			cnt += ch[i][j] == '*' ;
		}
	}
	bool ok = false ;
	for(int i = 1 ; i < n - 1 ; i++){
		for(int j = 1 ; j < m - 1 ; j++){
			if(ch[i][j] == '*'){
				int l = solve(i,j-1,0,-1) ;
				int r = solve(i,j+1,0,1) ;
				int u = solve(i-1,j,-1,0) ;
				int d = solve(i+1,j,1,0) ;
				if(l && r && u && d){
					if(cnt == 1 + l + r + u + d){
						ok = true ;
					} else {
						cout << "NO" ;
						return 0 ;
					}
				}
			}
		}
	}
	cout << (ok?"YES":"NO") ;
	return 0 ;
}
