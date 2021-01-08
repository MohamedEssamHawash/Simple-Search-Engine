#include <iostream>
#include "inord_list.h"
#include <string>
#include <cstring>
#include <string.h>
#include <locale>
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc , char* argv[])
{
    string word ;
    int wordcounter=0 ;
    inord_list mylist ;
    string ipline ;
    int nline=0 ;
    int cline=0 ;
    if(argc != 3)
    {
        cout<<"Incorrect number of arguments" ;
    }
    else
    {
        fstream ipfile ;
        ipfile.open(argv[1]) ;
        if(ipfile.fail())
        {
            cout<<"File not found"<<endl ;
            return 0 ;
        }
        else
        {
            while (getline(ipfile,ipline))
            {
                 nline++ ;
                 cline=cline+ipline.length();
                 stringstream lword(ipline);
                 while(lword>>word)
        {
            if(word.compare("[")==0 ||word.compare("]")==0 || word.compare("{")==0 || word.compare("}")==0 || word.compare(";")==0 || word.compare(":")==0 || word.compare(",")==0 || word.compare(".")==0 || word.compare(")")==0 || word.compare("(")==0 || word.compare("&")==0 || word.compare("")==0)
            {

            }
            else
             {int wordlen ;
            wordlen=word.length();
            int windex ;
            for(windex=0 ; windex<wordlen ; windex++)
            {
                word[windex]=tolower(word[windex]);
            }
            word[windex]=0 ;
            if(mylist.insertion(word,nline))
            {

            }
            wordcounter++ ;
             }
        }
            }
            ipfile.close() ;

        }
        fstream commandfile;
        commandfile.open(argv[2]) ;
        if(commandfile.fail())
        {
            cout<<"File not found"<<endl ;
            return 0 ;
        }

        else
        {
            string command[100] ;
        string temp ;
        int x=0 ;
        while(commandfile>>temp)
        {
            command[x]=temp;
            x++ ;
        }
        for(int y=0 ; y<x ; y++)
        {
            if(command[y].compare("wordCount")==0)
            {

                cout<<wordcounter<<" words"<<endl ;

            }
            else if(command[y].compare("distWords")==0)
            {

                       int z ;
                       z=mylist.distWords(wordcounter) ;
                       cout<<z<<" distinct words"<<endl;

            }
            else if(command[y].compare("frequentWord")==0)
            {
                mylist.frequentWord() ;
            }
            else if(command[y].compare("charCount")==0)
            {
                       int z ;
                     //z=mylist.charCount(wordcounter);
                      z=nline+cline ;
                      cout<<z<<" characters"<<endl ;

            }
            else if (command[y].compare("countWord")==0)
            {

                        string z ;
                    int co ;
                    int len ;
                    int zindex ;
                    z=command[y+1] ;
                    len=z.length();
                    for(zindex=0 ; zindex<len ; zindex++)
                    {
                        z[zindex]=tolower(z[zindex]);
                    }
                    z[zindex]=0 ;
                    co=mylist.countWord(z) ;
                    cout<<z<<" is repeated "<<co<<" times"<<endl ;
                    y=y+1 ;

            }
           else if(command[y].compare("starting")==0)
            {

                       string z ;
                    int len ;
                    int zindex ;
                    z=command[y+1] ;
                    len=z.length();
                    for(zindex=0 ; zindex<len ; zindex++)
                    {
                        z[zindex]=tolower(z[zindex]);
                    }
                    z[zindex]=0 ;
                    mylist.starting(z) ;
                    y=y+1 ;

            }
            else if (command[y].compare("containing")==0)
            {

                       string z ;
                        int len ;
                        int zindex ;
                        z=command[y+1] ;
                        len=z.length();
                        for(zindex=0 ; zindex<len ; zindex++)
                        {
                            z[zindex]=tolower(z[zindex]);
                        }
                        z[zindex]=0 ;
                        mylist.containing(z) ;
                        y=y+1 ;

            }
            else if (command[y].compare("search")==0)
            {

                       string z ;
                    int len ;
                    int zindex ;
                    z=command[y+1] ;
                    len=z.length();
                    for(zindex=0 ; zindex<len ; zindex++)
                    {
                        z[zindex]=tolower(z[zindex]);
                    }
                    z[zindex]=0 ;
                    mylist.searching(z,wordcounter) ;
                    y=y+1 ;

            }
            else
            {
               cout<<"Undefined command"<<endl;

            }
        }
        commandfile.close();

    }

        }
    return 0;
}

