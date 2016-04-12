#ifndef OPENLIST_H
#define OPENLIST_H

#include "SearchNode.h"


class OpenList
{
public:
    OpenList(){}
    ~OpenList(){}

    //Returns search node from given position, if it exists. Return 0 otherwise.
    SearchNode* findFromOpenList(const Position& pos); 
    SearchNode* removeSmallestFromOpenList();
    //Insert new SearchNode to open list and sort the open list according to (F).
    void insertToOpenList(SearchNode* node);
    void sortOpenList();
    void clear() { openList.clear(); }

    bool isEmpty() {return openList.empty(); }
    
private:
    typedef std::vector<SearchNode*> OpenListType;
    OpenListType openList;
};


#endif