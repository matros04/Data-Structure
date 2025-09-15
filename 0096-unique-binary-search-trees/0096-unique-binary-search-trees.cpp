class Solution {
public:
    int numTrees(int n) {
        vector<int>ut(n+1,1);
            for(int nodes=2;nodes <=n ;nodes++)
            {
                int total=0;
                for(int root=1;root<=nodes;root++)
                {
                    total+=ut[root-1]*ut[nodes-root];
                }
                ut[nodes]=total;
            }
        return ut[n];

    }
};