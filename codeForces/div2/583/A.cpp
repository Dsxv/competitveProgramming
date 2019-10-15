#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int n , d , e ;
	cin >>n >> d >> e ;
	set<int> s = {d,2*d,5*d,10*d,20*d,50*d,100*d,5*e,10*e,20*e,50*e,100*e,200*e} ;
	vector<int> v(s.begin(),s.end()) ;
	int prev = n ;
	while(true){
		int temp = n ;
		for(int i = 0 ; i < v.size() ; i++){
			temp = min(temp,n%v[i]) ;
		}
		if(prev == temp){
			cout << temp ; return 0 ;
		}else{
			n = temp ;
		}
	}
	// cout << n ;
	
	
	return 0;
}
