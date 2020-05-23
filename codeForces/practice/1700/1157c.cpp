#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n ;
	deque<int> q ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		q.push_back(x) ;
	}
	int x = 0 ;
	string s = "" ;
	while(q.size()){
		if(x >= q.front() && x >= q.back()){
			break ;
		}
		if(q.front() < q.back()){
			if(q.front() > x){
				s += "L" ; 
				x = q.front() ; 
				q.pop_front() ;
			} else {
				s += "R" ;
				x = q.back() ;
				q.pop_back() ;
			}
		} else if(q.front() > q.back()) {
			if(q.back() > x){
				s += "R" ;
				x = q.back() ;
				q.pop_back() ;
			} else {
				s += "L" ;
				x = q.front() ;
				q.pop_front() ;
			}
		} else {
			vector<int> v(q.begin() , q.end()) ;
			int n = v.size() ;
			string x = "L" ;
			string mx = "R" ;
			for(int i = 1 ; i < v.size() ; i++){
				if(v[i] <= v[i-1]) {
					break ;
				} else {
					x += "L" ;
				}
			}
			for(int i = n - 2 ; i >= 0 ; i--){
				if(v[i] <= v[i+1]) {
					break ;
				} else {
					mx += "R" ;
				}
			}
			if(x.size() > mx.size()){
				s += x ;
			} else {
				s += mx ;
			}
			break ;
		}
	}
	cout << s.size() << endl << s ;
	return 0 ;
}

