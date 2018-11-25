/* Bipartite Matching */
int mx[505],my[505];   //memset -1
bool vx[505];
int Matching(){
for(int i=0; i<Y; i++)  //Y左邊  X右邊  (兩排做mathcing)
    if(my[i]==-1){
        memset(vx,false,sizeof(vx));
        if(Aug(i)) match++;
    }
return match;
}
bool Aug(int y){ //Augmenting Path 擴充路徑
    for(int j=0; j<X; j++)
        if(ar[y][j] && !vx[j]){
            vx[j]=true;
            if(mx[j]==-1 || Aug(mx[j])){
                mx[j]=y;
                my[y]=j;
                return true;
            }
        }
    return false;
}

/* Multiple Bipartite Matching */
bool Matching(int Max){
	for(int i=0; i<N; i++){
			memset(vx,false,sizeof(vx));
			if(!Augument(i,Max)) return false;
	}
	return true;
}

bool Augument(int y,int Max){
	for(int x=first[y]; x!=-1; x=e[x].next){
		int i=e[x].v;
		if(!vx[i]){
			vx[i]=true;
			if(peo[i]<Max){
				Mx[i][peo[i]++]=y;
				return true;
			}
			for(int k=0; k<peo[i]; k++)
				if(Augument(Mx[i][k],Max)){
					Mx[i][k]=y;
					return true; 
				}
		}
	}
	return false;
}