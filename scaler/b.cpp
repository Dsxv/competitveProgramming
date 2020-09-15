#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<int> solve(string s, vector<vector<int> > &B) {
 int n = s.size() ;
 s = 'x' + s ;
 int pre[n+1] = {} ;
 vector<int> v ;
 for(int i = 1 ; i <= n ; i++){
     pre[i] = pre[i-1] + (s[i] == '1') ;
     if(s[i] == '1') {
         v.push_back(i) ;
     }
 }
 vector<int> res ;
 for(auto i : B){
     int l = i[0] , r = i[1] ;
     int lo = 0 , hi = v.size() - 1 ;
     int ans1 = -1 , ans2 = -1 ;
     while(lo <= hi){
         int mid = (lo + hi) / 2 ;
         if(v[mid] >= l){
             ans1 = v[mid] ;
             hi = mid - 1 ;
         } else {
             lo = mid + 1 ;
         }
     }
     if(ans1 >= r || ans1 == -1){
         res.push_back(0) ;
         continue ;
     }
     lo = 0 , hi = v.size() - 1 ;
     while(lo <= hi){
         int mid = (lo + hi) / 2 ;
         if(v[mid] <= r){
             ans2 = v[mid] ;
             lo = mid + 1 ;
         } else {
             hi = mid - 1 ;
         }
     }
     if(ans2 <= l || ans2 == -1){
         res.push_back(0) ;
         continue ;
     }
     res.push_back((r-l+1) - pre[r] + pre[l-1]) ;
 }
 return res ;
}

int32_t main(){
	string s = "0100010010" ;
	int r , c ;
	cin >> r >> c ;
	vector<vector<int>> v(r , vector<int>(c)) ;
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++) cin >> v[i][j] ;
	}
	auto x = solve(s , v) ;
	for(auto i : x) cout << i << " " ;
	return 0 ;
}

