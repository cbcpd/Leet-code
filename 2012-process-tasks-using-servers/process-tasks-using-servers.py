class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        busy_servers = []
        i = 0
        n = len(tasks)
        free_servers = [[servers[i], i] for i in range(len(servers))]
        heapq.heapify(free_servers)
        current_time=0
        ans = [0]*len(tasks)

        while i<n:
            current_time=max(current_time, i)
            if not free_servers:
                current_time = busy_servers[0][0]
            while busy_servers and busy_servers[0][0]<=current_time:
                end_time, server = heapq.heappop(busy_servers)
                heapq.heappush(free_servers, [servers[server], server])
            weight, server = heapq.heappop(free_servers)
            heapq.heappush(busy_servers, [current_time+tasks[i], server])
            ans[i]=server
            i+=1
        return ans