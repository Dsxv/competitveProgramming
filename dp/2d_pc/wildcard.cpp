#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 5e3 + 5 ;
int dp[N][N] ;
class Solution {
public:
    bool solve(string&s , string&p , int i = 0 , int j = 0){
        if(i == s.size()){
            if(j == p.size()) return true ;
            if(p[j] == '*') return solve(s,p,i,j+1) ;
            return false ;
        }
        if(j == p.size()) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;
        if(p[j] == '*'){
            return dp[i][j] =  (solve(s,p,i+1,j) + solve(s,p,i,j+1));
        }else if(p[j] == '?'){
            return dp[i][j] = solve(s,p,i+1,j+1) ;
        }else{
            if(s[i] != p[j]) return false ;
            return dp[i][j] = solve(s,p,i+1,j+1) ;
        }
    }
    
    bool isMatch(string s, string p) {
        for(int i = 0 ; i <= s.size() ; i++){
            for(int j = 0 ; j <= p.size() ; j++ ) dp[i][j] = -1 ;
        }
        return solve(s,p) ;
    }
} s;
int32_t main(){
	string a , b ;
	cin >> a >> b ;
	cout << s.isMatch(a,b) ;
	return 0 ;
}

