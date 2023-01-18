#include <iostream>
#include <string>
#include "autocomplete.h"

int main()
{
	
	TrieNode* trieWord = new TrieNode();
	insert(trieWord, "auto");
	insert(trieWord, "boat");
	insert(trieWord, "cat");
	insert(trieWord, "cater");
	insert(trieWord, "call");
	insert(trieWord, "dog");
	insert(trieWord, "can");
	insert(trieWord, "hello");
	insert(trieWord, "cache");
	insert(trieWord, "rut");
	insert(trieWord, "run");

	std::string wordVariants; 
	wordVariants.clear(); 
	std::string VersionWord; 
	std::string inputWord; 
	std::string fullText; 
	std::string tempWord; 
	bool space = true; 
	while (std::cin) 
	{
		getline(std::cin, inputWord);
		for (size_t i = 0, ib = 0; i < inputWord.length(); ++i)
		{
			fullText.push_back(inputWord[i]);
			tempWord.push_back(inputWord[i]);

			if (inputWord[i] == ' ')
			{
				tempWord.clear(); 
			}
		}
		wordSubstitution(trieWord, wordVariants, tempWord);
		if (wordVariants.empty())
		{
			tempWord.clear();
			std::cout << fullText;
			continue;
		}
		wordVariants.erase(wordVariants.length() - 1); 
		int choise = 1; 
		std::cout << std::endl << choise << " ";
		for (size_t i = 0; i < wordVariants.length(); ++i) 
		{
			if (wordVariants[i] == ' ')
			{
				choise++;
				std::cout << std::endl << choise;
			}
			std::cout << wordVariants[i];
		}
		std::cout << "\nSelect the appropriate word by pressing 1, 2 or 3. If there is no such word, press 0\n"; 
		std::cin >> choise;
		std::cin.ignore(32767, '\n');
		for (size_t i = 0; i < wordVariants.length(); ++i) 
		{
			if (choise == 1)
			{
				VersionWord.push_back(wordVariants[i]);
			}
			if (wordVariants[i] == ' ')
			{
				--choise;
			}
			if (choise < 1)
			{
				break;
			}
		}
		if (!VersionWord.empty())
		{
			fullText.erase(fullText.length() - tempWord.length());
			fullText += VersionWord;
			tempWord.clear();
			std::cout << fullText;
		}
		else 
			std::cout << fullText;

		wordVariants.clear();
		VersionWord.clear();
	}
	return 0;
}

