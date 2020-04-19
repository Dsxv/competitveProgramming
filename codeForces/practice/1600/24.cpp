#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10 ; // change this according to n

struct DSU{
	int parent[N] , val[N] ;
	DSU(){
		for(int i = 0 ; i < N ; i++) {
			parent[i] = i ;
			val[i] = 1 ;
		}
	}
	int gp(int v){ //get_parent
		if(v == parent[v])
			return v ;
		return parent[v] = gp(parent[v]) ;
	}
	bool merge(int a , int b){
		a = gp(a) , b = gp(b) ;
		if(a == b) return true ;
		if(val[a] < val[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		val[a] += val[b] ;
		return true ;
	}
} dsu ;

vector<int> G[N] ;

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	string s[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i] ;
		for(int j = 0 ; j < n ; j++){
			if(s[i][j] == '1'){
				dsu.merge(i,j) ;
			}
		}
	}
	map<int,vector<int>> mp ;
	for(int i = 0 ; i < n ; i++){
		mp[dsu.gp(i)].push_back(i) ;
	}
	int ans[n] ;
	for(auto i : mp){
		vector<int> v ;
		for(auto j : i.second){
			v.push_back(a[j]) ;
		}
		sort(v.begin(),v.end()) ;
		for(int j = 0 ; j < v.size() ; j++){
			ans[i.second[j]] = v[j] ;
		}
	}
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}


