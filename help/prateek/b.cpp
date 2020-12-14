#include <bits/stdc++.h>
using namespace std ;

#define int long long


struct DSU{
	vector<int> parent , val ;
	int N ;
	DSU(){
		N = 10 ;
	}
	DSU(int n){
		N = n ;
		parent.resize(n) ;
		val.resize(n) ;
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
		return false ;
	}
} ;

struct pt{
	int x , y ;
	double dis ;
	pt(int a , int b , double c){
		x = a , y = b , dis = c ;
	}
} ;

double dist(pair<int,int> a , pair<int,int> b){
	int x = a.first - b.first ;
	int y = a.second - b.second ;
	double dis = x * x + y * y ;
	if(dis == 1) return 0 ;
	return sqrt(dis) ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		vector<pt> edges ;
		vector<pair<int,int>> p(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i].first >> p[i].second ;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 1 ; j < n ; j++){
				edges.push_back(pt(i , j , dist(p[i] , p[j]))) ;
			}
		}
		sort(edges.begin() , edges.end() , [&](pt a , pt b){
				return a.dis < b.dis ;
		}) ;
		double sum = 0 ;
		DSU dsu(n) ;
		for(auto i : edges){
			if(dsu.merge(i.x , i.y)) continue ;
			sum += i.dis ;
		}
		cout <<fixed <<  setprecision(6) << sum << '\n' ;
	}
	return 0 ;
}


