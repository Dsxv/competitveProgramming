#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 1e6 + 10 ;

int dest , init , n ;

int solve(vector<pair<int,int>> s) {
	int i = 0, res;
	priority_queue<int>pq;
	for (res = 0; init < dest; res++) {
		while (i < s.size() && s[i].first <= init)
			pq.push(s[i++].second);
		if (pq.empty()) return -1;
		init += pq.top(), pq.pop();
	}
	return res;
} 

int32_t main(){
	cin >> dest >> init >> n; 
	vector<pair<int,int>> v(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> v[i].first ;
	}
	for(int i = 0 ; i < n ; i++){
		cin >> v[i].second ;
	}
	cout << solve(v) ;
	return 0 ;
}

