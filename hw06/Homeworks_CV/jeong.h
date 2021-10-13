#ifndef JEONG_H
#define JEONG_H
#include "kfc.h"
#include "stdlib.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <QDebug>
#include <fstream>

using namespace std;


struct EdgeInfo{
    int     nEdgeX;
    int     nEdgeY;
    int     nEdgeDir;   // 4 way. 아래의 ang을 통해 dir을 구한다.
    double  dEdgeAngD;   // Deg 0~360 얘는 엣지점에서 바깥을 향하거나 안을 향하는 각을 나타내는 것이다.
    double  dEdgeMag;
};

struct ModelInfo{
    int     nModelX;
    int     nModelY;
    double  dModelAngR;   // 얘는 모델 중심과 엣지점간의 각을 나타내는 것이다. RAD
    double  dModelDist;  // for generalized hough transform. distance from the center point
};


struct Point2d{
    double _nx;
    double _ny;
    Point2d(){

    }
    Point2d(double x, double y){
        _nx = x;
        _ny = y;
    }
};

struct Point2i{
    int _nx; // col
    int _ny; // row
    Point2i(){

    }
    Point2i(int y, int x){ // 행렬.. 아오..
        _nx = x;
        _ny = y;
    }
};



class Jeong
{
private:
    unsigned int        _jRow = 0;
    unsigned int        _jCol = 0;
    unsigned int        _jSize = 0;
    const KImageColor*  _icPtr;
    const KImageGray*   _igPtr;


// Hough Circle //
    KArray<double>      _arVotes;
    int              _dSx;
    int              _dSy;
    int              _dSr;

public:
    Jeong();
    Jeong(const KImageColor& icImg);
    Jeong(const KImageGray& igImg);
    ~Jeong();

    vector<EdgeInfo*>       Edge;
    vector<ModelInfo*>      Model[4]; // dir 4개
    vector<Point2i>         CircleCenter;


    unsigned int            Row() const {return _jRow;}
    unsigned int            Col() const {return _jCol;}
    unsigned int            Size() const{return _jSize;}
    void                    SetPtr(const KImageColor& icImg);
    void                    SetPtr(const KImageGray& igImg);
    KImageGray              LumiContrast(const int a, const int b, const int ap, const int bp) const;
    KImageGray              LumiContrast(const KImageGray& igImg, const int a, const int b, const int ap, const int bp)const;
    unsigned int            OtsuBetween() const;
    unsigned int            Otsubetween(const KImageGray& igImg) const;

    KImageGray              Dilation(const KImageGray& igImg) const;
    KImageGray              Erosion(const KImageGray& igImg) const;
    KImageGray              Opening(const KImageGray& igImg) const;
    KImageGray              Closing(const KImageGray& igImg) const;
    KImageWord              Labeling(const KImageGray& igImg, KImageColor *icpColor) const;
    void                    HistoEqualize(const KImageColor& icMain, KImageColor& icOutput) const;
    void                    HistoMatch(const KImageColor& icOrigin, const KImageColor& icTarget, KImageColor& icOutput) const;
    int                     getRandomNumber(int min, int max) const;
    void                    SaltPepperNoise(const KImageColor icIn, KImageColor &icOut, double dPercent)const;
    void                    GaussianNoise(const KImageColor icIn, KImageColor &icOut, double dMean, double dVar)const;
    void                    MeanFilter(const KImageColor icIn, KImageColor& icOut, int kernelsize) const;
    void                    GaussianFilter(const KImageColor icIn, KImageColor& icOut, double dSigma) const;
    void                    GaussianFilter2(const KImageColor icIn, KImageColor& icOut, double dSigma) const;
    void                    CannyEdgeDetection(const KImageGray& igIn, KImageGray& igOut, int lowT, int highT);
    void                    HoughCircle(const KImageGray& igIn, KImageGray& igOut, KImageGray &igVoting,int R);
    void                    GeneralizedHoughTransform(const KImageGray igIn, KImageGray& igOut);

};

#endif // JEONG_H
