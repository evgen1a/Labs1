
#include <iostream> 
#include <fstream>  
#include <string>   
#include <sstream>   
using namespace std;

void Func(char *FileName)
{
	ifstream in(FileName); 

	if(!in.is_open())
	{
		cout << "�� ������� ������� ����." << endl;
		exit(-1);
	}

	string str, word, minStrWord; 
	string allText; 
	int minWord = 71; 
	cout << "����� �����\n" << endl;
	while(!in.eof()) 
	{
		getline(in, str);    
		allText += str + " ";
		if(str.length() > 70)   
			{
				cout << "������!������ ����� ������ 70 ��������.";
				exit(-1);

			}
		cout << str << endl; 

		stringstream ss(str); 

		while(ss >> word) 
		{
		
			if(word.length() < minWord) {
			 minWord = word.length();
			  minStrWord = word;
			   }
		}
	}

	cout << "\n����� �������� ����� \"" << minStrWord << "\",���-�� �������� = " << minWord << endl;
	cout << "\n\n������� ����� �������" << endl;
	cout << "\n�����,���������� ����������� ���-�� �������� " << endl;
	

	
	stringstream ss(allText);  

		while(ss >> word) 
		{
			
			if(word.length() == minWord) {
			 cout << word  << '\n';
			  }
		}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	Func("input.dat");
	

	return 0;
}
