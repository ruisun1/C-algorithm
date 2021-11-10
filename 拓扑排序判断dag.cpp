#你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

#在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

#例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
#请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

#来源：力扣（LeetCode）
#链接：https://leetcode-cn.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> adjcent;
        vector<int> indegree(numCourses);
        for (auto& edge : prerequisites) {. #建立临接表
            int a = edge[0];
            int b = edge[1];
            adjcent[b].insert(a);
            ++indegree[a];                  #计算每个点的入度
        }
        int count = 0;
        queue<int> todo;
        for (int i = 0; i < numCourses; ++i) {  #queue用来记录所有入度为0的点
            if (!indegree[i]) todo.push(i);
        }
        while (!todo.empty()) {
            auto v = todo.front();
            todo.pop();   
            ++count;            #count所有跳出queue的数量
            auto& adjs = adjcent[v];
            for (auto adj : adjs) {
                --indegree[adj];
                if (!indegree[adj]) todo.push(adj);     #再次查找所有入度为0的点，加入queue
            }
        }
        return count == numCourses;
    }
};
