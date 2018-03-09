
int FordFulkerson(int s, int t, int n){
	int ret = 0;
	while(1){
		memset(v, 0, sizeof(v));
		if(!DFS(s, t, n)) // source, end, totalV
			break;
		ret += FindFlow(s, t, n);
	}
	return ret;
}


bool DFS(int cur, int t, int n){
	v[cur] = true;
	if(cur == t)
		return true;
	for(int i = 1; i <= n; ++i){
		if(v[i])
			continue;
		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
			pa[i] = cur;
			if(DFS(i, t, n))
				return true;
		}
	}
	return false;
}

int FindFlow(int s, int t, int n){
	int pre;
	int f = INF;
	for(int i = t; i != s; i = pa[i]){
		pre = pa[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f = min(f, cap[pre][i]-flow[pre][i]);
		else
			f = min(f, flow[i][pre]);
	}
	for (int i = t; i != s; i = pa[i]){
		pre = pa[i];
		if(cap[pre][i] - flow[pre][i] > 0)
			flow[pre][i] += f;
		else
			flow[i][pre] -= f;
	}
	return f;
}