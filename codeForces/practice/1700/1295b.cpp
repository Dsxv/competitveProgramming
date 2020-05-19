#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n  , x;
		cin >> n >> x ;
		string s ;
		cin >> s ;
		int b = count(s.begin(),s.end(),'0') - count(s.begin(),s.end(),'1') ;
		int sum = 0 ;
		int count = 0 ;
		for(auto i : s){
			if(i == '0') sum++ ;
			else sum-- ;
			if(b == 0 && sum == x){
				count = -1 ;
				break ;
			}
			if(b) {
				if(abs(sum-x)%abs(b) == 0 && (x-sum)/b >= 0){
					count++ ;
				}
			}
		}
		if(!x && ~count) count++ ;
		cout << count << endl ;
	}
	return 0 ;
}

