#ifndef PORTFOLIO_H
#define PROTFOLIO_H

#include "matrices.h"

//ͼ�����
class Portfolio:public Matrices
{
public:
    Portfolio();
protected:
    void init();
    void setAll();
};
#endif // PROTFOLIO_H
