#include <bits/stdc++.h>
using namespace std ;

#define int long long
class Solution {
public:
    int n ;
    int solve(int* dp , map<int,int>& meep,  vector<bool>& visited, map<int,set<int>> mp ,  vector<int>& a , int cur = 0){
        if(cur < 0 || cur >= n) return n*100 ;
		if(visited[cur]) return n*100 ; 
        if(cur == (n-1)){
            return 0 ;
        }
        visited[cur] = 1 ;
        int ans = n-1-cur ;
		if(!meep.count(a[cur])) {
			set<int> s = mp[a[cur]] ;
        	for(auto i : mp[a[cur]]){
            	ans = min(1 + solve(dp,meep,visited,mp,a,i) , ans) ;
        	}
			dp[cur] = ans ;
			for(auto i : mp[a[cur]]) {
				dp[i] = min(dp[i],ans+1) ;
			}
			meep[a[cur]] = 1 ;
		}
        ans =  min({ans,solve(dp,meep,visited,mp,a,cur-1),solve(dp,meep,visited,mp,a,cur+1)}) ;
		visited[cur] = 0 ;
        return dp[cur] = ans ;
    }
    
    int minJumps(vector<int>& a) {
        n = a.size() ;
        int dp[n] ;
        vector<bool> visited(n) ;
        map<int,set<int>> mp ;
        for(int i = 0 ; i < n ; i++){
            mp[a[i]].insert(i) ;
        }
        memset(dp,-1,sizeof(dp)) ;
		map<int,int> meep ;
        int ans = solve(dp,meep,visited,mp,a) ;
		return ans ;
    }
};
int32_t main(){
	Solution s ;
	int n ; cin >> n; 
	vector<int> a(n) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << s.minJumps(a) ;
	return 0 ;
}

