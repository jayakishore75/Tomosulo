// CompArch.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "SuperScalar.h"

using namespace std;

int main()
{
	SuperScalar scInst;

	if (0 != scInst.ReadInputFile("assembly.txt"))
	{
		cout << "read failure";
		cout << "Add the instruction file as the name 'assembly.txt' in executable folder or project folder";
	}

	scInst.Simulate();

    return 0;
}

/************************************************************************/
/*Reading the input file 
useful links:
http://www.cplusplus.com/reference/string/string/find/
*/
/************************************************************************/
int SuperScalar::ReadInputFile(string path)
{
	int ret = 0;
	string strLine;
	
	//Sequencial reader, become false once these contents are read from file
	bool bReadLinesOfCode = true;
	bool bReadCode = true;
	bool bReadLinesOfMemory = true;
	bool bReadMemory = true;

	//Total line of code
	int linesOfCode = 0;

	//Total line of memory
	int linesOfMemory = 0;
	
	//Current line of code
	int currentLineOfcode = 0;
	
	//Current line of memory
	int currentLineOfMemory = 0;

	//!< Read the input file
	ifstream inputFile(path);

	//!< Check if file is open
	if (inputFile.is_open())
	{
		while (getline(inputFile, strLine))
		{
			//!< Remove the comment.
			std::size_t locate = strLine.find("--");
			if(string::npos != locate)
			{
				strLine.resize(locate);
			}

			//!< move to next line if the entire line is a comment
			if (0 != strLine.length())
			{
				cout << strLine << endl;
				//!< Read first content i.e number of lines of code
				if (bReadLinesOfCode)
				{
					stringstream ss(strLine);
					if(ss >> linesOfCode)
						bReadLinesOfCode = false;
				}
				else if (bReadCode)
				{					
					AddInstruction(strLine);
					if (currentLineOfcode < linesOfCode-1)
						currentLineOfcode++;
					else
						bReadCode = false;
					
				}
				else if (bReadLinesOfMemory)
				{
					stringstream ss(strLine);
					ss >> linesOfMemory;
					bReadLinesOfMemory = false;
				}
				else if (bReadMemory)
				{
					if (++currentLineOfMemory > linesOfMemory)
						bReadMemory = false;
					else
						AddMemory(strLine);
				}
			}
		}
		inputFile.close();

		m_iPCMax = linesOfCode;
	}
	else
	{
		cout << "Unable to open file";
		ret = -1;
	}

	return ret;
}