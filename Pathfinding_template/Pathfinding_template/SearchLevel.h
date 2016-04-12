#ifndef SEARCHLEVEL_H
#define SEARCHLEVEL_H

#include "Texture.h"
#include "StreamTexture.h"
#include "SearchNode.h"

namespace
{
    void setPathColor(yam2d::StreamTexture* t, int x, int y)
    {
        t->getPixel(x, y)[0] = 0xff;
        t->getPixel(x, y)[1] = 0x00;
        t->getPixel(x, y)[2] = 0xff;
    }

    bool isRed(unsigned char* p)
    {
        return p[0] > 200;
    }

    bool isGreen(unsigned char* p)
    {
        return p[1] > 200;
    }

    bool isBlue(unsigned char* p)
    {
        return p[2] > 200;
    }
}

class SearchLevel
{
public:
    SearchLevel(yam2d::Texture* inputTex);
    ~SearchLevel() {}

    //Return actual distance from "fromNode" to "toPos" (These are adjacent nodes always so the lenght is 1)
    float getG(SearchNode* fromNode, const Position& toPos);
    //Return Heuristic distance
    float getH(const Position& fromPos, const Position& toPos);

    bool isWalkable(int posX, int posY);

    std::vector<Position> getAdjacentNodes(int posX, int posY);

private:
    yam2d::Texture* inputTexture;
};

#endif