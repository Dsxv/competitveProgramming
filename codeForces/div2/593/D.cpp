#include <bits/stdc++.h>
using namespace std ;

void doit(vector<int>* row , int& l , int& r , int& u , int& d , int& ans){
	}

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	vector<int> row[n] , col[m] ;
	for(int c = 0 ; c < k ; c++){
		int i , j ; 
		cin >> i >> j ;
		i-- , j-- ;
		row[i].push_back(j) ;
		col[j].push_back(i) ;
	}
	for(int i = 0 ; i < n ; i++) sort(row[i].begin(),row[i].end()) ;
	for(int i = 0 ; i < m ; i++) sort(col[i].begin(),col[i].end()) ;
	int l = 0 , r = m - 1 , d = n - 1 , u = 0 ;
	int ans = 0 ;
	while(l <= r && u <= d){
		if(lower_bound(row[u].begin(),row[u].end(),l) != row[u].end()){
			int ind = lower_bound(row[u].begin(),row[u].end(),l) - row[u].begin() ;
			ans += (r-row[ind]+1)*(d-u+1) ;
			r = row[ind]-1 ;
		}
		u++ ;
		if(u > d || l > r) break ;
		if(lower_bound(col[r].begin(),col[r].end(),u) != col[r].end()){
			int ind = lower_bound(col[r].begin(),col[r].end(),u) - col[r].begin() ;
			ans += (d-col[ind]+1)*(r-l+1) ;
			d = col[ind] - 1 ;
		}
		r-- ;
		
		if(u > d || l > r) break ;

		if(lower_bound(row[d].begin(),row[d].end(),l) != row[d].end()){
			int ind = lower_bound(row[d].begin(),row[d].end(),l) - row[d].begin() ;
			ans += (


		

	return 0 ;
}

