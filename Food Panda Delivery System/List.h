template<typename T>
class List
{
private:
	Node<T>* first;
	Node<T>* last;
	int size;
public:
	// constructor of the Singly Linked List 
	List();
	void insert(T data);
	int getSize();
	T getElement(int index);
};