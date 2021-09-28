#pragma once
using namespace std;
#include <iostream>
#include <cstdio>

class MyString
{
protected:
	char* str;
	int size;
public:
	MyString() {
		size = 0;
	}
	MyString(const char* str) {
		Setstr(str);
	}
	MyString(char* str) {
		int size = 0;
		while (str[size] != '\0') {
			size++;
		}
		this->str = new char[size];
		for (int i = 0; i < size; i++) {
			this->str[i] = str[i];
		}
		this->str[size] = '\0';
		this->size = size;
	}
	MyString(MyString& mystring) {
		str = new char[mystring.size];
		for (int i = 0; i < mystring.size; i++) {
			str[i] = mystring.str[i];
		}
		size = mystring.size;
	}
	MyString& operator=(MyString mystring);
	void operator=(const char* str);
	int getSize() {
		return size;
	}
	~MyString() {
		if (str) {
			delete[] str;
		}
	}
	void Deletestr();
	void Setstr(const char* str);
	MyString& operator+(MyString mystring);
	MyString operator+=(MyString mystring);
	bool operator==(MyString mystring);
	bool operator!=(MyString mystring);
	void dysplay() {
		for (int i = 0; i < size; i++) {
			cout << str[i];
		}
	}
	friend  ostream& operator<< (std::ostream& out, MyString& str);
	friend  istream& operator>> (std::istream& out, MyString& str);
};

