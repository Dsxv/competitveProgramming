#include <bits/stdc++.h>
using namespace std ;

int main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int count = 0 ;
		for(int i = 0 ; i < n ; i++){
			multiset<int> s;
			for(int j = i ; j < n ; j++){
				s.insert(a[j]);
				int x = *(s.begin()) ;
				int y = *(s.rbegin()) ;
				if((y - x) == abs(a[j] - a[i])) {
					count++ ;
				}
			}
		}
		cout << count << '\n' ;
	}
	return 0 ;
}

