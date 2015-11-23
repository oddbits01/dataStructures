//James Ebert
//ptr, struct, array

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Box{

	double weight;
	int width;
	int depth;
	int length;
};

Box* buildBox();
Box* buildCube(int, int);

int _tmain()
{
	Box* bob = new Box;	
	(*bob).weight=5.55;
	
	bob->width=5;
	bob->length=6;
	bob->depth=7;
	cout<<"weight: "<<bob->weight<<"     area: "<<bob->width*bob->length*bob->depth<<endl;
	delete bob;

	bob=buildBox();
	cout<<"weight: "<<bob->weight<<"     area: "<<bob->width*bob->length*bob->depth<<endl;
	cout<<bob<<endl;
	delete bob;

	cout<<bob<<endl;
	cout<<bob->weight<<endl;

	Box* ary[5];

	for(int i=0;i<5;++i){
		ary[i]=buildCube(i*3,i);
	}


	system("pause");
	return 0;
}

Box* buildBox(){
	Box* temp = new Box;
	temp->depth = 0;
	temp->length = 0;
	temp->weight = 0;
	temp->width = 0;

	return temp;
}

Box* buildCube(int weight, int side){
	Box* temp= new Box;
	temp->weight = weight;
	temp->depth = temp->length = temp->width = side;
	return temp;
}
