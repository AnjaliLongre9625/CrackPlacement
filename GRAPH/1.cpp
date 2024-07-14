class solution{
private:
    void dfs(){
    }

public:
    bool isCyclic(int V, vector<int> adj[]){
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for (int i = 1; i < V; i++){
            if (!vis[i]) {
                if (dfs(i) == true) {
                    return true;
                }
            }
        return false;
    }
};