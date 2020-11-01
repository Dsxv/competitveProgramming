#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct tp{
	int x , y ;
	int dis ;
	tp(int a , int b , int c){
		x = a , y = b , dis = c ;
	}
} ;

int solve(){
		pair<int,int> s , dest ;
		cin >> s.first >> s.second >> dest.first >> dest.second ;
		queue<tp> q ;
		q.push(tp(s.first , s.second , 0)) ;
		set<pair<int,int>> st ;
		st.insert(s) ;
		while(q.size()){
			tp cur = q.front() ;
			q.pop() ;
			int x = cur.x , y = cur.y  , d = cur.dis ;
			if(dest == make_pair(x,y)) return d ;
			pair<int,int> val[4] ;
			val[0] = {x + 2*y , y} ;
			val[1] = {x - 2*y , y} ;
			val[2] = (y + 2*x > 0) ? make_pair(x , y + 2*x) : make_pair(-x , -(y + 2*x)) ;
			val[3] = (y - 2*x > 0) ? make_pair(x , y - 2*x) : make_pair(-x , -(y - 2*x)) ;
			for(int i = 0 ; i < 4 ; i++){
				if(st.count({val[i].first , val[i].second})) continue ;
				q.push(tp(val[i].first , val[i].second , d + 1)) ;
				st.insert({val[i].first , val[i].second}) ;
			}
		}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		cout << solve() << '\n' ;
	}
	return 0 ;
}

