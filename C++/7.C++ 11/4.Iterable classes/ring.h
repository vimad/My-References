#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class ring {
private:
	T * mvalues;
	int mSize;
	int mPos;
public:
	class iterator;

	ring(int size) :mPos(0), mvalues(NULL), mSize(size) {
		mvalues = new T[mSize];
	}

	~ring() {
		delete[] mvalues;
	}

	int size() {
		return mSize;
	}

	void add(T item) {
		mvalues[mPos++] = item;

		if (mPos == mSize) mPos = 0;
	}

	T &get(int pos) {
		return mvalues[pos];
	}

	iterator begin() {
		return iterator(0, *this);
	}

	iterator end() {
		return iterator(mSize, *this);
	}
};

template <class T>
class ring<T>::iterator {
private:
	int mPos;
	ring &Ring;
public:
	iterator(int pos, ring &Ring) :mPos(pos), Ring(Ring) {

	}

	iterator &operator++(int) {
		mPos++;
		return *this;
	}

	iterator &operator++() {
		mPos++;
		return *this;
	}

	bool operator!=(const iterator &other) const {
		return mPos != other.mPos;
	}

	T &operator*() {
		return Ring.get(mPos);
	}

};