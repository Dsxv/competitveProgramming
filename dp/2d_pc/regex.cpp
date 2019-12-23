#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e4 + 10 ;
int dp[N][N] ;
class Solution {
public:
    bool solve(string&s , string&p , int i , int j){
        if(i == -1){
            if(j == -1) return 1 ;
            if(p[j] == '*')  return solve(s,p,i,j-2) ;
            return 0 ;
        }
        if(j < 0) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;
        if(p[j] == '*'){
            if(p[j-1] == s[i] || p[j-1] == '.') {
                dp[i][j] = solve(s,p,i-1,j) + solve(s,p,i,j-2) ;
            } else {
                dp[i][j] = solve(s,p,i,j-2) ;
            }
        }else if(p[j] == '.'){
            dp[i][j] = solve(s,p,i-1,j-1) ;
        }else{
            if(p[j] == s[i]) return dp[i][j] = solve(s,p,i-1,j-1) ;
            return dp[i][j] = 0 ;
        }
        return dp[i][j] ;
    }
    
    bool isMatch(string s, string p) {
        for(int i = 0 ; i <= s.size() ; i++){
            for(int j = 0 ; j <= p.size() ; j++ ) dp[i][j] = -1 ;
        }
        return solve(s,p,s.size()-1,p.size()-1) ;   
    }
}ss;
int32_t main(){
	string s , p ;
	cin >> s >> p ;
	cout << ss.isMatch(s,p)  ;	
	return 0 ;
}

