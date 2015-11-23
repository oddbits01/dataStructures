//James Ebert
//ptr, struct, array

#include "stdafx.h"
#include <iostream>

using namespace std;

void check(char* p){
	if((*p)=='e'){
		cout<<"found it\n";
	}
}

int _tmain()
{
	char k;
	char * ptr;

	k='c';
	cout<<k<<endl;
	
	k='y';
	cout<<k<<endl;
	
	ptr=(&k);
	cout<<(*ptr)<<endl;

	char ary[5]={'J','a','m','e','s'};
	for(int i=0;i<5;++i){
		cout<<ary[i]<<endl;
	}

	ptr=ary;
	for(int i=0;i<5;++i){
		cout<<(*ptr)<<endl;
		++ptr;
	}
	cout<<(*ptr)<<endl;
	cout<<ptr[-3]<<endl;

	ptr=ary;

	for(int i=0;i<5;++i){
		check(ptr);
		++ptr;
	}
	
	system("pause");
	return 0;
}
