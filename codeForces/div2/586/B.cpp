#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define int long long

#define f first
#define s second

int32_t main(){
	int n ;
	cin >> n ;
	int a[n+1][n+1] ;
	int ans[n+1] ;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= n ; j++) cin >> a[i][j] ;
	ans[3] = sqrt((a[1][3]*a[2][3])/a[1][2]) ;
	ans[1] = a[1][3]/ans[3] ;
	ans[2] = a[1][2]/ans[1] ;
	for(int i = 4 ; i <= n ; i++) ans[i] = a[1][i]/ans[1] ;
	for(int i = 1 ; i <= n ; i++) cout << ans[i] <<" " ;
	return 0 ;
}

