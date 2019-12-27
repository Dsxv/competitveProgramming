#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 ;
vector<int> G[N] ;

void dfs(int* a , int start , int parent = -1 , int d = 0){
	a[start] = d ;
	for(auto i : G[start])
		if(i != parent)
			dfs(a,i,start,d+1) ;
}

int32_t main(){
	int n , v ;
	cin >> n >> v ;
	v-- ; // v is where bob is 
	//alice is murderer who is at 1
	for(int i = 0 ; i < n - 1 ; i++) {
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	int a[n] , b[n] ;
	dfs(a,0) ;
	dfs(b,v) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++) {
		if(b[i] < a[i]) ans = max(ans,a[i]) ;
	}
	cout << ans*2;
	return 0 ;
}

