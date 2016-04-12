#ifndef SEARCHNODE_H
#define SEARCHNODE_H


#include <vector>
#include <algorithm>

typedef std::pair<int, int> Position;

class SearchNode
{
public:
    SearchNode(const Position& currentPos, float _H, float deltaG, SearchNode* prev);
    ~SearchNode();

    void resetPrev(SearchNode* prev, float deltaG);
    float distance() const { return F; } //Return approximation of total cost (F)
    static bool lessThan(SearchNode* node1, SearchNode* node2) { return node1->distance() > node2->distance(); } //Less than function for sorting
public:
    SearchNode* prevNode;
    Position pos;
    float G, H, F;
};

#endif