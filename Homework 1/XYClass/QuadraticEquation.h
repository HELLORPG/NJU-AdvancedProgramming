#pragma once
#include <iostream>
#include <cmath>

class QuadraticEquation
{
private:
	int a;
	int b;
	int c;
public:
	QuadraticEquation(int a, int b, int c);//���캯������a����Ϊ0�����Ǿ�����һ���������
	int getA() const;
	int getB() const;
	int getC() const;
	int getDiscriminant();
	double getRoot1();
	double getRoot2();
};
