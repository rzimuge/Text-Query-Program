#include "QueryResult.h"



QueryResult::QueryResult(string s, shared_ptr< set<int> > p, shared_ptr< vector<string> > f)
	:QueryWord(s),lines(p),Line(f)
{
}


QueryResult::~QueryResult()
{
}
