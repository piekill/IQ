#ifndef OVERLAY_H
#define OVERLAY_H

#include "matrices.h"

//ͼ�ε���
class Overlay:public Matrices
{
public:
    Overlay();
protected:
    void init();
    void setAll();
};
#endif // OVERLAY_H
