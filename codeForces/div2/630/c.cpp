#include <bits/stdc++.h>
using namespace std ;

#define int long long


struct DSU{
	vector<int> parent , val ;
	DSU(int n){
		parent.resize(n);  
		val.resize(n) ;
		for(int i = 0 ; i < n ; i++) {
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
} ;


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k;
		cin >> n >> k ;
		DSU dsu(n) ;
		string s ;
		cin >> s ;
		for(int i = 0 ; i < k ; i++){
			for(int j = i ; j < n ; j += k){
				dsu.merge(i,j) ;
				dsu.merge(j,n-j-1) ;
			}
		}
		map<int,map<char,int>> mp ;
		map<int,int> col ;
		for(int i = 0 ; i < n ; i++){
			mp[dsu.gp(i)][s[i]]++ ;
		}
		for(auto i : mp){
			int mx = 0 ;
			char ch ;
			for(auto j : i.second){
				if(j.second > mx){
					ch = j.first ;
					mx = j.second ;
				}
			}
			col[i.first] = ch ;
		}
		int count = 0 ;
		for(int i = 0 ; i < n ; i++) {
			count += (s[i] != col[dsu.gp(i)]) ;
		}
		cout << count << '\n' ;
	}
	return 0 ;
}


