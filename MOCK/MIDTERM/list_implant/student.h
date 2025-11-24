#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "list.h"
template <typename T>
void CP::list<T>::implant(CP::list<T> &other,int pos1,int pos2,int count){
    if(count==0)return;

    int cur_count = 0;
    node* it = mHeader->next;
    for(int i=0;i<pos1;i++){
        it = it->next;
    }

    node* it2 = other.mHeader->next;
    for(int i=0;i<pos2;i++){
        it2 = it2->next;
    }
    
    node* it3 = it2;
    for(int i=1;i<count;i++){
        it3 = it3->next;
    }
    
    it2->prev->next = it3->next; // _ <--> it2....it3 <--> _
    it3->next->prev = it2->prev;
    other.mSize = other.mSize-count;

    it3->next = it->next; 
    it->next->prev = it3;
    it2->prev = it;
    it->next = it2;
    mSize = mSize+count;
    //std::cout<<it2->data;
}
#endif