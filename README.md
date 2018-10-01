# project1

#include <bits/stdc++.h>
using namespace std;
int main(){
    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n,k;
        cin>>n>>k;
        int x[n],r[n],q[n];
       // vector<pair<pair<int,int>,int>>v;
        for(int i=0;i<n;i++){
            cin>>x[i]>>r[i]>>q[i];  
        }
      int cnt=0;
      for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              
          if(x[i]+r[i]>x[j]||x[i]-r[i]<x[j]){
              if(abs(q[i]-q[j])<=k) cnt++;
          }
              
              
          }
      }
    cout<<cnt;
    
}
