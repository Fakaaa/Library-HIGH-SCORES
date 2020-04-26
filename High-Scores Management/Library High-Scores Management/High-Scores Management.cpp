#include "HSmanagement.h"

namespace HSmanagement
{

	string names[size];
	long int scores[size];

	void clean_Table(long int scores[size], string names[size]){
		for (int i = 0; i < size; i++)
		{
			scores[i] = 0;
			names[i] = "Empty";
		}
	}

	void add_Score(long int newScore, string newName, long int scores[size], string names[size]){
		int id = 0;
		long int auxScore[size];
		string auxName[size];

		for (int i = 0; i < size; i++){
			if (scores[i] == 0){
				id = i;
				break;
			}
			else if(scores[i] != 0){
				continue;
			}

			if (i == size - 1 && scores[i] != 0){
				
				clean_Table(auxScore, auxName);
				copy_Table(scores,names,auxScore,auxName);
				higher_To_Lowest(auxScore,auxName);

				for (int j = 0; j < size; j++)
				{
					if (scores[j] == auxScore[size - 1]){
						id = j;
						break;
					}
				}
			}
		}
		scores[id] = newScore;
		names[id] = newName;
	}

	void copy_Table(long int scoresToCopy[size], string namesToCopy[size], long int copiedScore[size], string copiedName[size]){
		for (int i = 0; i < size; i++)
		{
			copiedScore[i] = scoresToCopy[i];
			copiedName[i] = namesToCopy[i];
		}
	}

	int find_Score(string name, long int scores[size], string names[size]){
		int idScore = 0;
		for (int i = 0; i < size; i++){
			if (names[i] == name) {
				idScore = i;
				break;
			}
		}
		return scores[idScore];
	}

	void higher_To_Lowest(long int scores[size], string names[size]){
		int auxScore = 0;
		string auxName;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++){
				if (scores[j] < scores[j + 1]) {
					auxScore = scores[j];
					auxName = names[j];
					names[j] = names[j + 1];
					scores[j] = scores[j + 1];
					names[j + 1] = auxName;
					scores[j + 1] = auxScore;
				}
			}
		}
	}
}
