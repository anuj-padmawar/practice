struct pos {
    int x,y,len;
    pos(int x, int y, int len): x(x), y(y), len(len) {};
};

bool ifInsideOrNot(int x,int y,int A,int B) 
{
    if((x>=1 && x<=A) && (y>=1 && y<=B))
    {
        return true;
    }
    return false;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) 
{
    
    int dx[]={-2,-2,-1,1,2,2,1,-1};
    int dy[]={1,-1,-2,-2,-1,1,2,2};
    
    bool visited[A+1][B+1];
    memset(visited, false, sizeof(visited));
    visited[C][D]=true;
    queue<pos*>q;
    pos *t = new pos(C,D,0);
    q.push(t);
    
    int x_cor,y_cor;
    
    while(!q.empty()) 
    {
        t=q.front();
        q.pop();
        
        if(t->x==E && t->y==F)
        {
            return t->len;
        }
        
        for(int i=0;i<8;i++) 
        {
            x_cor=t->x + dx[i];
            y_cor=t->y + dy[i];
            
            if(ifInsideOrNot(x_cor,y_cor,A,B) && !visited[x_cor][y_cor]) 
            {
                pos * xxx =new pos(x_cor,y_cor,t->len+1);
                visited[x_cor][y_cor]=true;
                q.push(xxx);
            }
        }
    }
    return -1;
}
