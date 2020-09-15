#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<int> v ;
vector<vector<int>> ans ;
int n ;
void solve(vector<int>&total , int& sum , vector<vector<int>> cur , int i = 0){
	if(i == (int)total.size()){
		for(int j = 0 ; j < (int)cur.size() ; j++){
			if(accumulate(cur[j].begin() , cur[j].end() , 0LL) != sum) return ;
			if((int)cur[j].size() != v[j]) return ;
		}
		ans = cur ;
		return ;
	}
	for(int j = 0 ; j < n ; j++){
		cur[j].push_back(total[i]) ;
		solve(total , sum , cur , i + 1) ;
		cur[j].pop_back() ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	cin >> n ;
	vector<int> total ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		v.push_back(x) ;
		while(x--){
			int m ; cin >> m; 
			total.push_back(m) ;
		}
	}
	int sum = accumulate(total.begin() , total.end() , 0LL) ;
	sum /= n ;
	vector<vector<int>> cur(n) ;
	solve(total , sum , cur) ;
	map<int,int> mp ;
	for(int i = 0 ; i < (int)ans.size() ; i++){
		mp[i] = *min_element(ans[i].begin() , ans[i].end()) ;
	}
	pair<int,vector<int>> p[n] ;
	for(int i = 0 ; i < n ; i++) p[i] = {i , ans[i]} ;
	sort(p , p + n , [&](pair<int,vector<int>> a , pair<int , vector<int>> b){
			return mp[a.first] < mp[b.first] ;
			}) ;
	for(int i = 0 ; i < n ; i++) {
		sort(p[i].second.begin() , p[i].second.end()) ;
		for(auto j : p[i].second) cout << j << " " ;
		cout << endl ;
	}
	return 0 ;
}

