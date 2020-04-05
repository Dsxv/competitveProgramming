#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
const int N = 1e3 + 10 ;
set<int> G[N] ;

void do_pre(int start , vector<int>& v){
	vector<int> tp(G[start].begin(),G[start].end()) ;
	v.push_back(start) ;
	if(tp.size() == 0){
		return ;
	}
	do_pre(tp[0] , v) ;
	if(tp.size() == 2) do_pre(tp[1], v) ;
}

void do_in(int start , vector<int>& v){
	vector<int> tp(G[start].begin(),G[start].end()) ;
	if(tp.size() == 0){
		v.push_back(start) ;
		return ;
	}
	do_in(tp[0],v) ;
	v.push_back(start) ;
	if(tp.size() == 2) do_in(tp[1], v) ;
}

void do_post(int start , vector<int>& v){
	vector<int> tp(G[start].begin(), G[start].end()) ;
	if(tp.size() == 0){
		v.push_back(start) ;
		return ;
	}
	do_post(tp[0],v) ;
	if(tp.size() == 2) do_post(tp[1], v) ;
	v.push_back(start) ;
}

void print(vector<int>& pre){
	for(auto i : pre) cout << i << " " ;
	cout << endl ;
}

int32_t main(){
	int n ;
	cin >> n ;
	n++ ;
	int st = 0 ;
	for(int i = 1 ; i < n ; i++){
		int p ;
		cin >> p ;
		G[p].insert(i) ;
	}
	vector<int> pre , ino , pos ;
	do_pre(st, pre) ;
	do_in(st, ino) ;
	do_post(st, pos) ;
	//print(pre) ;
	//print(ino) ;
	//print(pos) ;
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		int ar[] = {pre[i],ino[i],pos[i]} ;
		sort(ar,ar+3) ;
		sum = (sum + ar[1]) % mod ;
	}
	cout << sum ;
	return 0 ;
}

