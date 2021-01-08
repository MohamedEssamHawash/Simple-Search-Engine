#include "inord_list.h"

inord_list :: inord_list()
{
    head=NULL ;
    tail=NULL ;
    current=NULL ;
    pred=NULL ;
}

bool inord_list :: insertion(const listelemtype &e , int linenum)
{
    link addednode ;
    addednode = new node ;
    link pred ;
    if( head==NULL || e <= head -> element)
    {
        addednode -> element = e ;
        addednode -> line = linenum ;
        addednode -> next = head ;
        head = addednode ;
        return true ;
    }
    else
    {
        pred=head ;
        while ( pred->next != NULL && pred->next->element < e )
        {
            pred = pred -> next ;
        }
        addednode -> element = e ;
        addednode -> line = linenum ;
        addednode -> next = pred -> next ;
        pred -> next = addednode ;
        return 1 ;
    }
}
bool inord_list::first(listelemtype &e)
{
    if( head == NULL)
        return false ;
    else
    {
        current = head ;
        e=current -> element ;
        return true ;
    }
}
bool inord_list::next(listelemtype &e)
{
    if(head==NULL || current->next==NULL)
        return false ;
    else
    {
        current= current->next ;
        e=current->element ;
        return true ;
    }
}
int inord_list::distWords(int wordsCount)
{
    current=head ;
    int x=0 ;
    while( current->next != NULL && x<wordsCount )
    {
        while(current->next !=NULL && current->element.compare(current->next->element)==0)
        {
            current=current->next ;

        }
        x++ ;
        pred=current ;
        if(current->next != NULL)
        {
            current=current->next ;
        }
        if(current->next==NULL && current->element.compare(pred->element)!=0)
        {
            x++ ;
        }

    }
    return x ;
}
int inord_list::charCount(int wordsCount)
{
    current=head ;
    int x=1 ;
    int z=0 ;
    while(x<=wordsCount)
    {
        z=z+current->element.length() ;
        current=current->next ;
        x++ ;
    }
    return z ;
}
void inord_list::frequentWord()
{
    current=head ;
    int repeat=1 ;
    int maxi= repeat ;
    string temp;
    while(current!=NULL)
    {
        while(current->next!=NULL && current->element==current->next->element)
        {
            if(current->element.compare("an")==0 || current->element.compare("a")==0 || current->element.compare("the")==0 || current->element.compare("in")==0 || current->element.compare("on")==0 || current->element.compare("of")==0 || current->element.compare("is")==0 || current->element.compare("are")==0 || current->element.compare("and")==0 )
            {

            }
            else
            {
                 repeat++ ;
            if(repeat>maxi)
            {
                maxi=repeat ;
                temp=current->element ;
            }
            }
            current=current->next ;



        }
        current=current->next ;
        repeat=1 ;

    }
    cout<<"Most frequent word is: " ;
    current=head ;
    pred=head ;
    int counter ;
    while(current!=NULL)
    {
        counter=1 ;
        while(current->next!=NULL && current->element==current->next->element )
        {
            if(current->element.compare("an")==0 || current->element.compare("a")==0 || current->element.compare("the")==0 || current->element.compare("in")==0 || current->element.compare("on")==0 || current->element.compare("of")==0 || current->element.compare("is")==0 || current->element.compare("are")==0 || current->element.compare("and")==0 )
            {

            }
            else
            {
            counter++ ;
            if(counter==maxi)
            {
                cout<<current->element<<" " ;
            }
            }
            current=current->next ;
        }
        if(current!=NULL)
        {
            current=current->next ;
        }
    }
    cout<<endl ;
}
int inord_list::countWord(string word)
{
    current=head ;
    int NoOccurence=0 ;
    while(current!=NULL)
    {
         while (current!=NULL && current->element.compare(word)==0)
    {
        NoOccurence++ ;
        current=current->next ;
    }
        if(current!=NULL)
            current=current->next ;
        else
            break ;
    }
    return NoOccurence ;

}
void inord_list::starting(string sub)
{
    int len=sub.length();
    current=head ;
    int x , k ;
    int tap=0 ;
    int flag=0 ;
    while(current!=NULL)
    {
        for (int i=0 ; i<len ; i++)
        {
            if(sub[i]==current->element[i])
            {

            }
                else
                {
                   break ;
                }

             k=i ;
        }
        if((k+1)==len)
        {
            flag=1 ;
            pred=current ;
            x=inord_list::countWord(current->element);
            current=pred ;
            if(tap==0)
            {

            }
            else
            {
                cout<<"\t";
            }
            cout<<current->element<<": "<<x ;
            for(int j=1 ; j<x ; j++)
            {
                current=current->next ;
                if(current!=NULL)
                {
                }
                else
                {
                    break ;
                }
            }
            tap++ ;
            k++;
        }

            if(current!=NULL)
                {
                    current=current->next ;
                }
                else
                    break ;

    }
    if(flag==0)
    {
        cout<<"Word not found" ;
    }
    else
    {

    }
    cout<<endl ;
}
void inord_list::containing(string word)
{
    int found=0 ;
    int flag=0 ;
    int tap=0 ;
    current=head ;
    int x ;
    while(current!=NULL)
    {
        found=current->element.find(word);
        if(found!=-1)
        {
            flag=1 ;
            pred=current ;
            x=inord_list::countWord(current->element);
            current=pred;
            if(tap==0)
            {

            }
            else
            {
                cout<<"\t" ;
            }
            cout<<current->element<<": "<<x ;
            for(int j=0 ; j<x ; j++)
            {
                current=current->next ;
                if(current!=NULL)
                {
                }
                else
                {
                    break ;
                }
            }
            tap++ ;
        }
        else
        {
            current=current->next ;
        }
    }
    if(flag!=1)
    {
        cout<<"Word not found" ;
    }
    cout<<endl ;
}
void inord_list::searching(string word , int wordsCount)
{
    int arr[wordsCount] ;
    int indexline=0 ;
    current=head ;
    int found=0 ;
    int flag=0 ;
    int x ;
    while(current!=NULL)
    {
       found=current->element.find(word);
       if(found!=-1)
       {
           flag=1 ;
           pred=current ;
           x=inord_list::countWord(current->element) ;
           current=pred ;
           cout<<current->element<<":\tlines" ;
           for(int j=0 ; j<x ; j++)
           {
               while(current->next!=NULL && current->element==current->next->element && current->line==current->next->line && j<x)
               {
                   current=current->next ;
                   j++ ;
               }
               arr[indexline]=current->line ;
               //cout<<" "<<current->line ;
               indexline++ ;
               current=current->next ;
           }
           for(int u=indexline-1 ; u>=0 ; u--)
           {
               cout<<" "<<arr[u] ;
           }
           cout<<" "<<endl ;

           indexline=0 ;
       }
       else
       {
           current=current->next ;
       }

    }
    if(flag!=1)
    {
        cout<<"Word not found"<<endl ;
    }

}
