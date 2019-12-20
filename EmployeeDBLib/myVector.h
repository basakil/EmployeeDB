#pragma once

#include <vector>

#define MYVECTOR_MAXSIZE 100

template <typename T>
class myVector2 : public std::vector<T> {

};


template <typename T>
class myVector1 {
public:
	inline void push_back(const T &t) {
		if (lastIndex < MYVECTOR_MAXSIZE) {
			items[++lastIndex] = t;
		}
	}
	inline T& at(int pos) {
		if (pos <= lastIndex) {
			return items[pos];
		}
		throw 0;
	}
private:
	static const int MAX_SIZE = MYVECTOR_MAXSIZE;
	T items[MYVECTOR_MAXSIZE];// = T[20];
	int lastIndex = -1;
};

//template <typename T>
//static const int myVector1<T>::MAX_SIZE = 100;

//
//template<typename T>
//inline void myVector1<T>::push_back(T)
//{
//}
//
