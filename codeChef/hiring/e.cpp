///code from : https://cp-algorithms.com/data_structures/disjoint_set_union.html?fbclid=IwAR2MtqxYnfiFBquxbvOOBsokuAbkR6WbmjS8iH6sjlCwbfsqVOK4T29PPzs

#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ; // change this according to n

pair<int,int> parent[N] ;
int bipartite[N] ;
int rankk[N] ;

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rankk[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    } else {
        if (rankk[a] < rankk[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (rankk[a] == rankk[b])
            ++rankk[a];
    }
}

bool is_bp(int v) {
    return bipartite[find_set(v).first];
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , q ;
	cin >> n >> q ;
	for(int i = 0 ; i <= n ; i++) make_set(i) ;
	while(q--){
		int t , u , v;
		cin >> t >> u >> v;
		u-- , v-- ;
		if(t == 1){
			add_edge(u,v) ;
		} else {
			pair<int, int> ppa = find_set(u);
		    int a = ppa.first;
		    int x = ppa.second;
		    pair<int, int> ppb = find_set(v);
		    int b = ppb.first;
		    int y = ppb.second;
		    if (a == b) {
		        if (x == y || !bipartite[find_set(a).first]){
		        	cout << "No\n" ;
		        } else {
		        	cout << "Yes\n" ;
		        }
		    }
		    else{
		    	if(bipartite[a] && bipartite[b])
		    	{
		    		cout << "Yes\n" ;
		    	}
		    	else
		    	{
		    		cout << "No\n" ;
		    	}
		    }
		}
	}
	return 0 ;
}


