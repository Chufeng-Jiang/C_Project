// 广度优先搜索
void BFS(Graph& g)
{
	// 保证顶点不被重复遍历
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}

	// 找一个顶点, 开始访问 - 0
	queue<int> q;	// 存储顶点的下标
	visited[0] = true;
	cout << g.vertex[0] << " ";
	q.push(0);

	// 如果队列为空, 遍历完成
	while (!q.empty())
	{
		// 队头顶点的下标值拿出来
		int front = q.front();
		// 遍历所有的顶点, 找邻接点
		for (int i = 0; i < g.vertexNum; ++i)
		{
			// 如果没被访问, 并且两顶点互为邻接点
			if (!visited[i] && g.edge[front][i] > 0)
			{
				// 访问,并且入队列
				visited[i] = true;
				cout << g.vertex[i] << " ";
				q.push(i);
			}
		}
		// 所有的邻接点都访问完成,出队列
		q.pop();
	}
	delete[] visited;
}