
# include<iostream>
# include<string>
# include<fstream>
# include<queue>
# include"Node.h"
# include"List.h"
# include"GraphNode.h"
# include"Graph.h"
using namespace std;
template <typename T>
	Node<T>::Node(T element) {                       	// constructor 
		data = element;
		link = NULL;
	}
	template <typename T>
	void Node<T>::setData(T pVal) {             	//sets the KeyType data in the Node
		data = pVal;
	}
	template <typename T>
	T Node<T>:: getData() {                	// returns the KeyType data in the Node
		return data;
	}
	template <typename T>
	Node<T>* Node<T>:: GetNext() {                	// returns the link to the next node          
		return link;
	}
	template <typename T>
	void Node<T>::SetNext(Node* x) {                 	// sets the link to the next node
		link = x;
	}
template <typename T>
     List<T>::List() {                                  // constructor of the Singly Linked List 
		first = NULL;
		last = NULL;
		size = 0;
		int element=0;
	}
	 template <typename T>
	void List<T>::insert(T data) {                    //makes list of graph nodes
		if (first == NULL) {
			first = new Node<T>(data);
			last = first;
			size++;
		}
		else {
			Node<T>* temp = new Node<T>(data);
			last->SetNext(temp);
			last = temp;
			size++;
		}
	}
	template <typename T>
	int List<T>::getSize() {                  //to get size of the list
		return size;
	};
	template <typename T>
	T List<T>:: getElement(int index) {                   //to get element at specific index      
		int count = 0;
		Node<T>* ptr = first;
		while (count != index) {
			ptr = ptr->GetNext();
			count++;
		}
		return ptr->getData();
	}
	GraphNode::GraphNode() {                     //constructor
		data = ' ';
	}
	void GraphNode::setData(char val) {                     //sets the data
		data = val;
	}
	char GraphNode::getData() {                    //returns the data
		return data;
	}
	void GraphNode::addNeighbour(GraphNode* ptr, int weight) {   //To add neighbour and their weights      
		neighbours.insert(ptr);                                   
		weights.insert(weight);
	}
	GraphNode* GraphNode::getNeighbour(int index) {             //To get neigbour at sepcific index
		return neighbours.getElement(index);
	}
	int GraphNode::countNeighbour() {                 //counts total neighbour
		return neighbours.getSize();
	};
	int GraphNode::getWeight(int index) {              // To get weight at sepcific index
		return weights.getElement(index); 
	}
	void Graph:: addNode(char data) {              //adds node in link list
		GraphNode* gNode = new GraphNode;
		gNode->setData(data);
		nodes.insert(gNode);
	}
	void Graph:: addEdge(char node1, char node2, int weight) {           //add neighbours
		GraphNode* n1 = NULL, * n2 = NULL;
		for (int i = 0; i < nodes.getSize(); i++) {
			if (nodes.getElement(i)->getData() == node1) {
				n1 = nodes.getElement(i);
			}
			if (nodes.getElement(i)->getData() == node2) {
				n2 = nodes.getElement(i);
			}
		}
		n1->addNeighbour(n2, weight);
		n2->addNeighbour(n1, weight);
	}
	bool Graph:: hasVertex(char data) {         //checks whether a node exists or not
		for (int i = 0; i < nodes.getSize(); i++) {
			if (nodes.getElement(i)->getData() == data) {
				return true;
			}
		}
		return false;
	}
	void Graph::printGraph()                             
	{
		for (int i = 0; i < nodes.getSize(); i++)
		{
			cout << endl << "-------------------------" << endl;
			cout << "Node # " << i + 1 << ": " << nodes.getElement(i)->getData() << endl;
			cout << "Neighbours: " << endl;
			for (int j = 0; j < nodes.getElement(i)->countNeighbour(); j++)
			{
				cout << "Neighbour # " << j + 1 << ": " << nodes.getElement(i)->getNeighbour(j)->getData() << ", Weight: " << nodes.getElement(i)->getWeight(j) << endl;
			}
			cout << endl << "-------------------------" << endl << endl;
		}
	}
	int Graph:: minDistance(int dist[], bool visited[]) {       //finds minimum index
		// Initialize min value
		int min = 9999, min_index;
		for (int v = 0; v < nodes.getSize(); v++) {
			if (visited[v] == false && dist[v] <= min) {
				min = dist[v], min_index = v;
			}
		}
		return min_index;
	}
   void Graph::dijkstra(char sourceVertex) {         // find shortest path
		int* dist = new int[nodes.getSize()];
		bool* visited = new bool[nodes.getSize()];
		for (int u = 0; u < nodes.getSize(); u++) {
			dist[u] = 9999;   //set as infinity
			visited[u] = false;
		}
		int sourceVertexIndex = -1;
		for (int i = 0; i < nodes.getSize(); i++) {
			if (nodes.getElement(i)->getData() == sourceVertex) {
				sourceVertexIndex = i;
				break;
			}
		}
		dist[sourceVertexIndex] = 0;
		for (int i = 0; i < nodes.getSize(); i++) {
			int u = minDistance(dist, visited);
			visited[u] = true;
			for (int j = 0; j < nodes.getSize(); j++) {
				// Checking if edge exist
				bool edgeExists = false;
				int edgeWeight = -1;
				GraphNode* currentNode = nodes.getElement(u);
				for (int k = 0; k < currentNode->countNeighbour(); k++) {
					if (currentNode->getNeighbour(k)->getData() == nodes.getElement(j)->getData()) {
						edgeExists = true;
						edgeWeight = currentNode->getWeight(k);
						break;
					}
				}
				if (visited[j] == false && edgeExists == true && dist[u] != 9999 && (dist[u] + edgeWeight) < dist[j]) {
					dist[j] = dist[u] + edgeWeight;
				}
			}
		}
		cout << endl;
		for (int i = 0; i < nodes.getSize(); i++) {
			cout << nodes.getElement(i)->getData() << "\t" << dist[i] << endl;
		}
	}
   
   /*void Graph:: breadthfirstSearch(int s)
   {
	   char address = 'L';
	   int size = nodes.getSize();
	   bool* visitVertex = new bool[size];
	   for (int i = 0; i < size; i++)
		   visitVertex[i] = false;
	   queue<int> qu;
	   qu.push(s);
	   visitVertex[s] = true;
	   while (!qu.empty())
	   {
		   int v = qu.front();
		   char x= v+65;
		   cout << x << " ";
		   if (x == address) {
			   return;
		   }
		   for (int i = 0; i < size; i++)
		   {
			   if (nodes.getElement(i)->getData() >= 'A' && nodes.getElement(i)->getData()<='P' && visitVertex[i] == false)
			   {
				   qu.push(i);
				   visitVertex[i] = true;
			   }
		   }
		   qu.pop();
	   }
	   cout << endl;
   }*/
   
   void Graph::breadthfirstSearch(char s) {
	  
	   char address = 'L';
	   int size = nodes.getSize();
	   bool* visitVertex = new bool[size];
	   for (int i = 0; i < size; i++) {
		   visitVertex[i] = false;
	   }
	   queue<char> qu;
	   qu.push(s);
	   char* pushedValues = new char[size];
	   for (int i = 0; i < size; i++) {
		   pushedValues[i] = ' ';
	   }
	   while (!qu.empty())
	   {
		   int iterate = 0;
		   char v = qu.front();
		   cout << v;
		   pushedValues[iterate] = v;
		   qu.pop();
		   if (v == address) {
			   return;
		   }
		   int index = 0;
		   for (int i = 0; i < size; i++) {
			   if (nodes.getElement(i)->getData() == v) {
				   index = i;
			   }
		   }
		   visitVertex[index] = true;
		   bool check = false;
		   int index2 = 0;
			for (int j = 0; j < nodes.getElement(index)->countNeighbour(); j++)
			{
				if (nodes.getElement(index)->getNeighbour(j)->getData() >='A' && nodes.getElement(index)->getNeighbour(j)->getData() <= 'P' && visitVertex[j]==false) {
					for (int i = 0; i < size; i++) {
						if (pushedValues[i] = nodes.getElement(index)->getNeighbour(j)->getData()) {
							index2 = i;
							check = true;
						}
						else {
							check = false;
						}
					}
					if (check == true) {
						if (j != index2) {
							qu.push(nodes.getElement(index)->getNeighbour(j)->getData());
						}
					}
					else if (check == false) {
						qu.push(nodes.getElement(index)->getNeighbour(j)->getData());
					}
				}
			}
			iterate++;
		}
	  
  }
   
int main()
{
	Graph g;
	char n1, n2;
	int w;
	ifstream fin;
	fin.open("foodpanda.txt");
	while (!fin.eof()) {
		fin >> n1 >> n2 >> w;
		if (g.hasVertex(n1) == false) {
			g.addNode(n1);
		}
		if (g.hasVertex(n2) == false) {
			g.addNode(n2);
		}
		g.addEdge(n1, n2, w);
	}
	g.printGraph();
	g.dijkstra('H');
	g.breadthfirstSearch('H');
	return 0;
}