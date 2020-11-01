#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k; 
		cin >> n >> k ;
		pair<int , int> p[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i].first >> p[i].second ;
		}
		sort(p , p + n) ;
		deque<pair<int , int>> q ;
		int ans = INT_MIN ;
		for(int i = 0 ; i < n ; i++){
			pair<int,int> temp = {p[i].second - p[i].first , p[i].first} ;
			while(q.size() && q.front().second < (p[i].first - k)) q.pop_front() ;
			if(q.size()){
				ans = max(ans , p[i].first + p[i].second + q.front().first) ;
			}
			while(q.size() && q.back().first < temp.first){
				q.pop_back() ;
			}
			q.push_back(temp) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

