#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int main(){
    int n;
    // freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]=i+1;
    }
    int pre;
    int counter=0;
    cin>> pre;
    for(int i =0;i<n-1;i++)
    {
        int x;
        cin>>x;
        if(mp[x]<mp[pre]) counter++;
        pre = x;
    }
    cout<<counter<<endl;
    
}
