
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> adjList;

        // Build the adjacency list and in-degree array
        for (const auto& pair : prerequisites) {
            adjList[pair[1]].push_back(pair[0]);
            inDegree[pair[0]]++;
        }

        // Create a queue for topological sorting
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sorting
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            numCourses--;

            for (const auto& neighbor : adjList[course]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If numCourses is 0, all courses can be finished
        return numCourses == 0;
    }
};
