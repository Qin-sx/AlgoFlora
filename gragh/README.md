[Reference](https://labuladong.online/algo/data-structure/topological-sort/)

### leetcode 207 课程表1

#### BFS 环检查

当入度为0（满足条件）时，才将节点放入队列。如果所有节点都被遍历，说明没有环。

```c++
class Solution {
    // 0
    // | \
    // 1  2
    // | /
    // 3
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 建图
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto pre : prerequisites)
        {
            edges[pre[0]].push_back(pre[1]);  //学了课程0之后可以学课程1
            ++indegree[pre[1]];               //课程1的入度+1
        }

        // 初始化队列
        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }

        }

        // BFS 多叉树层级遍历
        int count = 0;

        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();

            ++count; // 遍历了几个节点

            for (auto node : edges[cur])
            {
                --indegree[node]; // 入度 -1
                if(indegree[node] == 0) // 如果入度为0，将节点放入队列（每次都会-1，所以只会入队一次）
                {
                    que.push(node);
                }
            }
        }

        return numCourses == count; //是否遍历了所有的节点
    }
};
```

#### DFS 环检查

和多叉树的遍历一样。和回溯不同的是，DFS关注节点，`选择`在for循环外面，回溯关注树枝，`选择`在for循环里面。  
如果路径之前记录过这个节点，说明成环了。  
有可能有多个图，用visit记录。

```c++
class Solution {
    // 0
    // | \
    // 1  2
    // | /
    // 3

    vector<bool> visit;
    vector<bool> path;
    bool iscycle;

    void traverse(const vector<vector<int>>& edges, int node)
    {
        if (iscycle)
        {
            return;
        }

        if (path[node])
        {
            iscycle = true;
            return;
        }

        if (visit[node])
        {
            return;
        }

        // 加入节点
        visit[node] = true;
        path[node] = true;

        // 多叉树遍历
        for (auto e : edges[node])
        {
            traverse(edges, e);
        }

        // 撤销节点
        path[node] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 建图
        vector<vector<int>> edges(numCourses);

        for (auto pre : prerequisites)
        {
            edges[pre[0]].push_back(pre[1]);  //学了课程0之后可以学课程1
        }

        // 初始化
        visit = vector<bool>(numCourses,false);
        path = vector<bool>(numCourses,false);
        iscycle = false;
        // DFS 多叉树遍历

        for (int i = 0; i < numCourses; ++i) //有可能有多个图，所以每个节点都需要遍历一次。有visit记录。
        {
            traverse(edges, i);
        }

        return !iscycle; //是否遍历了所有的节点
    }
};
```



