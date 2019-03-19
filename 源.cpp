#include"标头.h"
#include "TextQuery.h"
#include"QueryResult.h"

using namespace std;

ostream &print(ostream &os, const QueryResult lh)
{
	os << lh.QueryWord << " occur " << lh.lines->size() << " ";
	if (lh.lines->size() > 1) { os << "times" << endl; }
	else { os << " times" << endl; }
	for (auto num : *lh.lines)
	{
		os << "\t(line " << num << ") "
			<< *(lh.Line->begin() + num - 1 )<< endl;
	}
	return os;
}

void  runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while (1)
	{
		cout << "please enter in: " << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		print( cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream in("test.txt");
	runQueries(in);
	return 0;
}
