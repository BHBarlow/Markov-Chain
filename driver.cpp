#include<iostream>
//#include "markovMat.h"
#include "markovList.h"
using namespace std;

int main()
{
	//markovMat* chain = new markovMat("corpus.txt");
	markovList* chain;
	chain = new markovList("corpus.txt");
	
	cout << chain->generate(100) << endl;
	return 0;
}