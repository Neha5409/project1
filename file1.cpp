#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define endl '\n'
#define pi 3.1415926536
#define inf 1e15
using namespace std;

vector<vector<pair<ll,int>>>adj(100007);
ll dist[100007],arr[100007];
bool vis[100007];
void dijkstra(int src, int n){
    
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;
    for(int i=1;i<=n;i++){
        dist[i]=inf;
    }
    dist[src]=0;
    arr[src]=-1;
    pq.push(mp(0,src));
    while(!pq.empty()){ 
        int u=pq.top().second;
        pq.pop();
        vis[u]=true;
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].first;
            int w=adj[u][j].second;
            if(!vis[v] && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                arr[v]=u;
                pq.push(mp(dist[v],v));
            }
        }
        
    }
    
    if(dist[n]>=inf)cout<<-1;
    else{
        int i=n;
        vector<int>ans;
        while(i!=-1){
            ans.pb(i);
            i=arr[i];
        }
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
        int x,y;
        ll w;
        cin>>x>>y>>w;
        adj[x].pb(mp(y,w));
        adj[y].pb(mp(x,w));
    }
    dijkstra(1,n);
    
    return 0;
}
