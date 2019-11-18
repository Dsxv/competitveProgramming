#include <bits/stdc++.h>
using namespace std ;

double solve(vector<int>* edges , int start , int parent = -1 , int l = 0){
	double ans = 0 ;
	int s = edges[start].size() ;
	if(s == 0) return 0 ;
	if(start && s == 1) return l ;
	for(auto i : edges[start]){
		if( i != parent){
			ans += solve(edges,i,start,l+1) ;
		}
	}
	if(start) return ans/(s-1) ; 
	 return ans/s ;
}
			

int32_t main(){
	int n ; cin >> n ;
	vector<int> edges[n] ;
	for(int i = 0 ; i < n - 1 ; i++ ) {
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		edges[f].push_back(s) ;
		edges[s].push_back(f) ;
	}
	cout << fixed << setprecision(7) << solve(edges,0) ;
	return 0 ;
}

