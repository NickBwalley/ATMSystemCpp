#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string strReplace = "HELLO"; //String to search
    string strNew = "GOODBYE";	//String To re
    ifstream filein("test.txt"); //File to read from
    ofstream fileout("temp.txt"); //Temporary file
    if(!filein || !fileout) //if both files are not available
	{
        cout << "Error opening files!" << endl;
        return 1;
    }
    string strTemp;
    //bool found = false;
 while(filein >> strTemp)//it will check line from test to strTemp string
    {
        if(strTemp == strReplace)//if your word found then replace
		{
            strTemp = strNew;
            //found = true;
        }
        strTemp += "\n";
        fileout << strTemp;//output everything to fileout(temp.txt)
        //if(found) break;
    }
    return 0;
}
