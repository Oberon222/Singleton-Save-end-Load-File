#include<iostream>
#include<string>
#include <fstream>
using namespace std;

class WorkWithTheFile
{
private:
	static WorkWithTheFile* wf;
	WorkWithTheFile() {}
	WorkWithTheFile(const WorkWithTheFile&) = delete;
	WorkWithTheFile& operator = (WorkWithTheFile&) = delete;
	
public:
	static WorkWithTheFile* GetInstanse()
	{
		if (wf == nullptr) wf = new WorkWithTheFile();
		return wf;  
	}

	void Record(string message)
	{
		string fileName = "Message.txt";
		ofstream fout;
		fout.open(fileName, fstream::app);
		bool isOpen = fout.is_open();
		if (!isOpen) cout << "Error!" << endl;

		fout << message << endl;
		fout.close();
	}

	void Reading()
	{
		ifstream fin;
		fin.open("Message.txt");
		if (!fin.is_open()) cout << "Error!" << endl;
		string data;
		while (!fin.eof())
		{
			data = " ";
			fin >> data;
			cout << data << endl;
		}
		fin.close();

	}
};

WorkWithTheFile* WorkWithTheFile::wf = nullptr;

int main()
{
	string message = " Hello!!!!";
	WorkWithTheFile* workFile = WorkWithTheFile::GetInstanse();
	workFile->Record(message);


	system("pause");
	return 0;
}