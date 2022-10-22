#include"string_stack.h"
#include "string_stack.cpp"
#include<string>
#include<sstream>
#include<fstream>

typedef std::string myData;

void tag_checker(StringStack<myData>& xml, std::string s)
{
	std::string tag = "";
	int begin = xml.GetLength()+1;
	int current = 0;
	for (size_t i = 0; i < s.size(); i++)
	{	
		//if beginning of tag push on t stack
		if (s[i] == '<')
		{
			tag = s[i];
			xml.Push(tag);
		}
		//if we find an end tag
		if (s[i] == '>')
		{
			//Check top of stack for a beginning tag <
			xml.Top(tag);
			if (tag == "<")
			{
				//pop from stack and clear data from tag
				xml.Pop(tag);
				tag = "";	
			}
		}
		current = xml.GetLength();
		if (current > begin)
		{
			std::cout << "Error Missing Tag at S[" << i-1 << "]\n";
			begin = current;	
		}	
	}
}

void read_file(StringStack<myData>& xml, std::string filename)
{
	std::ifstream my_file;
	std::stringstream temp;
	std::string s;

	my_file.open(filename);
	if (my_file.is_open())
	{
		temp << my_file.rdbuf();
	}
	my_file.close();
	s = temp.str();
	tag_checker(xml, s);	
}

int main()
{
	StringStack<myData> testing;
	read_file(testing, "sample.txt");
	testing.Print();
	std::cout<<"Stack Length:" << testing.GetLength();
}