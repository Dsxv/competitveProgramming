#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	vector<pair<int,int>> st ;
	for(int i = 0 ; i < n ; i++){
		int sum ; cin >> sum ;
		int count = 1 ;
		// sum/count < s.top().first / s.top(().second
		while(st.size() && (sum*st.back().second) <= (st.back().first*count)){
			sum += st.back().first ;
			count += st.back().second ;
			st.pop_back() ;
		}
		st.push_back({sum,count}) ;
	}
	int i = 0 ;
	cout << fixed << setprecision(10) ;
	for(auto i : st){
		double x = (double)i.first/i.second;
		 for(int j = 0 ; j < (i.second) ; j++){
			cout << x <<'\n';
		 }
	}
	return 0 ;
}

