#ifndef JEONG_H
#define JEONG_H
#include "kfc.h"
#include "stdlib.h"
#include <iostream>
#include <algorithm>
#include <vector>


typedef struct Point2d{
    int _nx;
    int _ny;
}Point2d;



class Jeong
{
private:
    unsigned int        _jRow = 0;
    unsigned int        _jCol = 0;
    unsigned int        _jSize = 0;
    const KImageColor*  _icPtr;
    const KImageGray*   _igPtr;

public:
    Jeong();
    Jeong(const KImageColor& icImg);
    Jeong(const KImageGray& igImg);
    ~Jeong();


    std::vector<Point2d>    v_Point2d;


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





};

#endif // JEONG_H
