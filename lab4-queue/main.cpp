#include "queue.h"
#include <iostream>

void main(){
	try{
		TQueue<int> queue(20);

		queue.Push(5);
		queue.Push(7);
		queue.Push(9);

		for(int i = 0; i < 4; i++){
			std::cout << queue.Pop();
		}
	} catch(const char* exception){
		std::cerr << "Error: " << exception << '\n';
	}
}
