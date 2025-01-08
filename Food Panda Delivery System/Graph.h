class Graph {
public:
	void addNode(char data);
	void addEdge(char node1, char node2, int weight);
	bool hasVertex(char data);
	void printGraph();
	int minDistance(int dist[], bool visited[]);
	void dijkstra(char sourceVertex);
	void breadthfirstSearch(char s);
private:
	List<GraphNode*> nodes;
};