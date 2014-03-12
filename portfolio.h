#ifndef PORTFOLIO_H
#define PROTFOLIO_H

#include "matrices.h"

//Í¼ÐÎ×éºÏ
class Portfolio:public Matrices
{
public:
    Portfolio();
protected:
    void init();
    void setAll();
};
#endif // PROTFOLIO_H
