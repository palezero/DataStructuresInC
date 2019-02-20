#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxDegree 100
typedef struct Node
{
	int CoeffArray[MaxDegree+1];//系数
	int HighPower;//该多项式系数的最高次幂
}*Polynomial;
Polynomial Polyinit();
Polynomial Polymake(int data[], int length);
Polynomial Polyadd(Polynomial Poly1,Polynomial Poly2);
Polynomial Polymux(Polynomial Poly1,Polynomial Poly2);
Polynomial Polysub(Polynomial Poly1,Polynomial Poly2);
void Polyprint(Polynomial Poly);
void Polyclear(Polynomial Poly);
Polynomial Polymux(Polynomial Poly1, Polynomial Poly2)
{
	static Polynomial Polysum;
	int MaxPower;
	int i,j;
	Polysum = Polyinit();
	MaxPower = Poly1->HighPower + Poly2->HighPower - 1;
	for (i = 0; i < Poly1->HighPower; i++)
		for (j = 0; j < Poly2->HighPower; j++)
			Polysum->CoeffArray[i+j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
	Polysum->HighPower = MaxPower;
	return Polysum;
}
Polynomial Polysub(Polynomial Poly1,Polynomial Poly2)
{
	static Polynomial Polysum;
	int MaxPower;
	int i;
	Polysum = Polyinit();
	MaxPower= Poly1->HighPower >= Poly2->HighPower?Poly1->HighPower:Poly2->HighPower;
	for (i = 0; i < MaxPower; i++)
		Polysum->CoeffArray[i] = Poly1->CoeffArray[i] - Poly2->CoeffArray[i];
	Polysum->HighPower = MaxPower;
	return Polysum;
}
Polynomial Polyadd(Polynomial Poly1, Polynomial Poly2)
{
	static Polynomial Polysum;
	int MaxPower;
	int i;
	Polysum = Polyinit();
	MaxPower= Poly1->HighPower >= Poly2->HighPower?Poly1->HighPower:Poly2->HighPower;
	for (i = 0; i < MaxPower; i++)
		Polysum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
	Polysum->HighPower = MaxPower;
	return Polysum;
}
void Polyclear(Polynomial Poly)
{
	int i;
	for (i = 0; i <= MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}
Polynomial Polymake(int data[],int length)
{	
	static Polynomial Poly;
	int i;
	Poly = (Polynomial)malloc(sizeof(struct Node));
	Poly->HighPower = 0;
	for (i = 0; i < length; i++)
	{
		Poly->CoeffArray[i] = data[i];
		Poly->HighPower++;
	}
	return Poly;
}
Polynomial Polyinit()
{
	static Polynomial Poly;
	int i ;
	Poly = (Polynomial)malloc(sizeof(struct Node));
	for (i = 0; i <= MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
	return Poly;
}
void Polyprint(Polynomial Poly)
{
	int i = 0, temp;
	for (i = Poly->HighPower-1; i >= 0 ; i--)
	{
		temp = Poly->CoeffArray[i];
		if(i != 0)
			printf("%dx^%d+", temp, i);
		else
			printf("%d\n", temp);
	}
}