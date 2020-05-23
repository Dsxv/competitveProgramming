#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 105 ;
int g[N][N] ;
int nx[N][N] ;

int32_t main(){
	int n ;
	cin >> n ;
	string s[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i] ;
	}
	int m ;
	cin >> m ;
	int a[m] ;
	map<int,int> mp ;
	for(int i = 0 ; i < m ; i++) {
		cin >> a[i] ;
		a[i]-- ;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(s[i][j] - '0'){
				g[i][j] = 1 ;
				nx[i][j] = j ;
			} else {
				g[i][j] = INT_MAX ;
			}
		}
		nx[i][i] = i ;
		g[i][i] = 0 ;
	}
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(g[i][j] > g[i][k] + g[k][j]){
					g[i][j] = g[i][k] + g[k][j] ;
					nx[i][j] = nx[i][k] ;
				}
			}
		}
	}
	vector<int> ans ;
	ans.push_back(0) ;
	for(int i = 1 ; i < m ; i++){
		if(g[a[ans.back()]][a[i]] < (i-ans.back())){
			assert(ans.back() != (i-1)) ;
			// i - 1 because : it's not present in the answer
			// it's not present means it is reached through the path
			// the next element is certainly i after i - 1
			ans.push_back(i-1) ;
		}
	}
	ans.push_back(m-1) ;
	cout << ans.size() << '\n' ;
	for(auto i : ans) cout << a[i] + 1 << " " ;
	return 0 ;
}

