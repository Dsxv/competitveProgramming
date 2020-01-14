#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<vector<int>> & v){
	queue<pair<int,int>> q ;
	q.push({1,0}) ;
	map<int,int> mp ;
	int n = v.size() ;
	mp[1] = 1 ;
	while(q.size()){
		int f = q.front().first - 1 ;
		int d = q.front().second ;
		q.pop() ;
		if(f == n - 1) return d ;
		for(auto i : v[f]){
			if(!mp.count(i)){
				q.push({i,d+1}) ;
				mp[i] = 1 ;
			}
		}
	}
	return -1 ;
}

int32_t main(){
	int n , m;
	cin >> n >> m ;
	vector<vector<int>> ans(n) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			int x ; cin >> x ;
			ans[i].push_back(x) ;
		}
	}
	cout << solve(ans) ;
	return 0 ;
}

