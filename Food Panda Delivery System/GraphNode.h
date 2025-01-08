class GraphNode {
public:
	GraphNode();
	void setData(char val);
	char getData();
	void addNeighbour(GraphNode* ptr, int weight);
	GraphNode* getNeighbour(int index);
	int countNeighbour();
	int getWeight(int index);
private:
	char data;
	List<GraphNode*> neighbours;
	List<int> weights;
};