#include <bits/stdc++.h>
using namespace std;

bool DFS(int **arr,int v,int *visited,int st,int end,map<int,int> &m){
    if(st==end)
        return true;
    visited[st]=1;
    bool ans=false;
    for(int i=0;i<v;i++){
        if(arr[st][i]==1){
            if(visited[i]==0){
                m[i]=st;
                 ans=ans||DFS(arr,v,visited,i,end,m);
                if(!ans) m.erase(i) ;
            }
        }
    }
    return ans;
}

int main() {
    map<int,int> m;
    int v, e;
    cin >> v >> e;
    int **arr=new int*[v];
    for(int i=0;i<v;i++)
        arr[i]=new int[v];
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            arr[i][j]=0;
    }
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        arr[f][s]=1;
        arr[s][f]=1;
    }
    
    int st,end;
    cin>>st>>end;
    
   int *visited=new int[v];
    
   if(DFS(arr,v,visited,st,end,m)==true){
       while(end!=st){
           cout<<end<<" ";
          end = m[end];
       }
       cout<<st<<" ";
   }
    

  return 0;
}

