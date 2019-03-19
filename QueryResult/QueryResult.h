#pragma once
#include"标头.h"
class QueryResult
{
	friend ostream &print(ostream &os, const QueryResult lh);
public:
	QueryResult(string s, shared_ptr< set<int> > p, shared_ptr< vector<string> > f);
	~QueryResult();
private:
	string QueryWord;
	shared_ptr< vector<string> > Line;
	shared_ptr< set<int> >  lines;
};

