#include "TextQuery.h"



TextQuery::TextQuery(ifstream &infile)
	:Line( new vector<string> )
{
	
	Line->resize(1);
	string s;
	for (int i = 0; getline(infile, (*Line)[i] ); i++)
	{
		Line->resize(i + 2);
		istringstream record( (*Line)[i] );
		while (record >> s)
		{
			auto &lines = word[s];//& is import
			if (!lines)
			{
				lines.reset(new set<int>);
			}
			lines->insert(i+1);
			
		}
	}
}



QueryResult TextQuery::query(string s)
{
	if (word.find(s) != word.end())
	{
		auto ptr_map = word[s];
		return QueryResult(s,ptr_map,Line);
	}
	else
	{
		cout << "Not in" << endl;
		static shared_ptr< set<int> > nodata(new set<int>);//如果不是静态的话当函数结束,计数为0外界无法使用
		return QueryResult(s, nodata, Line);
	}
}

TextQuery::~TextQuery()
{
}
