#ifndef INORD_LIST_H_INCLUDED
#define INORD_LIST_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef string listelemtype;

class inord_list
{
public:
    inord_list();
    bool insertion(const listelemtype &e , int linenum) ;
    bool first (listelemtype &e) ;
    bool next (listelemtype &e) ;
    int distWords(int wordsCount) ;
    int charCount(int wordsCount) ;
    void frequentWord() ;
    int countWord (string word) ;
    void starting (string sub) ;
    void containing (string word) ;
    void searching (string word , int wordsCount) ;
private:
    struct node ;
    typedef node* link;
    struct node
    {
        listelemtype element ;
        link next ;
        int line ;
    };
    link head ;
    link tail ;
    link current ;
    link pred ;
};


#endif // INORD_LIST_H_INCLUDED
