// Simple_Factory_Pattern.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<memory>   //shared_ptr

using namespace std;

class Operation{
private:
	double _numberA;
	double _numberB;

public:
	double getA()const { return _numberA; }
	double getB()const { return _numberB; }
	void setA(const double & x) { _numberA = x; }
	void setB(const double & y) { _numberB = y; }
	
	virtual double GetResult()const {
		double result = 0.0;
		return result;
	}
};

class OperationAdd :public Operation{
public:
	double GetResult()const{
		return getA() + getB();
	}
};

class OperationSub :public Operation{
public:
	double GetResult()const{
		return getA() - getB();
	}
};

class OperationMul :public Operation{
public:
	double GetResult()const{
		return getA() * getB();
	}
};

class OperationDiv :public Operation{
public:
	double GetResult()const{
		if (getB() == 0)
			cout << "��������Ϊ�㣡" << endl;
		return getA() / getB();	
	}
};

class SimpleFactory{
public:

 static Operation * createOperator(const char s){
		Operation * oper = NULL;
		switch (s)
		{
			case '+':
				oper = new OperationAdd();     //��̬�����֣��ø����ָ��ָ���������������ڳ�������ʱ�жϵ����ĸ�
				break;
			case '-':
				oper = new OperationSub();
				break;
			case '*':
				oper = new OperationMul();
				break;
			case '/':
				oper = new OperationDiv();
				break;
		}
		return oper;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	double a, b;
	char ch;
	cin >> a >> ch >> b;

	shared_ptr<Operation> sp(SimpleFactory::createOperator(ch));
	sp->setA(a);
	sp->setB(b);
	cout << sp->GetResult() << endl;
	system("pause");
	return 0;
}

