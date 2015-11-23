//James Ebert
//ptr, struct, array solution

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Part{

	string name;
	int count;
	float price;
};

struct Search{
	string minPriceName;
	string maxPriceName;
	string minCountName;
	string maxCountName;
	float minPrice;
	float maxPrice;
	float minCount;
	float maxCount;
	float total;
};

Part* buildPart();

int _tmain()
{
	ifstream infile;
	infile.open("data.txt"); //open file for reading
	
	Part* ary[10]; //set up array
	string name; //set up temp vars for our data members
	int count;
	float price;

	for(int i=0;i<10;++i){ //read 10 lines from the file and assign their values to our structurs
		ary[i]=buildPart();
		infile>>name>>count>>price;
		ary[i]->name=name;
		ary[i]->count=count;
		ary[i]->price=price;
	}

	Search* ptr = new Search;

	ptr->maxCount = ptr->minCount = ary[0]->count; //give initial values to all of our search memebers
	ptr->maxPriceName = ptr->minPrice = ary[0]->price;
	ptr->maxCountName = ptr->minCountName = ptr->maxPriceName = ptr->minPriceName = ary[0]->name;
	ptr->total = ary[0]->price * ary[0]->count; //initialise total to cost of first item * stock 

	for(int i=1;i<10;++i){//since we initialised everything to ary[0] we don't need to check it
		if(ptr->maxCount < ary[i]->count){
			ptr->maxCount = ary[i]->count;
			ptr->maxCountName = ary[i]->name;
		}
		if(ptr->minCount > ary[i]->count){
			ptr->minCount = ary[i]->count;
			ptr->minCountName = ary[i]->name;
		}
		if(ptr->minPrice > ary[i]->price){
			ptr->minPrice = ary[i]->price;
			ptr->minPriceName = ary[i]->name;
		}
		if(ptr->maxPrice < ary[i]->price){
			ptr->maxPrice = ary[i]->price;
			ptr->maxPriceName = ary[i]->name;
		}
		ptr->total+=(ary[i]->count * ary[i]->price);
	}

	cout<<"most expensive: "<<ptr->maxPriceName<<"	cost: "<<ptr->maxPrice<<endl;
	cout<<"least expensive: "<<ptr->minPriceName<<"		cost: "<<ptr->minPrice<<endl;
	cout<<"most in stock: "<<ptr->maxCountName<<"		cost: "<<ptr->maxCount<<endl;
	cout<<"least in stock: "<<ptr->minCountName<<"	cost: "<<ptr->minCount<<endl<<endl;
	cout<<"total value of all stock: "<<ptr->total<<endl;

	system("pause");
	return 0;
}

Part* buildPart(){
	Part* temp = new Part;
	temp->name="";
	temp->count=0;
	temp->price=0;

	return temp;
}
