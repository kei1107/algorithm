#[derive(Copy, Clone)]
pub struct Edge{
    from:usize,
    to:usize,
    cost:i64
}

#[derive(Clone)]
pub struct Graph{
    N:usize,
    Edges:Vec<Vec<Edge>>
}
impl Graph{
    pub fn new(n:usize) -> Graph{
        Graph{N:n,Edges:vec![vec![];n]}
    }
    pub fn add_edge(&mut self,u:usize,v:usize,cost:i64,undirected:bool){
        self.Edges[u].push(Edge{from:u,to:v,cost});
        if undirected {
            self.Edges[v].push(Edge{from:v,to:u,cost})
        }
    }

    pub fn Dijkstra(&self,root:usize) -> Vec<i64>{
        let mut dist = vec![i64::max_value() as i64;self.N];
        dist[root] = 0;

        let mut pq = BinaryHeap::new();
        pq.push((0_i64,root));
        while !pq.is_empty(){
            let s = pq.pop().unwrap();
            let (d,n) = (-s.0,s.1);
            if dist[n] < d {
                continue;
            }

            for e in &self.Edges[n]{
                if dist[e.to] > dist[e.from] + e.cost{
                    dist[e.to] = dist[e.from] + e.cost;
                    pq.push((-dist[e.to],e.to));
                }
            }
        }

        return dist;
    }

}
