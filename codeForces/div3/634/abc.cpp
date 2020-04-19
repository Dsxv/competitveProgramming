#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ; // change this according to n

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


int getResult(vector<string>& relation){
	map<string,int> mp ;
	int k = 0 ;
	for(auto i : relation){
		string s = "" , t = "" ;
		bool ok = false ;
		for(int j = 0 ; j < i.size() ; j++){
			if(i[j] == '-'){
				ok = true ;
				continue ;
			}
			if(!ok) s += i[j] ;
			else t += i[j] ;
		}
		cout << s << " : " << t << endl ;
		if(!mp.count(s)) {
			mp[s] = k++ ;
		}
		if(!mp.count(t)) {
			mp[t] = k++ ;
		}
		dsu.merge(mp[s],mp[t]) ;
	}
	int mx = 0 ;
	for(auto i : mp){
		mx = max(mx,dsu.val[dsu.gp(i.second)]) ;
	}
	return mx ;
}


int32_t main(){
	int n ;
	cin >> n ;
	vector<string> v ;
	for(int i = 0 ; i < n ; i++){
		string s ;
		cin >> s ;
		v.push_back(s) ;
	}
	cout << getResult(v) ;
	return 0 ;
}


