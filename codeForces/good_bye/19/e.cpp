#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 1e5 + 10 ; // change this according to n

struct DSU{
	int n = MAXN  ;
	int parent[MAXN] , size[MAXN] ;
	DSU(){
		for(int i = 0 ; i < n ; i++) {
			parent[i] = i ;
			size[i] = 1 ;
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
		if(size[a] < size[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		size[a] += size[b] ;
		return true ;
	}
} dsu ;

map<double,vector<int>> G[MAXN] ;

int32_t main(){
	map<double,set<pair<int,int>>> mp;
	int n ;
	cin >> n ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++) cin >> p[i].first >> p[i].second ;
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			int x1 = p[i].first , y1 = p[i].second , x2 = p[j].first , y2 = p[j].second ;
			double d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ;
			d = sqrt(d) ;
			mp[d].insert({i,j}) ;
		}
	}
	for(auto x : mp){ cout << x.first << endl ;
		for(auto i : x.second){
			cout  <<i.first+1 << ":" << i.second+1 << endl ;
			dsu.merge(i.first,i.second) ;
		}
	}
	//for(int i = 0 ; i < n ; i++){
		//if(G[i].size()){<F2>
			//for(auto j : G[i]){ //G[i] is map of vector
				//vector<int>&v = j.second ;
				//if(v.size()){
					//int x = v[0] ;
					//for(auto k : v) dsu.merge(x,k) ;
				//} 
			//}
		//}
	//}
	int pr = dsu.gp(0) ;
	vector<int> ans ;
	for(int i = 0 ; i < n ; i++){
		if(dsu.gp(i) == pr) ans.push_back(i+1) ;
	}
	cout << ans.size() << '\n' ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}


