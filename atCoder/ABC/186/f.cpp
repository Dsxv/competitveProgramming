#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 10 ;
vector<int> row[N] , col[N] , ff[N] ;

struct BIT{
	int n ;
	vector<int> v; 
	BIT(int n){
		this->n = n ;
		v.resize(n) ;
	}
	void update(int ind , int val){
		ind++ ;
		for(int i = ind ; i < n ; i += i&-i){
			v[i] += val ;
		}
	}
	int query(int ind){
		ind++ ;
		int sum = 0 ;
		for(int i = ind ; i > 0 ; i -= i&-i){
			sum += v[i] ;
		}
		return sum ;
	}
} bit(N) ;

int32_t main(){
	int n , m , q ;
	cin >> n >> m >> q ;
	for(int i = 0 ; i < q ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		row[f].push_back(s) ;
		col[s].push_back(f) ;
	}
	for(int i = 0 ; i < n ; i++){
		if(row[i].size() == 0) row[i].push_back(m) ;
		sort(row[i].begin() , row[i].end()) ;
	}
	for(int i = 0 ; i < m ; i++){
		if(col[i].size() == 0) col[i].push_back(n) ;
		sort(col[i].begin() , col[i].end()) ;
	}
	int x = col[0][0] ;
	int y = row[0][0] ;
	int ans = 0 ;
	for(int i = 0 ; i < x ; i++){
		ans += row[i][0] ;
	}
	for(int i = 0 ; i < n ; i++){
		ff[row[i][0]].push_back(i) ;
	}
	
	for(int i = 0 ; i < y ; i++){
		if(i){
			int d = col[i][0] ;
			ans += bit.query(d - 1) ;
		}
		for(auto j : ff[i]) bit.update(j , 1) ;
	}
	cout << ans ;
	return 0 ;
}

