#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
vector<int>idx[10];
int arr[10]={0};
int main() 
{
	int n , m ;
    string str;
    cin>>str;
	cin >> m ;
	n = str.size() ;
   	int i,id=-1,p=0,q=0,x=n-m;
   	for(i = 0; str[i]; i++) {
   		idx[str[i]-'0'].pb(i);
   	}
   	str = "";
    for(i = 9; i >= 0; --i) {
    	int l = idx[i].size();
        while(l > arr[i] && idx[i][arr[i]] < id) {
        	++arr[i];
        }
        if(l > arr[i]) {
        	if(idx[i][arr[i]] - p - q <= m) {
        		str += char(i+'0');
            	id = idx[i][arr[i]++];
            	m -= id-p-q;
            	p = id-q++;
            	if(q == x) {
            		break;
            	}
            	i = 10;
        	}
        }
    }
    cout<<str;
	return 0;
}
