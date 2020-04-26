#include <iostream>
#include <string.h>
#include <string>
using namespace std;

namespace HSmanagement
{
	const int size = 10;
	
	extern void clean_Table(long int scores[size], string names[size]);
	extern void copy_Table(long int scoresToCopy[size], string namesToCopy[size], long int copiedScore[size], string copiedName[size]);
	extern void add_Score(long int newScore, string newName, long int scores[size], string names[size]);
	extern int find_Score(string name, long int scores[size], string names[size]);
	extern void higher_To_Lowest(long int scores[size], string names[size]);
}
