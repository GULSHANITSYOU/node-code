class Solution {
    vector<int> topoSort( vector<vector<pair<int,int>>>&adj,int n){
        
        vector<int>inDeg(n,0); 
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j < adj[i].size();j++){
                int v = adj[i][j].first; 
                inDeg[v]++; 
            }
        }
        
        queue<int>q; 
        vector<int>topsrt; 
        
        for(int i =  0 ; i<n ; i++)
        if(inDeg[i] == 0) q.push(i); 
        
        while(q.size()){
            int u = q.front(); 
            q.pop();
            topsrt.push_back(u); 
            
            for(int i = 0 ; i < adj[u].size() ; i++){
                int v = adj[u][i].first; 
                if(--inDeg[v] == 0)
                q.push(v); 
                
            }
        }
        
        return topsrt; 
        
        
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(N);
        
        for(int i = 0 ; i<M ; i++) {
            int u = edges[i][0];
            int v = edges[i][1]; 
            int w = edges[i][2]; 
            adj[u].push_back({v,w}); 
        }
        
        vector<int>toposort = topoSort(adj,N); 
        
        
        vector<int>path(N,-1) ; 
        
        path[0] = 0 ; 
        
        for(int i = 0 ; i<N ; i++){
            int u = toposort[i]; 
            if(path[u] != -1){
                
                for(int  j = 0  ; j < adj[u].size(); j++){
                    int v = adj[u][j].first; 
                    int w = adj[u][j].second; 
                    
                    if(path[v] == -1){
                        path[v] = path[u] + w; 
                    }else if(path[u]+w < path[v]){
                        path[v] = path[u]+w ; 
                    }
                }
                
                
            }
        }
        
        return path; 
        
    }
};