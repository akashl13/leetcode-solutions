
import java.util.*;

class Solution {

    public int specialNodes(int n, int[][] edges, int x, int y, int z) {

        // Build adjacency list
        List<Integer>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].add(v);
            adj[v].add(u);
        }

        // Calculate distances from x, y and z
        int[] dx = bfs(n, adj, x);
        int[] dy = bfs(n, adj, y);
        int[] dz = bfs(n, adj, z);

        int answer = 0;

        // Check every node
        for (int i = 0; i < n; i++) {

            long[] d = {
                dx[i],
                dy[i],
                dz[i]
            };

            // Sort distances
            Arrays.sort(d);

            long a = d[0];
            long b = d[1];
            long c = d[2];

            // Check Pythagorean condition
            if (a * a + b * b == c * c) {
                answer++;
            }
        }

        return answer;
    }

    // BFS to calculate distances
    private int[] bfs(int n, List<Integer>[] adj, int start) {

        int[] dist = new int[n];
        Arrays.fill(dist, -1);

        Queue<Integer> queue = new ArrayDeque<>();

        queue.offer(start);
        dist[start] = 0;

        while (!queue.isEmpty()) {

            int node = queue.poll();

            for (int next : adj[node]) {

                if (dist[next] == -1) {

                    dist[next] = dist[node] + 1;

                    queue.offer(next);
                }
            }
        }

        return dist;
    }
}
