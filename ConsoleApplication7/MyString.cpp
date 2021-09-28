#include "MyString.h"


MyString& MyString::operator=(MyString mystring)
{
	if (this->str != nullptr) {
		delete[] this->str;
	}
	str = new char[mystring.size+1];
	size = mystring.size;
	for (int i = 0; i < size; i++) {
		str[i] = mystring.str[i];
	}
	str[size] = '\0';
	return *this;
}

 void MyString::operator=(const char* str)
{
	Setstr(str);
}

void MyString::Deletestr()
{
	if (str) {
		str = new char[0];
	}
	size = 0;
	
}

void MyString::Setstr(const char* str)
{
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	this->str = new char[size+1];
	for (int i = 0; i < size; i++) {
		this->str[i] = str[i];
	}
	this->str[size] = '\0';
	this->size = size;
}




MyString& MyString::operator+(MyString mystring)
{
	int sizeall = size + mystring.size;
	MyString* temp=new MyString();
	temp->str = new char[sizeall];
	temp->size = sizeall;
	for (int i = 0; i < size; i++) {
		temp->str[i] = str[i];
	}
	for (int i = size; i < sizeall; i++) {
		temp->str[i] = mystring.str[i-size];
	}
	return *temp;

}

MyString MyString::operator+=(MyString mystring)
{
	char* str1 = new char[size];
	int tempsize = size;
	if(str){
		for (int i = 0; i < size; i++) {
			str1[i] = str[i];
		} 
	}
	str = new char[size + mystring.size];
	size += mystring.size;
	for (int i = 0; i < tempsize; i++) {
		str[i] = str1[i];
	}
	for (int i = tempsize; i < size; i++) {
		str[i] = mystring.str[i - tempsize];
	}
	return *this;
}

bool MyString::operator==(MyString mystring)
{
	if (size != mystring.size) {
		return 0;
	}
	else{
		for (int i = 0; i < size; i++) {
			if (str[i] != mystring.str[i]) {
				return 0;
			}
		}
	}
	return 1;
}

bool MyString::operator!=(MyString mystring)
{
	return !(*this == mystring);
}

ostream& operator<<(std::ostream& out, MyString& str)
{
	for (int i = 0; i < str.size; i++) {
		out << str.str[i];
	}
	return out;
}

istream& operator>>(std::istream& in, MyString& str1)
{
	str1.size = 0;
	char* temp, * str;
	str = new char[0];
	temp = new char[0];
	char t;
	while (1) {
		t = cin.get();
		if (t == '\n') {
			delete[] temp;
			break;
		}
		str1.size++;
		delete[] temp;
		temp = new char[str1.size];
		for (int i = 0; i < str1.size - 1; i++) {
			temp[i] = str[i];
		}
		temp[str1.size - 1] = t;
		delete[] str;
		str = new char[str1.size+1];
		for (int i = 0; i < str1.size; i++) {
			str[i] = temp[i];
		}
	}
	str[str1.size] = '\0';
	str1.Setstr(str);
	return in;
}
