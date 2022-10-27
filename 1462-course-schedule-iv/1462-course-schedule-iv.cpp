class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> connections(numCourses, vector<int>(numCourses, 0));
        
        for(auto edge: prerequisites){
            int a = edge[0], b = edge[1];
            connections[a][b] = 1;
        }
        for(int k=0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    connections[i][j] = connections[i][j] || (connections[i][k] && connections[k][j]);
                }
            }
        }
        vector<bool> result;
        for(auto query: queries){
            int u = query[0], v = query[1];
            result.push_back(connections[u][v]);
        }
        return result;
    }
};