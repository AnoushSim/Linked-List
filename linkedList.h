#ifndef "LINKEDLIST"
#define "LINKEDLIST"

template <typename T>
struct Node {
  T item;
  Node* next;
};

template <typename T>
class LinkedList {
  Node<T>* _head;
  
  public:
  LinkedList();
  ~LinkedList();
  void insert( T element);
  void insert_at(int pos, T element);
  void remove_( int pos);
  int find(const T& element);
  void showList() ;
};

template <typename T>
LinkedList<T>::LinkedList() {
  _head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  std::cout << "Destructor is invoked!" << std::endl;
}

template <typename T>
void LinkedList<T>::insert (T element) {
  Node<T>* node = new Node<T>();
  node->item = element;
  node->next = _head;
  _head = node;
}

template <typename T>
void LinkedList<T>::insert_at (int pos,T element) {
  Node<T>* _tmp = new Node<T>();
  Node<T>* _cur = new Node<T>();
  Node<T>* _prev = new Node<T>();
  
  _cur = _head;
  if(_head != nullptr) {
    for(int ix = 0;  ix < pos-1; ++ix) {
   
      _prev=_cur;
      _cur=_cur->next;
     }
    _tmp->item = element;
    _prev->next = _tmp;	
     _tmp->next = _cur;
   }
}

template <typename T>
void LinkedList<T>::remove_(int pos) {
  Node<T>* _cur = new Node<T>();
  Node<T>* _prev = new Node<T>();
  
  _cur = _head;
  if(_head != nullptr) {
   for (int ix = 0; ix < pos-1; ++ix) {
     _prev = _cur;
     _cur = _cur->next;
  } 
  _prev->next = _cur->next;
 }
}

template <typename T>
int LinkedList<T>::find(const T& element) {
  Node<T>* _cur = new Node<T>();
  _cur = _head;
  if(_head != nullptr) {
    for(int ix = 1; _cur != nullptr; ++ix) {
      if(_cur->item == element)
         return ix ;
      _cur = _cur->next;
    }
  }
  return -1;
}

template <typename T>
void LinkedList<T>::showList()  {
	Node<T>* _cur = _head;
	for(int ix = 1; _cur != nullptr; ++ix) {
		std::cout << ix  <<" : " << _cur->item << std::endl;
		_cur = _cur->next;
	}	
}

#endif
