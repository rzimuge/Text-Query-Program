#pragma once
#include"标头.h"
#include "QueryResult.h"
using namespace std;

class TextQuery
{
public:

	TextQuery(ifstream &infile);
	QueryResult  query(string s);

	~TextQuery();
private:
	shared_ptr< vector<string> > Line;
	map< string, shared_ptr< set<int> > >  word;
};

