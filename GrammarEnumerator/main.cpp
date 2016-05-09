/*This program computes the number of n letter words
formed from the alphabet [a, b], where there could be no two consecutive a's.
The program is based on the observation that a word can either start with
an a or a b. The sum of sets of words startng with an a and those starting with
a b gives the total word count. This could be modeled recursively as a fibonacci
sequence with n1 = 2 and n2 =  3 as starting conditions. Dynamic programming is used
to avoid stack overflow for sufficiently high n*/
#include <iostream>
#include <vector>

int EnumerateGrammar(int n, std::vector<int>& fibTable) {
	int answer;
	//check the table for a previously computed answer
	if (fibTable[n] >= 0)
		return fibTable[n];
	if (n == 1)
		return 2;
	else if (n == 2)
		return 3;
	else
		answer = EnumerateGrammar(n - 1, fibTable) + EnumerateGrammar(n - 2, fibTable);
	fibTable[n] = answer;
	return answer; 
}

int main() {
	int n{ 1 };

		std::cout << "Please enter the word length." << std::endl;
		std::cin >> n;
		
		std::vector<int> fibTable(n + 1, -1);
		std::cout << "There are " << EnumerateGrammar(n, fibTable) << " possible combinations for this number of letters." << std::endl;

		system("pause");
		return 0;
}