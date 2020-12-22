#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		deque<int> q ;
		for(int i = 0 ; i < n ; i++) {
			int x ; cin >> x ;
			q.push_back(x) ;
		}
		bool tp = 0 ;
		while(q.size()){
			if(tp){
				cout << q.back() << " " ;
				q.pop_back() ;
			} else {
				cout << q.front() << " " ;
				q.pop_front() ;
			}
			tp ^= 1 ;
		}
		cout << '\n' ;
	}
	return 0 ;
}

