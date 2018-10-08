#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define endl '\n'
#define pi 3.1415926536
using namespace std;

vector<vector<pair<int,int>>>adj(100001);

void dijkstra(int src, int n){
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    
    vector<pair<int,int>> dist(n+1);
    for(int i=1;i<=n;i++){
        dist[i]=mp(INT_MAX,-1);
        pq.push(mp(dist[i].first,i));
    }
    dist[src]=mp(0,src);
    pq.push(mp(dist[src].first,src));
    
    while(!pq.empty()){ 
        int u=pq.top().second;
        pq.pop();
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].first;
            int w=adj[u][j].second;
            if( dist[v].first>dist[u].first+w){
                dist[v]=mp(dist[u].first+w,u);
                pq.push(mp(dist[v].first,v));
            }
        }
        
    }
    
    if(dist[n].first==INT_MAX)cout<<-1;
    else{
        int i=n;
        vector<int>ans;
        ans.pb(n);
        while(dist[i].second!=src){
            ans.pb(dist[i].second);
            i=dist[i].second;
        }
        cout<<1<<" ";
        for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].pb(mp(y,w));
        adj[y].pb(mp(x,w));
    }
    dijkstra(1,n);
    
    return 0;
}
