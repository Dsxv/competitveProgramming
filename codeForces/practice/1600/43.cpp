#include <bits/stdc++.h>
using namespace std ;

#define int long long

char ch[105][105] ;

set<int> st ;
int n , m ;

void solve(int f , int s , int m , int j){
	if(j == m || f >= s){
		return ;
	}
	if(st.count(j)) {
		solve(f,s,m,j+1) ;
		return ;
	}
	int l = f , r = f ;
	for(int i = f+1 ; i <= s ; i++){
		if(ch[i][j] != ch[i-1][j]){
			if(ch[i][j] < ch[i-1][j]){
				st.insert(j) ;
				solve(f,s,m,j+1) ;
				return ;
			} else {
				solve(l,r,m,j+1) ;
				l = i , r = i ;
			}
		} else {
			r++ ;
		}
	}
	solve(l,r,m,j+1) ;
}

int32_t main(){
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> ch[i][j] ;
		}
	}
	solve(0,n-1,m,0) ;
	cout << st.size() ;
	return 0 ;
}

