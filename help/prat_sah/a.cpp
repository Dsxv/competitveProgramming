#include <bits/stdc++.h>
using namespace std ;

#define int long long

int suminRange(vector<int>& nums , vector<vector<int>> queries){
	const int mod = 1e9 + 7 ;
	int n = nums.size() ;
	int pre[n+1] = {} ;
	for(int i = 1 ; i <= n ; i++){
		pre[i] = (nums[i-1] + pre[i-1] + mod ) % mod ;
	}
	int ans = 0 ;
	for(auto i : queries){
		ans = (ans +  (pre[i[1] + 1] - pre[i[0]] + mod)) % mod ;
	}
	return ans ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	vector<int> v(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> v[i] ;
	}
	vector<vector<int>> queries(m , vector<int>(2)) ;
	for(int i = 0 ; i < m ; i++) {
		cin >> queries[i][0] >> queries[i][1] ;
	}
	cout << suminRange(v ,queries) ;
	return 0 ;
}

