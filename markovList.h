#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;


class markovList
{
	private:

		struct edge
		{
			edge* destinatin;
			edge* next;
			double weight;
			string word;
		};

		map<string, edge*> corpus;
		int corpusSize;
		
	public:
		markovList(const char*);
		~markovList();
		string generate(int);
};



markovList::markovList(const char* filename)
{
	cout << "here0";
	ifstream file(filename);
	stringstream parser, splitter;
	string line, index, word;
	float weight;
	edge* newEdge;
	int i = 0;
	srand (time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');
	cout << "here1";
	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		cout << "here2";
		parser.clear();
		parser << line;
		getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
		corpus[index] = newEdge;
		while(getline(parser, word, ','))
		{
			cout << "here3";
			edge* hood = new edge;
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			hood->word = word;
			hood->weight = weight;
			newEdge->next = hood;
			newEdge = newEdge->next;
		}
	}}
}

markovList::~markovList()
{	edge* temp;
	string word = temp->word;

	for(map<string,edge*>::iterator it = corpus.begin(); it!=corpus.end(); ++it)
	{
		while(it->second)
		{
			temp = it->second->next;
			delete it->second;
			it->second = temp;
		}
		
	}
}
		
string markovList::generate(int length)
{
	map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point

	string fullLine = "";
	for(int i = 0; i < length; i++)
	{
		double roll = (float)rand()/RAND_MAX;
		double sumEdges = 0.0;
		string temp = "";
		
		while(sumEdges > roll)
		{
			sumEdges += it->second->weight;
			if(sumEdges < roll)
			{
				temp = it->second->word;
			}
			it->second = it->second->next;
		}
		fullLine += temp + " ";
		it->second = corpus[temp];
	}
	return fullLine;
}


#endif