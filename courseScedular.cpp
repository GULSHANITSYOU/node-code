class Solution {
    bool iscyclic(vector<vector<int>>& graph, int node, vector<bool>& visited,
                  vector<bool>& active) {

        visited[node] = true;
        active[node] = true;

        for (auto i : graph[node]) {
            if (!visited[i] && iscyclic(graph, i, visited, active))
                return true;
            if (visited[i] && active[i])
                return true;
        }

        active[node] = false;

        return false;
    }

    bool isCyclic(vector<vector<int>>& graph, int nodes) {

        vector<bool> visited(nodes, false);
        vector<bool> active(nodes, false);

        for (int i = 0; i < nodes; i++) {
            if (iscyclic(graph, i, visited, active))
                return true;
        }

        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>> &graph) {

        // vector<vector<int>> graph(numCourses);

        // for (auto vec : prerequisites) {
        //     int u = vec[0], v = vec[1];
        //     graph[u].push_back(v);
        // }

        return isCyclic(graph, numCourses) ? false : true;
    }


    void DFS(int node , vector<vector<int>>&graph, vector<bool>&visited, vector<int>&stk){

        visited[node] = true ; 


        for(auto n : graph[node]){
            if(!visited[n])
              DFS(n,graph,visited,stk);            
        }
        stk.push_back(node); 
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for (auto vec : prerequisites) {
            int u = vec[0], v = vec[1];
            graph[u].push_back(v);
        }

        if(!canFinish(numCourses,prerequisites,graph))
        return {}; 


        // vector<bool>visited(numCourses,false) ; 
        // vector<int>stk; 

        // for(int i = 0 ; i < numCourses ; i++){
        //     if(!visited[i])
        //     DFS(i,graph,visited,stk);
        // }


        vector<int>inDegree(numCourses,0); 
        queue<int>q; 
        vector<int>toposort;

        for(int i = 0 ; i < numCourses ; i++){
            for(auto j : graph[i]){
                inDegree[j]++;
            }
        }

        for(int i = 0  ; i < numCourses ; i++){
            if(inDegree[i] == 0)
            q.push(i); 
        }


        while(!q.empty()){
            int node = q.front(); 
            q.pop(); 

            toposort.push_back(node); 

            for(auto num : graph[node]){
                if(--inDegree[num] == 0)
                q.push(num); 
            }
        }

        reverse(toposort.begin(),toposort.end()); 
        return toposort ; 


        
    }
};