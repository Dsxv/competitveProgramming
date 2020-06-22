#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e9 ;
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , c;
		cin >> n >> c;
		map<pair<int,int> , vector<int>> mp ;
		for(int i = 0 ; i < n ; i++){
			int x , y ;
			cin >> x >> y ;
			mp[{y-x , (y+N*c)%c}].push_back(x) ;
		}
		int ans = mp.size() ;
		int sum = 0 ;
		for(auto i : mp){
			vector<int> v = i.second ;
			sort(v.begin() , v.end()) ;
			int x = v[v.size() / 2] ;
			for(auto i : v){
				sum += abs(x-i) ;
			}
		}
		cout << ans << " " << sum/c << '\n' ;
	}
	return 0 ;
}


