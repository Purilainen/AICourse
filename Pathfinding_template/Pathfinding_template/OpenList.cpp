#include "OpenList.h"

SearchNode* OpenList::findFromOpenList(const Position& pos)
{
    for (size_t i = 0; i < openList.size(); ++i)
    {
        if (openList[i]->pos == pos)
        {
            return openList[i];
        }  
    }
    return 0;
    
}

SearchNode* OpenList::removeSmallestFromOpenList()
{
    SearchNode* result = *(openList.end() - 1); // Take last one
    openList.pop_back(); //Remove last;
    return result;
}

void OpenList::insertToOpenList(SearchNode* node)
{
    openList.push_back(node);
    sortOpenList();
}

void OpenList::sortOpenList()
{
    std::sort(openList.begin(), openList.end(), &SearchNode::lessThan);
}

