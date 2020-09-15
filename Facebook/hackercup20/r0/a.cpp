#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int n ;
	cin >> n ;
	bool ok1[n] = {} , ok2[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		char ch ; cin >> ch ;
		ok2[i] = ch == 'Y' ;
	}
	for(int i = 0 ; i < n ; i++){
		char ch ; cin >> ch ;
		ok1[i] = ch == 'Y' ;
	}
	vector<vector<char>> ans(n,vector<char>(n,'N')) ;
	for(int i = 0 ; i < n ; i++){
		queue<int> q ;
		int visited[n] = {} ;
		q.push(i) ; visited[i] = 1 ;
		while(q.size()){
			int x = q.front() ; q.pop() ;
			ans[i][x] = 'Y' ;
			if(x-1>= 0 && ok1[x] && ok2[x-1] && !visited[x-1]){
				q.push(x-1) ;
				visited[x-1] = 1 ;
			}
			if(x+1 < n && ok1[x] && ok2[x+1] && !visited[x+1]){
				q.push(x+1) ;
				visited[x+1] = 1 ;
			}
		}
	}
	for(auto i : ans){
		for(auto j : i) cout << j ;
		cout << '\n' ;
	}
}


int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ":\n";
		gogogo() ;
	}	
	return 0 ;
}


