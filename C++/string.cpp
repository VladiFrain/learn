#include "header.h"

using namespace std;

//����� ������
int strLength(const char* str) {
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

class MyStr
{
public:
	//����������� ��� ����������
	MyStr()
	{
		str = nullptr;
		length = 0;
	}
	//����������� ��� ������ ��������� ������
	MyStr(const char *str)
	{
		length = strLength(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}
	//����������
	~MyStr()
	{
		delete[] this->str;
	}
	//����������� �����������
	MyStr(const MyStr &other)
	{
		length = strLength(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}
	//����������� ��������
	MyStr(MyStr &&other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
	//������������� �������� ������������
	MyStr &operator = (const MyStr &other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		length = strLength(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}
	//������������� �������� ��������
	MyStr operator + (const MyStr &other)
	{
		MyStr newStr;
		int thisLength = strLength(this->str);
		int otherLength = strLength(other.str);
		newStr.length = thisLength + otherLength;
		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[newStr.length] = '\0';

		return newStr;
	}
	//����� ������ �� �������
	void Print()
	{
		cout << str << endl;
	}
	//����� ������
	int Length()
	{
		return length;
	}
	//���������� ��������� ���������
	bool operator ==(const MyStr &other)
	{
		if (this->length != other.length)
		{
			return false;
		}
		for (int i = 0; i < length; i++)//��� ������� ����� length ������������(�� ��������� � ������)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}
	//���������� ��������� �����������
	bool operator !=(const MyStr &other)
	{
		return !(this->operator==(other));
	}
	//���������� ���������[]
	char &operator [](int index)
	{
		return this->str[index];
	}

private:
	//��������� �� ����� char, ������ ������� ������� �� �������� � ��� ������
	char *str;
	//������ ������
	int length;
};
//��� �������� � ����� main ����� argStart
void MyString() //������� �������: -ms
{
	cout << "�������� ������������ String" << endl;
	MyStr str;
	str = "Hello";

	MyStr str2("World");

	MyStr str3;
	str3 = str + str2;

	str3.Print();

	cout << str.Length() << endl;
	cout << str2.Length() << endl;
	cout << str3.Length() << endl;
	
	bool equal = str != str2;
	cout << equal << endl;

	cout << str[1] << endl;
	str[0] = 'Q';
	str.Print();
}