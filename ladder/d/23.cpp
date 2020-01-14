#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5005 ;
int a[N][N] , b[N][N] ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m;
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		string s ;
		cin >> s ;
		for(int j = 0 ; j < s.size() ; j++) a[i][j] = s[j] - '0' ;
	}
	for(int i = 0; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			b[j][i] = a[i][j] ;
		}
	}
	swap(n,m);
	for(int j = 0 ; j < m ; j++){
		a[0][j] = b[0][j] ;
	}
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			a[i][j] = (a[i-1][j]+b[i][j])*(b[i][j]) ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		sort(a[i],a[i]+m) ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			ans = max(ans,a[i][j]*(m-j)) ;
		}
	}
	cout << ans ;
	return 0 ;
}

