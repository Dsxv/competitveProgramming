#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		string s ;
		cin >> s ;
		int ans = 1 ;
		priority_queue<int> pq ;
		sort(s.begin() , s.end()) ;
		vector<pair<int,int>> v ;
		v.push_back({s[0] , 1}) ;
		for(int i = 1 ; i < n ; i++){
			if(v.back().first == s[i]) {
				v.back().second++ ;
			} else {
				v.push_back({s[i] , 1}) ;
			}
		}

		for(int i = 1 ; i <= n ; i++){
			pq = priority_queue<int> () ;
			for(auto j : v){
				pq.push(j.second) ;
			}
			vector<int> v ;
			int cnt = 0 ;
			int visited[i] = {} ;
			for(int j = 0 ; j < min(i,k) ; j++){
				if(visited[j]) continue ;
				cnt = 0 ;
				int x = j ;
				while(!visited[x]) {
					cnt++ ;
					visited[x] = 1 ;
					x = (k + x) % i ;
				}
				if(cnt)
				v.push_back(cnt) ;
			}
			sort(v.begin() , v.end() , greater<int>()) ;
			bool found = true ;
			for(int j : v){
				int x = pq.top() ;
				if(j <= x){
					pq.pop() ;
					pq.push(x-j) ;
				} else {
					found = false ;
				}
			}
			if(found) {
				ans = i ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

