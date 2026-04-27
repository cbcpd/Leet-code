class Disjoint_set:
    def __init__(self,n):
        self.parent=[i for i in range(n+1)]
        self.size=[1 for i in range(n+1)]

    def find_parent(self,node):
        if self.parent[node]==node:
            return node
        self.parent[node]=self.find_parent(self.parent[node])
        return self.parent[node]

    def union(self,u,v):
        ulp_u=self.find_parent(u)
        ulp_v=self.find_parent(v)

        if ulp_u==ulp_v:
            return

        if self.size[ulp_u]<self.size[ulp_v]:
            self.parent[ulp_u]=ulp_v
            self.size[ulp_v]+=self.size[ulp_u]

        else:
            self.parent[ulp_v]=ulp_u
            self.size[ulp_u]+=self.size[ulp_v]


class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m,n=len(grid),len(grid[0])
        ds=Disjoint_set(m*n)

        def getid(x,y):
            return x*n+y

        def detectl(x,y):
            if y-1>=0 and grid[x][y-1] in [1,4,6]:
                ds.union(getid(x,y),getid(x,y-1))

        def detectr(x,y):
            if y+1<n and grid[x][y+1] in [1,3,5]:
                ds.union(getid(x,y),getid(x,y+1))

        def detectu(x,y):
            if x-1>=0 and grid[x-1][y] in [2,3,4]:
                ds.union(getid(x,y),getid(x-1,y))

        def detectd(x,y):
            if x+1<m and grid[x+1][y] in [2,5,6]:
                ds.union(getid(x,y),getid(x+1,y))

        def handler(x,y):
            if grid[x][y]==1:
                detectl(x,y)
                detectr(x,y)

            elif grid[x][y]==2:
                detectu(x,y)
                detectd(x,y)

            elif grid[x][y]==3:
                detectl(x,y)
                detectd(x,y)

            elif grid[x][y]==4:
                detectr(x,y)
                detectd(x,y)

            elif grid[x][y]==5:
                detectl(x,y)
                detectu(x,y)

            else:
                detectr(x,y)
                detectu(x,y)

        for i in range(m):
            for j in range(n):
                handler(i,j)


        return ds.find_parent(getid(0,0))==ds.find_parent(getid(m-1,n-1))