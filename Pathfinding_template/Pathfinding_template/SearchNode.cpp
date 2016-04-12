#include "SearchNode.h"

SearchNode::SearchNode(const Position& currentPos, float _H, float deltaG, SearchNode* prev)
    : prevNode(0), pos(currentPos), G(0), H(_H)
{
    resetPrev(prev, deltaG);
}

void SearchNode::resetPrev(SearchNode* prev, float deltaG)
{
    prevNode = prev;

    if (prev == 0)
        G = 0.0f;
    else
        G = deltaG + prev->G;

    F = H * + G;
}
