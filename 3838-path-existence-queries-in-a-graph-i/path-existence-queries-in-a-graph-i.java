class Solution {
    int parent[];
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        parent = new int[n];
        for(int i=0; i<n ;i++) {
            parent[i]=i; }                        // each node is its own root initially
        for(int i=0; i<n-1; i++) {
            int num1 = nums[i], num2 = nums[i+1];  // only consecutive pairs can be edges

            if(Math.abs(num1 - num2) <= maxDiff) {
                union(i, i+1);                     // within gap -> merge the two nodes
            }
        }
        boolean ans[] = new boolean[queries.length];
        int index = 0;
        for(int q[] : queries) {
            int x = q[0];
            int y = q[1];

            ans[index++] = (find(x)==find(y));     // same root -> path exists
        }
        return ans;
    }
    private int find(int x) {
        if(parent[x]!=x)
            parent[x] = find(parent[x]);           // path compression: point straight to root
        return parent[x];
    }
    private void union(int x, int y) {
        parent[find(x)] = find(y);                 // hang x's root under y's root
    }
}