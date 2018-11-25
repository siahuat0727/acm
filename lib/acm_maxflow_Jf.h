/* Maximum flow */

int FordFulkerson(int s, int t){
    int ret = 0;
    while (1) {
        memset(visited, 0, sizeof(visited));
        if (!DFS(s, t)) break;
        ret += findFlow(s, t);
    }
    return ret;
}

bool DFS(int k, int t) {
    visited[k] = 1;
    if (now == t) return 1;
    for (int i = 0; i < n; ++i ) {
        if (visited[i]) continue;
        if (cap[k][i]-flow[k][i]>0 || flow[i][k]>0) {
            path[i] = k;
            if (DFS(i, t)) return 1;
        }
    }
    return 0;
}

int findFlow(int s, int t) {
    int f = INF;
    for (int i = t, pre; i != s; i = pre) {
        pre = path[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            f = min(f, cap[pre][i] - flow[pre][i]);
        else
            f = min(f, flow[i][pre]);
    }
    for (int i = t, pre; i != s; i = pre) {
        pre = path[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += f;
        else 
            flow[i][pre] -= f;
    }
    return f;
}

/* MCMF (vertex) */

void init(){
    memset(cap,0,sizeof(cap));
    memset(flow,0,sizeof(flow));
}

bool SPFA(int s, int t){ 
    for(int i=1; i<=N; ++i) dis[i]=INF; dis[s]=0;
    memset(inQueue,false,sizeof(inQueue));
    queue <int> Que;
    Que.push(s); inQueue[s]=true;
    while(!Que.empty()){
        int top=Que.front();
        Que.pop(); inQueue[top]=false;
        for(int i : edge[top]){
            if(flow[i][top]>0 && dis[i]>dis[top]-cost[top][i]){
                dis[i]=dis[top]-cost[top][i];
                path[i]=top;
                if(!inQueue[i]){ Que.push(i); inQueue[i]=true; }
            }   
            else if(cap[top][i]-flow[top][i]>0 && dis[i]>dis[top]+cost[top][i]){
                dis[i]=dis[top]+cost[top][i];
                path[i]=top;
                if(!inQueue[i]){ Que.push(i); inQueue[i]=true; }
            }
        }
    }
    return dis[t]!=INF;
}

int FindMinFlow(int s, int t) {
    int bottleneck = INF;
    for (int u = T; u != S; u = pre[u])
        bottleneck = min(bottleneck, cap[pre[u]][u] - flow[pre[u]][u]);
    return bottleneck;
}

void UpdateFlow(int s, int t, int bottleneck) {
    for (int i = t,pre; i != s; i = pre) {
        pre = path[i];
        flow[pre][i] += bottleneck;
        flow[i][pre] -= bottleneck;
    }
}

int MCMF(int s, int t){
    int MaxFlow=0, MinCost=0;
    while(SPFA(s,t)){
        int ff = FindMinFlow(s,t)
        UpdateFlow(s,t,ff);
        MaxFlow += ff;
        MinCost += dis[t];
    }
    return (MaxFlow or MinCost);
}

/* MCMF (edge) */

struct Node {
    int x, y, cap, cost;// x->y, v
    int next;
} edge[1000005];

int e, head[10005], dis[10005], Prev[10005], record[10005], inq[10005];

void addEdge(int x, int y, int cap, int cost) {
    edge[e].x=x, edge[e].y=y, edge[e].cap=cap, edge[e].cost=cost;
    edge[e].next = head[x], head[x] = e++;
    edge[e].x=y, edge[e].y=x, edge[e].cap=0, edge[e].cost=-cost;
    edge[e].next = head[y], head[y] = e++;
}

int mincost(int s, int t) {
    int mncost = 0, flow, totflow = 0;
    int i, x, y;
    while(1) {
        memset(dis, 63, sizeof(dis));
        int oo = dis[0];
        dis[s] = 0;
        deque<int> Q;
        Q.push_front(s);
        while(!Q.empty()) {
            x = Q.front(), Q.pop_front();
            inq[x] = 0;
            for(i = head[x]; i != -1; i = edge[i].next) {
                y = edge[i].y;
                if(edge[i].cap>0 && dis[y]>dis[x]+edge[i].cost) {
                    dis[y] = dis[x] + edge[i].cost;
                    Prev[y] = x, record[y] = i;
                    if(inq[y] == 0) {
                        inq[y] = 1;
                        if(Q.size() && dis[Q.front()] > dis[y])
                            Q.push_front(y);
                        else
                            Q.push_back(y);
                    }
                }
            }
        }
        if(dis[t] == oo) break;
        flow = oo;
        for(x = t; x != s; x = Prev[x]) {
            int ri = record[x];
            flow = min(flow, edge[ri].cap);
        }
        for(x = t; x != s; x = Prev[x]) {
            int ri = record[x];
            edge[ri].cap -= flow;
            edge[ri^1].cap += flow;
            edge[ri^1].cost = -edge[ri].cost;
        }
        totflow += flow;
        mncost += dis[t] * flow;
    }
    return mncost;
}