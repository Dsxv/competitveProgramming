#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		int a, b , x , y , z ;
		cin >> n ;
		cin >> a >> b >> x >> y >>  z ;
		int d1 = (z - b + y - 1) / y  ;
		int d2 = (z - a + x - 1) / x ;

		priority_queue<int> pq ;
		for(int i = 0 ; i < n ; i++) {
			int tp ;
			cin >> tp ;
			pq.push(tp) ;
		}
		if(d1 > d2) {
			cout << 0 << '\n' ;
		} else {
			int rem = z - (a + (d1-1)*x) ;
			int count = 0 ;
			while(rem > 0){
				if(pq.size() == 0){
					count = -1 ;
					break ;
				}
				int tp = pq.top() ;
				pq.pop() ;
				rem -= tp ;
				if(tp > 1){
					pq.push(tp/2) ;
				}
				count++ ;
			}
			if(count != -1) cout << count << '\n' ;
			else cout << "RIP\n" ;
		}
	}
	return 0 ;
}

