int Solution::diffPossible(vector<int> &A, int B) {
    vector<int> input(A);
    sort(input.begin(), input.end());
    int x=0,y=0;
    int size=input.size();
    while (y<size)
    {
        if (x==y)
        {
           ++y; 
        }
            
        else if (input[y]-input[x] == B && x!=y)
        {
            return 1;
        }
            
        else if (input[y]-input[x] < B)
        {
            ++y;
        }
            
        else if (input[y]-input[x] > B)
        {
            ++x;
        }
            
    }
    return 0;
}


