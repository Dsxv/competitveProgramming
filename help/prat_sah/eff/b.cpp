##include <bits/stdc++.h>
using namespace std ;

#define int long long

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size() ;
        vector<int> v(n) ;
        stack<int> a ;
        for(int i = 0 ; i < n ; i++){
            while(a.size() && s[i] > s[a.top()]){
                v[a.top()] = i ;
                a.pop() ;
            }
            a.push(i) ;
        }
        while(a.size()){
            v[a.top()] = n ;
            a.pop() ;
        }
        string ans = "";
        for(int i = 0 ; i < n ;){
            if((v[i] - i) <= k) {
                k -= (v[i]-i) ;
                i = v[i] ;
            } else {
                ans += s[i++] ;
            }
        }
        return ans ;
    }
};
		
int32_t main(){
	int n , m ;
	cin >> n >> m ;
	Solution sol ;
	string s;
	cin >> s ;
	cout << sol.removeKdigits(s,m) ;
	return 0 ;
}
