template<typename T>
class Node{
private:
	T data;
	Node* link;
public:
	// constructor 
	Node(T element);
	//sets the KeyType data in the Node
	void setData(T pVal);
	// returns the KeyType data in the Node
	T getData();
	// returns the link to the next node
	Node* GetNext();
	// sets the link to the next node
	void SetNext(Node* x);
};