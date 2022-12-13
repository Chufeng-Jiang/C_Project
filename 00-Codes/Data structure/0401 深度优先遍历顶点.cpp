// 深度优先搜索
void DFS(Graph& g)
{
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}

	// 从顶点数组中的第一个开始访问
	stack<int> st;	// int - 顶点数组的下标
	visited[0] = true;
	cout << g.vertex[0] << " ";
	st.push(0);

	while (!st.empty())
	{
		// 遍历所有的顶点, 找邻接点 - 栈顶元素对应的邻接点
		for (int i = 0; i < g.vertexNum; ++i)
		{
			// 栈顶元素在顶点数组中的位置
			int top = st.top();
			
			// 对g.vertex[i]的邻接点进行挨个判断--二维矩阵的横向
			/***************************
					| V0  V1  V2  V3 
				 V0 | 0   1   1   0	 		
			visited | 1   0   0   0  visited数组的大小与顶点数相同，按行轮流使用
			***************************/
			//visited[i]没有被访问过，并且top顶点到顶点i之间有边
			if (!visited[i] && g.edge[top][i] > 0) 
			{
				// 遍历该顶点
				visited[i] = true;
				cout << g.vertex[i] << " "; //输出顶点
				// 邻接点压栈
				st.push(i);
			}
		}
		// 栈顶的顶点与其余的顶点组成的边全部判断了一遍
		st.pop();
	}
	delete[] visited;
}