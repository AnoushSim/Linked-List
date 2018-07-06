#include <iostream>

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
  void insert_begin( const T& element);
  void insert_at(int pos, const T& element);
  void insert_end(const T& element);
  void remove_( int pos);
  int find(const T& element);
  void get_size();
  void replace(int pos,const T& element);
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
void LinkedList<T>::insert_begin (const T& element) {
  Node<T>* node = new Node<T>();
  node->item = element;
  node->next = _head;
  _head = node;
}

template <typename T>
void LinkedList<T>::insert_at (int pos,const T& element) {
  Node<T>* _tmp = new Node<T>();
  Node<T>* _cur = new Node<T>();
  Node<T>* _prev = new Node<T>();
  
  _cur = _head;
  if(_head != nullptr) {
    for(int ix = 0;  ix < pos - 1; ++ix) {
   
      _prev=_cur;
      _cur=_cur->next;
     }
    _tmp->item = element;
    _prev->next = _tmp;	
     _tmp->next = _cur;
   }
}

template <typename T>
void LinkedList<T>::insert_end (const T& element){
  Node<T>* node = new Node<T>();
  Node<T>* _cur = _head;
  for(int ix = 0; _cur->next != nullptr; ++ix ) {
    _cur = _cur->next;
  }
  node->item = element;
  node->next = nullptr;
  _cur->next = node;
}


template <typename T>
void LinkedList<T>::remove_(int pos) {
  Node<T>* _cur = new Node<T>();
  Node<T>* _prev = new Node<T>();
  
  _cur = _head;
  if(_head != nullptr) {
   for (int ix = 0; ix < pos - 1; ++ix) {
     _prev = _cur;
     _cur = _cur->next;
  } 
  _prev->next = _cur->next;
  delete _cur;
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
void LinkedList<T>::get_size() {
  Node<T>* _cur = new Node<T>();
  _cur = _head;
  if(_head == nullptr) {
    std::cout << "List is empty!" <<std::endl;
    return;
  }
  int count = 0;
  for(int ix = 0; _cur != nullptr; ++ix) {
    count++;
    _cur = _cur->next;
  }
  std::cout << "The length of the list is :" << count << std::endl;
  
}

template <typename T>
void LinkedList<T>::replace(int pos,const T& element) {
  Node<T>* _tmp = new Node<T>();
  Node<T>* _cur = new Node<T>();
  Node<T>* _prev = new Node<T>();
  
  _cur = _head;
  if(_head != nullptr) {
    for(int ix = 0;  ix < pos - 1; ++ix) {
   
      _prev=_cur;
      _cur=_cur->next;
     }
     _tmp->item = element;
     _tmp->next = _cur->next;
     _prev->next = _tmp;
     delete _cur;
  } 
}

template <typename T>
void LinkedList<T>::showList()  {
	Node<T>* _cur = _head;
	for(int ix = 1; _cur != nullptr; ++ix) {
		std::cout << ix  <<" : " << _cur->item << std::endl;
		_cur = _cur->next;
	}	
}

int main() {
        LinkedList<int>  l_list;
        l_list.insert_begin(1);
        l_list.insert_begin(2);
        l_list.insert_begin(3);
        l_list.insert_end(10);
        l_list.get_size();
        l_list.showList();
        std::cout << "\n";
      	l_list.insert_at(2, 4);
      	l_list.showList();
      	l_list.replace(2, 55);
      	l_list.get_size();
      	l_list.showList();
        std::cout << "\n";
      	int position = l_list.find(55);
      	std::cout << position <<std::endl;
      	l_list.remove_(3);
	      l_list.showList();
      	return 0;
}

