#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 55 ;
int adj[N][N] = {} ;
int  n;
bool dfs(vector<int>& ans , int start , int des , int pr = -1){
	if(start == des) return true ;
	for(int i = 0 ; i < n ; i++){
		if(adj[start][i] && i != pr){
			ans.push_back(i) ;
			if(dfs(ans,i,des,start)) return true ;
			ans.pop_back() ;
		}
	}
	return false ;
}

vector<int> solve(int st , int des){
	vector<int> ans ;
	ans.push_back(st) ;
	dfs(ans,st,des) ;
	vector<int> pth ;
	for(int i = 0 ; i < ans.size()-1 ; i++){
		pth.push_back(adj[ans[i]][ans[i+1]]) ;
	}
	return pth ;
}

int32_t main(){
	cin >> n ;
	for(int i = 1 ; i <= n-1 ; i++){
		int x , y ;
		cin >> x >> y ;
		x-- , y-- ;
		adj[x][y] = i ;
		adj[y][x] = i ;
	}
	//vector<int> ans = solve(0,3) ;
	//for(auto i : ans) cout << i << " " ;
	vector<int> jp[n][n] ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i+1 ; j <= n ; j++){
			vector<int> v = solve(i,j) ;
			jp[i][j] = v ;
			reverse(v.begin(),v.end()) ;
			jp[j][i] = v;
		}
	}
	int m ; cin >> m ;
	map<int,vector<int>> mp;
	for(int i = 0 ; i < m ; i++){
		int f , s ; cin >> f >> s ;
		f-- , s-- ;
		mp[i] = jp[f][s] ;
	}
	int ans = 0 ;
	for(auto i : mp)
	while(1){	
		int c[n+1] = {} ;
		for(auto i : mp){
			for(auto j : mp[i.first]) c[j]++ ;
		}
		int ind = -1 , count = 0 ;
		for(int i = 0 ; i <= n ; i++){
			if(c[i] > count) {
				ind = i ; count = c[i] ;
			}
		}
		vector<int> del ;
		for(auto i : mp){
			bool ok = false ;
			for(auto j : mp[i.first]){
				ok |= (j == ind) ;
			}
			if(ok) del.push_back(i.first) ;
		}
		for(auto i : del) mp.erase(i) ;
		if(count < 2) {ans += (mp.size()) ; break ;}
	}
	cout << (1<<(n-1-ans)) ;
	return 0 ;
}

