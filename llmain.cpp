#include <iostream>
#include <linkedList.h>

int main() {
        LinkedList<int>  l_list;
        l_list.insert(1);
        l_list.insert(2);
        l_list.insert(3);
      	l_list.insert_at(2, 4);
      	 int position = l_list.find(4);
      	l_list.remove_(3);
	      l_list.showList();
      	return 0;
}
