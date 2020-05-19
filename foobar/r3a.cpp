#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {1,-1,0,0} ;
int yy[4] = {0,0,1,-1} ;

int solve(vector<vector<int>> &v){
	int n = v.size() , m = v[0].size() ;
	bool a[n][m] = {} ;
	queue<vector<int>> q ;
	vector<int> s = {0,0,1} ;
	q.push(s) ;
	a[0][0] = 1 ;
	while(q.size()){
		s = q.front() ;
		if(s[0] == n - 1 && s[1] == m - 1) return s[2] ;
		q.pop() ;
		for(int i = 0 ; i < 4 ; i++){
			int xi = xx[i] + s[0] , yi = yy[i] + s[1] ;
			if(xi >= 0 && xi <= n - 1 && yi >= 0 && yi <= m - 1 && !a[xi][yi] && !v[xi][yi]){
				a[xi][yi] = 1 ;
				vector<int> temp = {xi , yi , s[2] + 1} ;
				q.push(temp) ;
			}
		}
	}
	return INT_MAX ;
}

int solution(vector<vector<int>>& v){
	int n = v.size() , m = v[0].size() ;
	int ans = INT_MAX ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			int x = v[i][j] ;
			v[i][j] = 0 ;
			ans = min(ans, solve(v)) ;
			v[i][j] = x ;
		}
	}
	return ans ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	vector<vector<int>> v(n,vector<int>(m)) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> v[i][j] ;
		}
	}
	cout << solution(v) ;
	return 0 ;
}

