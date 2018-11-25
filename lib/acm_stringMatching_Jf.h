/* KMP */

/* string A compare B (LenA<=LenB), pi for A */
LenA=strlen(A); LenB=strlen(B); ans=0; pi[0]=-1;
for(int i=1,k=-1; i<LenA; ++i){
while(k>=0 && A[i]!=A[k+1]) k=pi[k];
    if(A[i]==A[k+1]) ++k;
    pi[i]=k;
}
for(int i=0,k=-1; i<LenB; ++i){
while(k>=0 && B[i]!=A[k+1]) k=pi[k];
    if(B[i]==A[k+1]) ++k;
    if(k+1==LenA){ ++ans; k=pi[k];}
}
printf("%d\n",ans);   /* how many matching */


/* Z-algorithm */
L = R = 0;
for ( int i = 1 ; i < len ; i ++ ) {
    if ( i > R ) Z[i] = 0; // Case 0
    else {
        int ip = i - L;
        if ( ip + Z[ip] < Z[L] ) Z[i] = Z[ip]; // Case 1
        else Z[i] = R - i + 1; // Case 2, 3
    }
    while ( i + Z[i] < len && A[ i + Z[i] ] == A[ Z[i] ] ) Z[i]++;
    if ( i + Z[i] - 1 > R ) {
        L = i;
        R = i + Z[i] - 1;
    }
}

/* AC Automation (TRIE) */

typedef struct TRIE {
	struct TRIE *fail;
	map <char,struct TRIE*> child;
	vector <int> id;
	int cnt;
	TRIE():fail(NULL),cnt(0){}
} Node;

void addTRIE(Node *root, string s, int id){
	Node *now = root;
	for(int i=0; s[i]!='\0'; ++i){
		map <char,Node*>::iterator it = now->child.find(s[i]);
		if(it==now->child.end()){
			Node *t = new TRIE;
			now->child.insert(pair<char,Node*>(s[i],t));
			now=now->child[s[i]];
		}
		else now=(*it).second;
	}
	now->id.push_back(id);
}

void buildFailFunc(Node *root){
	root->fail = NULL;
	queue<Node*> que;
	que.push(root);
	while( !que.empty() ){
		Node *F = que.front(); que.pop();
		for(auto it : F->child){
			Node *cur = it.second, *ptr = F->fail;
			while(ptr && !ptr->child.count(it.first))
ptr = ptr->fail;
			cur->fail = ptr ? ptr->child[it.first] : root;
			que.push(cur);
		}
	}
}

void findAns(Node *root){
	Node *ptr = root;
	for(int i=0; A[i]!='\0'; ++i){
		while(ptr && !ptr->child.count(A[i]) ) ptr = ptr->fail;
		if(ptr) ptr = ptr->child[A[i]];
		else ptr = root;
		
		if(ptr->cnt!=-1){
			for(Node *it=ptr; it; it=it->fail)
				if(it->id.size()){
					it->cnt=-1;
					for(int id : it->id)
						ans[id]=true;  // find it
				}
		}
	}
}

void freeAll(Node *root){
	for(auto it : root->child) freeAll(it.second);
	free(root);
}