
/*
Programmer:-   Shivam Mohite
Topic:-        Finding And Replacing String from File

Problem Statement:- Wite a cpp program using comand line arguments to search for a word in a file and replace it with the specified word the uses of the program are shown below
$ change<old word> <new word> <file name>

Algorithm:-
     1]Start
     2]While Compiling give the word which is to be replaced and the word you want to replaced and the file name.
     3]End

*/

 #include <fstream>
 #include <iostream>
 #include <string.h>
 #include<cstdlib>
 using namespace std;
 int main(int argc,char *argv[])
 {
      if(argc<4)
      {
           cout<<"Insufficient number of arguments on command line\n";
           exit (1);
      }
      string data,newdata; // for user input
      fstream fin;
      cout<<"Find string \""<<argv[2]<<"\" and replace with \""<<argv[3]<<"\" in file\""<<argv[1]<<" \"\n";
      cout<<"**************Contents of file before replacing*********\n";
      fin.open(argv[1],ios::in);
      if(!fin)
      {
           cout<<"error opening file";
           return 1;
      }
      while(fin)
      {
           getline(fin,data);
           cout<<data<<endl;
      }
      fin.close();
      fin.open(argv[1],ios::in);
      newdata="";
      if(!fin)
      {
           cout << "Unable to open file";
           exit(1);
      }
      while(fin)
      {
           getline(fin,data);
           int a =(int) data.find(argv[2],0);
           while (a != string::npos)
           {
                data.replace(a,strlen(argv[2]),argv[3]);
                a =(int) data.find(argv[2],(a+1));
           }
           newdata=newdata+data+"\n";
      }
      fin.close();
      fin.open(argv[1],ios::out);
      if(!fin)
      {
           cout<<"error opening file";
           return 1;
      }
      fin<<newdata;
      cout<<"Replacement successful\n";
      fin.close();
      cout<<"********************Contents of file after replacing**************\n";
      fin.open(argv[1],ios::in);
      if(!fin)
      {
           cout<<"error opening file";
           return 1;
      }
      while(fin)
      {
           getline(fin,data);
           cout<<data<<endl;
      }
      fin.close();
      return 0;
 }
