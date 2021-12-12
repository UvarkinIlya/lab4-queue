#pragma once

template <class T>
class TQueue{
	T* arr;
	int MaxSize;//Максимальный размер массива
	int head, tail;//Указатель на начало и конец очереди
	int countElem;//кол-во элементов в очереди

	public:
		TQueue(int _maxSize = 20){
			if(_maxSize <= 0){
				throw "wrong size";
			}

			MaxSize = _maxSize;
			arr = new T[MaxSize];
			head = 0;
			tail = -1;
			countElem = 0;
		}

		~TQueue(){
			delete[] arr;
			MaxSize = -1;
		}

		const bool isEmpty(){
			return countElem == 0;
		}

		const bool isFull(){
			return countElem == MaxSize;
		}

		void Push(T elem){
			if (isFull()){
				throw "queue full!";
			}
			tail = (tail + 1) % MaxSize;
			arr[tail] = elem;
			countElem++;
		}

		T Pop(){
			if (isEmpty()){
				throw "queue empty!";
			}
			T elem = arr[head];
			head = (head + 1) % MaxSize;
			countElem--;
			return elem;
		}

		const T getFront(){
			if (isEmpty()){
				throw "queue empty!";
			}
			return arr[head];
		}

		const T getBack(){
			if (isEmpty()){
				throw "queue empty!";
			}
			return arr[(tail + 1) % MaxSize];
		}
};

