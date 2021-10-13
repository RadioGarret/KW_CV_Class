#include "jeong.h"

Jeong::Jeong()
{
    std::vector<std::pair<int,int>>   Edge;
}
Jeong::~Jeong()
{
}
Jeong::Jeong(const KImageColor& icImg){
    _jRow   = icImg.Row();
    _jCol   = icImg.Col();
    _jSize  = _jRow * _jCol;
    _icPtr  = &icImg;
}
Jeong::Jeong(const KImageGray& igImg){
    _jRow   = igImg.Row();
    _jCol   = igImg.Col();
    _jSize  = _jRow * _jCol;
    _igPtr  = &igImg;
}
void Jeong::SetPtr(const KImageColor &icImg)
{
    _jRow   = icImg.Row();
    _jCol   = icImg.Col();
    _jSize  = _jRow * _jCol;
    _icPtr  = &icImg;
}

void Jeong::SetPtr(const KImageGray &igImg)
{
    _jRow   = igImg.Row();
    _jCol   = igImg.Col();
    _jSize  = _jRow * _jCol;
    _igPtr  = &igImg;
}


KImageGray Jeong::LumiContrast(const int a, const int b, const int ap, const int bp) const
{
#ifdef _DEBUG
    assert(_igPtr != nullptr);
#endif
    KImageGray igTemp = KImageGray(*_igPtr);

    for(int i=0;i<igTemp.Row();i++){
        for(int j=0;j<igTemp.Col();j++){
            if(igTemp._ppA[i][j] < a)
                igTemp._ppA[i][j] = ap;
            else if(igTemp._ppA[i][j] >= a && igTemp._ppA[i][j] <=b){
                igTemp._ppA[i][j] = (bp-ap)/(b-a) * (igTemp._ppA[i][j] - a) + ap;
            }else{
                igTemp._ppA[i][j] = bp;
            }
        }
    }
    return igTemp;
}

KImageGray Jeong::LumiContrast(const KImageGray &igImg, const int a, const int b, const int ap, const int bp) const
{
    KImageGray igTemp = KImageGray(igImg);

    for(int i=0;i<igTemp.Row();i++){
        for(int j=0;j<igTemp.Col();j++){
            if(igTemp._ppA[i][j] < a)
                igTemp._ppA[i][j] = ap;
            else if(igTemp._ppA[i][j] >= a && igTemp._ppA[i][j] <=b){
                igTemp._ppA[i][j] = (bp-ap)/(b-a) * (igTemp._ppA[i][j] - a) + ap;
            }else{
                igTemp._ppA[i][j] = bp;
            }
        }
    }
    return igTemp;
}

unsigned int Jeong::OtsuBetween() const
{
#ifdef _DEBUG
    assert(_igPtr!=nullptr);
#endif

    // get histogram
    KHisto hTmp;
    hTmp.Histogram(*_igPtr);

    // variables
    double dq1_t = (hTmp[0])/_jSize;
    double dmu1_t = 0;
    double dmu1_tp1, dmu2_tp1, dq1_tp1;
    double dVar_tp1, dVarMax=0;
    unsigned int i_optimal_t; // optimal T. 아래 for문에서는 t+1임!!


    // global mean
    double dmu_g=0;
    for(int i=0;i<256;i++){
        dmu_g += i * (hTmp[i])/_jSize;
    }
    // searching for the optimal t(actually t+1)
    for(int t=0;t<254;t++){

        dq1_tp1 = dq1_t + (hTmp[t+1])/_jSize;
        if(dq1_tp1 == 0) // 아래 dmu1_tp1에서 분모가 dq1_tp1 인데, 0이면 무한대 됨.
            dq1_tp1 = 0.00001;

        dmu1_tp1 = ((dq1_t * dmu1_t) + (t+1)*(hTmp[t+1])/_jSize) / dq1_tp1;
        dmu2_tp1 = (dmu_g - dq1_tp1*dmu1_tp1) / (1-dq1_tp1);

        dVar_tp1 = dq1_tp1*(1-dq1_tp1)*(dmu1_tp1-dmu2_tp1)*(dmu1_tp1-dmu2_tp1);
        if(dVarMax<dVar_tp1){
            dVarMax = dVar_tp1;
            i_optimal_t = t+1;
        }
        // update
        dq1_t = dq1_tp1;
        dmu1_t = dmu1_tp1;
    }

    return i_optimal_t;
}

unsigned int Jeong::Otsubetween(const KImageGray& igImg) const
{
    // get histogram
    KHisto hTmp;
    hTmp.Histogram(igImg);

    // variables
    double dq1_t = (hTmp[0])/_jSize;
    double dmu1_t = 0;
    double dmu1_tp1, dmu2_tp1, dq1_tp1;
    double dVar_tp1, dVarMax=0;
    unsigned int i_optimal_t; // optimal T. 아래 for문에서는 t+1임!!


    // global mean
    double dmu_g=0;
    for(int i=0;i<256;i++){
        dmu_g += i * (hTmp[i])/_jSize;
    }
    // searching for the optimal t(actually t+1)
    for(int t=0;t<254;t++){

        dq1_tp1 = dq1_t + (hTmp[t+1])/_jSize;
        if(dq1_tp1 == 0) // 아래 dmu1_tp1에서 분모가 dq1_tp1 인데, 0이면 무한대 됨.
            dq1_tp1 = 0.00001;

        dmu1_tp1 = ((dq1_t * dmu1_t) + (t+1)*(hTmp[t+1])/_jSize) / dq1_tp1;
        dmu2_tp1 = (dmu_g - dq1_tp1*dmu1_tp1) / (1-dq1_tp1);

        dVar_tp1 = dq1_tp1*(1-dq1_tp1)*(dmu1_tp1-dmu2_tp1)*(dmu1_tp1-dmu2_tp1);
        if(dVarMax<dVar_tp1){
            dVarMax = dVar_tp1;
            i_optimal_t = t+1;
        }
        // update
        dq1_t = dq1_tp1;
        dmu1_t = dmu1_tp1;
    }

    return i_optimal_t;
}

KImageGray Jeong::Dilation(const KImageGray& igImg) const
{
    KImageGray  igTemp = igImg;

    // 무조건 흰색이 foreground
    for(int i=1,ii=this->Row()-2;ii;i++, ii--){
        for(int j=1, jj=this->Col()-2; jj; j++, jj--){
            if(igImg._ppA[i][j]==0) // 0인데, 주면에 있으면 늘려
                if(igImg._ppA[i-1][j-1]|| igImg._ppA[i-1][j]||igImg._ppA[i][j+1]||igImg._ppA[i][j-1]||
                        igImg._ppA[i][j+1]||igImg._ppA[i+1][j-1]||igImg._ppA[i+1][j]||igImg._ppA[i+1][j+1])
                    igTemp._ppA[i][j] = 255;
        }
    }
    return igTemp;
}

KImageGray Jeong::Erosion(const KImageGray& igImg) const
{
    KImageGray  igTemp = igImg;

    // 무조건 흰색이 foreground
    for(int i=1,ii=this->Row()-2;ii;i++, ii--){
        for(int j=1, jj=this->Col()-2; jj; j++, jj--){
            if(igImg._ppA[i][j]) // 255인데, 주변에 있으면 줄여
                if(igImg._ppA[i-1][j-1]==0|| igImg._ppA[i-1][j]==0||igImg._ppA[i][j+1]==0||igImg._ppA[i][j-1]==0||
                        igImg._ppA[i][j+1]==0||igImg._ppA[i+1][j-1]==0||igImg._ppA[i+1][j]==0||igImg._ppA[i+1][j+1]==0)
                    igTemp._ppA[i][j] = 0;
        }
    }

    return igTemp;
}

KImageGray Jeong::Opening(const KImageGray& igImg) const
{
    KImageGray  igTemp = igImg;

    // 1. Erosion
    igTemp = Erosion(igTemp);

    // 2. Dilation
    igTemp = Dilation(igTemp);

    return igTemp;
}

KImageGray Jeong::Closing(const KImageGray& igImg) const
{
    KImageGray  igTemp = igImg;

    // 1. Dilation
    igTemp = Dilation(igTemp);

    // 2. Erosion
    igTemp = Erosion(igTemp);

    return igTemp;
}

KImageWord Jeong::Labeling(const KImageGray &igImg, KImageColor *icpColor) const
{

    int             nRow = igImg.Row();
    int             nCol = igImg.Col();
    unsigned int    uCur, uUp, uLeft;
    unsigned short  wUpColor, wLeftColor, wIdx = 0;

    //init.
    KImageWord awColor(nRow,nCol);
    std::vector<std::pair<unsigned short, unsigned short>> diff;
    if(icpColor)
        icpColor->Create(nRow,nCol);

    // 0. 가장자리 0으로 만들어주기
    for(int i=0; i<nRow; i++){
        if(i==0 || i==nRow-1)
            for(int j=0;j<nCol;j++){
                awColor[i][j] = 0;
                igImg._ppA[i][j] = 0; // ??? 어떻게 이게 되지?
            }
        else{
            awColor[i][0] = 0;
            awColor[i][nCol-1] = 0;
            igImg._ppA[i][0] = 0; // ???
            igImg._ppA[i][nCol-1] = 0;
        }
    }

    // 1. 살펴보기
    for(int i=1, ii=nRow-2; ii; i++, ii--)
        for(int j=1, jj=nCol-2; jj; j++, jj--){
            uCur = igImg._ppA[i][j];
            uUp = igImg._ppA[i-1][j];
            uLeft = igImg._ppA[i][j-1];
            wUpColor = awColor[i-1][j];
            wLeftColor = awColor[i][j-1];

            if(uUp && uLeft && wUpColor!=wLeftColor){
                diff.push_back(std::make_pair(wUpColor,wLeftColor));
            }

            if(uCur){ // 현재가 1인 상태
                if(uUp||uLeft){ // 위, 좌 하나라도 있으면
                    if(uUp==0)
                        awColor[i][j] = wLeftColor;
                    else{
                        awColor[i][j] = wUpColor;
                    }
                }else{
                    awColor[i][j] = wIdx;
                    wIdx++;
                }
            }
        }


    // 2. Label 같은애들 다시 묶기
    for(int i=0; i<diff.size()-1; i++){
        unsigned short A = diff[i].first;
        unsigned short B = diff[i].second;
        if(B > A)
            for(int j=i+1; j<diff.size()-1; j++){
                unsigned short C = diff[j].first;
                unsigned short D = diff[j].second;
                if(C == B)
                    diff[j].first = A;
                if(D == B)
                    diff[j].second = A;
            }
    }

    for(int k=0; k<diff.size(); k++){
        unsigned short A = (diff[k].first < diff[k].second)?diff[k].first : diff[k].second;
        unsigned short B = (diff[k].first > diff[k].second)?diff[k].first : diff[k].second;

        for(int i=1, ii=nRow-1; ii; i++, ii--)
            for(int j=1, jj=nCol-1; jj; j++, jj--)
                if(awColor[i][j] == B)
                    awColor[i][j] = A;
    }


    // 3. 색칠하기
    //결과를 영상에 저장

        for(int i=0, ii=nRow; ii; i++, ii--)
            for(int j=0, jj=nCol; jj; j++, jj--){
                if(igImg._ppA[i][j] == 0){
                    (*icpColor)[i][j].r = 0;
                    (*icpColor)[i][j].g = 0;
                    (*icpColor)[i][j].b = 0;
                    continue;
                }
                switch(awColor[i][j]%9)
                {
                case 0:
                    (*icpColor)[i][j].r = 255;
                    break;
                case 1:
                    (*icpColor)[i][j].g = 255;
                    break;
                case 2:
                    (*icpColor)[i][j].b = 255;
                    break;
                case 3:
                    (*icpColor)[i][j].r = 100;
                    break;
                case 4:
                    (*icpColor)[i][j].g = 100;
                    break;
                case 5:
                    (*icpColor)[i][j].b = 100;
                    break;
                case 6:
                    (*icpColor)[i][j].r = 255;
                    (*icpColor)[i][j].g = 255;
                    break;
                case 7:
                    (*icpColor)[i][j].r = 255;
                    (*icpColor)[i][j].b = 255;
                    break;
                case 8:
                    (*icpColor)[i][j].g = 255;
                    (*icpColor)[i][j].b = 255;
                    break;
                }
            }
        return awColor;
}

void Jeong::HistoEqualize(const KImageColor &icMain, KImageColor& icOutput) const
{
    int         nRow = icMain.Row();
    int         nCol = icMain.Col();
    int         N    = nRow * nCol;
    double      dR=0, dG=0, dB=0, dpR[256]={0,}, dpG[256]={0,}, dpB[256]={0,};

    KImageGray R(nRow,nCol), G(nRow,nCol), B(nRow,nCol);
    for(int i=0, ii=nRow; ii; i++, ii--)
        for(int j=0, jj=nCol; jj; j++, jj--){
            R._ppA[i][j] = icMain._ppA[i][j].r;
            G._ppA[i][j] = icMain._ppA[i][j].g;
            B._ppA[i][j] = icMain._ppA[i][j].b;
        }
    KHisto hTmpR, hTmpG, hTmpB;
    hTmpR.Histogram(R);
    hTmpG.Histogram(G);
    hTmpB.Histogram(B);

    for(int i=0, ii=256; ii; i++, ii--){
        dR += hTmpR[i];
        dG += hTmpG[i];
        dB += hTmpB[i];
        dpR[i] = (double)(dR/N);
        dpG[i] = (double)(dG/N);
        dpB[i] = (double)(dB/N);
    }

    for(int i=0, ii=nRow; ii; i++, ii--)
        for(int j=0, jj=nCol; jj; j++, jj--){
            icOutput._ppA[i][j].r = dpR[R._ppA[i][j]] * 255;
            icOutput._ppA[i][j].g = dpG[G._ppA[i][j]] * 255;
            icOutput._ppA[i][j].b = dpB[B._ppA[i][j]] * 255;
        }
}

void Jeong::HistoMatch(const KImageColor &icOrigin, const KImageColor &icTarget, KImageColor &icOutput) const
{
    int             nRow = icOrigin.Row();
    int             nCol = icOrigin.Col();
    int             N    = nRow * nCol;
    double          dOriR=0, dOriG=0, dOriB=0, dTarR=0, dTarG=0, dTarB=0, dpOriR[256]={0,}, dpOriG[256]={0,}, dpOriB[256]={0,}, dpTarR[256]={0,}, dpTarG[256]={0,}, dpTarB[256]={0,};


    KImageGray      igOriR(nRow,nCol), igOriG(nRow,nCol), igOriB(nRow,nCol), igTarR(nRow,nCol), igTarG(nRow,nCol), igTarB(nRow,nCol);
    KHisto          hOriR, hOriG, hOriB, hTarR, hTarG, hTarB;

    for(int i=0, ii=nRow; ii; i++, ii--)
        for(int j=0, jj=nCol; jj; j++, jj--){
            igOriR._ppA[i][j] = icOrigin._ppA[i][j].r;  igOriG._ppA[i][j] = icOrigin._ppA[i][j].g;  igOriB._ppA[i][j] = icOrigin._ppA[i][j].b;
            igTarR._ppA[i][j] = icTarget._ppA[i][j].r;  igTarG._ppA[i][j] = icTarget._ppA[i][j].g;  igTarB._ppA[i][j] = icTarget._ppA[i][j].b;
        }
    hOriR.Histogram(igOriR);    hOriG.Histogram(igOriG);    hOriB.Histogram(igOriB);
    hTarR.Histogram(igTarR);    hTarG.Histogram(igTarG);    hTarB.Histogram(igTarB);

    for(int i=0, ii=256; ii; i++, ii--){
        dOriR += hOriR[i];      dOriG += hOriG[i];      dOriB += hOriB[i];
        dTarR += hTarR[i];      dTarG += hTarG[i];      dTarB += hTarB[i];
        dpOriR[i] = dOriR/N;    dpOriG[i] = dOriG/N;    dpOriB[i] = dOriB/N;
        dpTarR[i] = dTarR/N;    dpTarG[i] = dTarG/N;    dpTarB[i] = dTarB/N;
    }

    // r을 s로 대응시키기 (dPOriR, G, B를 재활용해서 그냥 담자)
    for(int i=0, ii=256; ii; i++, ii--){
        double          dOffsetMinR = 1000000, dOffsetMinG = 1000000, dOffsetMinB = 1000000;
        unsigned int    uMinIntR=0, uMinIntG=0, uMinIntB=0;
        for(int j=0, jj=256; jj; j++, jj--){
            if(dOffsetMinR>std::abs(dpOriR[i]-dpTarR[j])){
                dOffsetMinR = std::abs(dpOriR[i]-dpTarR[j]);
                uMinIntR = j;
            }
            if(dOffsetMinG>std::abs(dpOriG[i]-dpTarG[j])){
                dOffsetMinG = std::abs(dpOriG[i]-dpTarG[j]);
                uMinIntG = j;
            }
            if(dOffsetMinB>std::abs(dpOriB[i]-dpTarB[j])){
                dOffsetMinB = std::abs(dpOriB[i]-dpTarB[j]);
                uMinIntB = j;
            }
        }
        dpOriR[i] = (double)uMinIntR;
        dpOriG[i] = (double)uMinIntG;
        dpOriB[i] = (double)uMinIntB;
    }


    // 픽셀값 매칭된 값으로 바꿔주기
    for(int i=0, ii=nRow; ii; i++, ii--)
        for(int j=0, jj=nCol; jj; j++, jj--){
            icOutput._ppA[i][j].r = (unsigned int)dpOriR[icOrigin._ppA[i][j].r];
            icOutput._ppA[i][j].g = (unsigned int)dpOriG[icOrigin._ppA[i][j].g];
            icOutput._ppA[i][j].b = (unsigned int)dpOriB[icOrigin._ppA[i][j].b];
        }
}

int Jeong::getRandomNumber(int min, int max) const
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0); // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void Jeong::SaltPepperNoise(const KImageColor icIn, KImageColor &icOut, double dPercent) const
{
    unsigned int nRow = icIn.Row(), nCol = icIn.Col();

    dPercent *= 0.01;
    double threshold = 500 * dPercent;
    int randomNum;

    for(int i=0, ii=nRow; ii; i++, ii--)
        for(int j=0, jj=nCol; jj; j++, jj--){
            randomNum = this->getRandomNumber(0,1000);
            if(randomNum<threshold) {
                icOut._ppA[i][j].r = 0;
                icOut._ppA[i][j].g = 0;
                icOut._ppA[i][j].b = 0;
            }else if(randomNum > 1000 - threshold){
                icOut._ppA[i][j].r = 255;
                icOut._ppA[i][j].g = 255;
                icOut._ppA[i][j].b = 255;
            }else{
                icOut._ppA[i][j].r = icIn._ppA[i][j].r;
                icOut._ppA[i][j].g = icIn._ppA[i][j].g;
                icOut._ppA[i][j].b = icIn._ppA[i][j].b;
            }
        }
}


void Jeong::GaussianNoise(const KImageColor icIn, KImageColor &icOut, double dMean, double dVar) const
{
    unsigned int    nRow = icIn.Row(), nCol = icIn.Col(), nSize = icIn.Size();
    double          dNewR = 0, dNewG = 0, dNewB = 0;

    // Gaussian 하나 만듬
    KGaussian gaussian(dMean, dVar);
    gaussian.OnRandom(nSize);

    // Noise 분배
    for(int i=0, ii=nRow; ii; i++, ii--)
        for(int j=0, jj=nCol; jj; j++, jj--){

            dNewR = icIn._ppA[i][j].r + gaussian.Generate();
            dNewG = icIn._ppA[i][j].g + gaussian.Generate();
            dNewB = icIn._ppA[i][j].b + gaussian.Generate();

            if(dNewR>255) icOut._ppA[i][j].r = 255;
            else if(dNewR<0) icOut._ppA[i][j].r = 0;
            else icOut._ppA[i][j].r = dNewR;

            if(dNewG>255) icOut._ppA[i][j].g = 255;
            else if(dNewG<0) icOut._ppA[i][j].g = 0;
            else icOut._ppA[i][j].g = dNewG;

            if(dNewB>255) icOut._ppA[i][j].b = 255;
            else if(dNewB<0) icOut._ppA[i][j].b = 0;
            else icOut._ppA[i][j].b = dNewB;

        }

}

void Jeong::MeanFilter(const KImageColor icIn, KImageColor &icOut, int kernelsize) const
{
    // 이렇게 const 인자 붙이면 이 함수 내에서는 icIn 바꿔도 바깥의 icIn은 바뀌지 않는다.


    // kernelsize shold be odd number
    #ifdef _DEBUG
        assert(kernelsize%2==1);
    #endif
        unsigned int    nRow = icIn.Row(), nCol = icIn.Col();
        int             nHalf = kernelsize/2;
        int             nSx = nHalf, nSy = nHalf, nEx = nCol-nHalf, nEy = nRow-nHalf;
        int*            kernel = new int[kernelsize];

        for(int i=0; i<kernelsize; i++)
            kernel[i] = 1;

        // convolution
        for(int i=nSy; i<nEy; i++)
            for(int j=nSx; j<nEx; j++){
                double dR=0, dB=0, dG=0;
                for(int r = -nHalf, rr=0; r<=nHalf; r++, rr++){
                    dR += icIn._ppA[i+r][j].r * kernel[rr];
                    dG += icIn._ppA[i+r][j].g * kernel[rr];
                    dB += icIn._ppA[i+r][j].b * kernel[rr];
                }
                icIn._ppA[i][j].r = dR/kernelsize < 255 ? dR/kernelsize : 255;
                icIn._ppA[i][j].g = dG/kernelsize < 255 ? dG/kernelsize : 255;
                icIn._ppA[i][j].b = dB/kernelsize < 255 ? dB/kernelsize : 255;
            }
        for(int i=nSy; i<nEy; i++)
            for(int j=nSx; j<nEx; j++){
                double dR=0, dB=0, dG=0;
                for(int r = -nHalf, rr=0; r<=nHalf; r++, rr++){
                    dR += icIn._ppA[i][j+r].r * kernel[rr];
                    dG += icIn._ppA[i][j+r].g * kernel[rr];
                    dB += icIn._ppA[i][j+r].b * kernel[rr];
                }
                icOut._ppA[i][j].r = dR/kernelsize < 255 ? dR/kernelsize : 255;
                icOut._ppA[i][j].g = dG/kernelsize < 255 ? dG/kernelsize : 255;
                icOut._ppA[i][j].b = dB/kernelsize < 255 ? dB/kernelsize : 255;
            }

        delete[] kernel;
}

void Jeong::GaussianFilter(const KImageColor icIn, KImageColor &icOut, double dSigma) const
{
    // 이렇게 const 인자 붙이면 이 함수 내에서는 icIn 바꿔도 바깥의 icIn은 바뀌지 않는다.

    // kernelsize shold be odd number
    #ifdef _DEBUG
        assert(kernelsize%2==1);
    #endif
        unsigned int    nRow = icIn.Row(), nCol = icIn.Col();
        int             nHalf = (int)(3.0*dSigma + 0.3);
        int             nSx = nHalf, nSy = nHalf, nEx = nCol-nHalf, nEy = nRow-nHalf;
        KMatrix         mMask(nHalf*2 + 1, nHalf*2 + 1);
        double          dScale = 0.0, dSigma2 = 2.0*_SQR(dSigma);
        double          dConst = 1.0/_2PI/_SQR(dSigma);

        for(int r = -nHalf, i=0; r <= nHalf; r++, i++)
            for(int c = -nHalf, j=0; c <= nHalf; c++, j++){
                mMask[i][j] = dConst * exp(-(r*r + c*c)/dSigma2);
                dScale      += mMask[i][j];
            }
        mMask /= dScale; // 이거 operator 정의되어있음. 원소 하나하나 dScale 나눈다.

        // Convolution
        for(int i=nSy; i<nEy; i++)
            for(int j=nSx; j<nEx; j++){
                for(int r=-nHalf, rr=0; r<=nHalf; r++, rr++)
                    for(int c=-nHalf, cc=0; c<=nHalf; c++, cc++){
                        icOut[i][j].r += icIn[i+r][j+c].r * mMask[rr][cc];
                        icOut[i][j].g += icIn[i+r][j+c].g * mMask[rr][cc];
                        icOut[i][j].b += icIn[i+r][j+c].b * mMask[rr][cc];
                    }
            }

}

void Jeong::GaussianFilter2(const KImageColor icIn, KImageColor &icOut, double dSigma) const
{
    // 이렇게 const 인자 붙이면 이 함수 내에서는 icIn 바꿔도 바깥의 icIn은 바뀌지 않는다.

    // kernelsize shold be odd number
    #ifdef _DEBUG
        assert(kernelsize%2==1);
    #endif
        unsigned int    nRow = icIn.Row(), nCol = icIn.Col();
        int             nHalf = (int)(3.0*dSigma + 0.3);
        int             nSx = nHalf, nSy = nHalf, nEx = nCol-nHalf, nEy = nRow-nHalf;
        double*         kernel = new double[nHalf*2+1];
        double          dScale = 0.0, dSigma2 = 2.0*_SQR(dSigma);
        double          dConst = 1.0/_2PI/_SQR(dSigma);

        for(int i=-nHalf, ii=0; i<=nHalf; i++, ii++){
            kernel[ii] = dConst * exp(-(i*i)/dSigma2);
            dScale += kernel[ii];
        }
        for(int i=-nHalf, ii=0; i<=nHalf; i++, ii++){
            kernel[ii] /= dScale;
        }


        // x Convolution
        for(int i=nSy; i<nEy; i++)
            for(int j=nSx; j<nEx; j++){
                double dRsum = 0, dGsum = 0, dBsum = 0;
                for(int r=-nHalf, rr=0; r<=nHalf; r++, rr++){
                    dRsum += icIn[i+r][j].r * kernel[rr];
                    dGsum += icIn[i+r][j].g * kernel[rr];
                    dBsum += icIn[i+r][j].b * kernel[rr];
                }
                icIn[i][j].r = dRsum;
                icIn[i][j].g = dGsum;
                icIn[i][j].b = dBsum;
            }

        // y Convolution
        for(int i=nSy; i<nEy; i++)
            for(int j=nSx; j<nEx; j++){
                for(int r=-nHalf, rr=0; r<=nHalf; r++, rr++){
                    icOut[i][j].r += icIn[i][j+r].r * kernel[rr];
                    icOut[i][j].g += icIn[i][j+r].g * kernel[rr];
                    icOut[i][j].b += icIn[i][j+r].b * kernel[rr];
                }
            }
}

void Jeong::CannyEdgeDetection(const KImageGray& igIn, KImageGray &igOut, int lowT, int highT)
{
    int nHalf = 1;
    int nRow = igIn.Row(), nCol = igIn.Col();
    int nSize = nRow * nCol;
    double dGradX, dGradY;
    double dSigma = 0.3;
    double d2Sigma = 2. * dSigma * dSigma;
    double dConstant = 1/(d2Sigma * _PI * dSigma * dSigma);
    double dScale = 0;
    int dx[4] = {1, 1, 0, -1};
    int dy[4] = {0, 1, 1, 1};
    int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
    int dy8[8] = {0, 1, 1, 1,  0,  -1, -1, -1};
    using namespace std;

    KImageGray igMag(nRow,nCol), igAng(nRow,nCol), igDir(nRow,nCol), igEdge(nRow,nCol), igBuf(nRow,nCol);
    KMatrix mKernelX(nHalf*2+1, nHalf*2+1), mKernelY(nHalf*2+1, nHalf*2+1);


    // FDG를 위한 masking kernel
    for(int i=-nHalf, ii=0; i<=nHalf; i++, ii++){ // i가 v
        for(int j=-nHalf, jj=0; j<=nHalf; j++, jj++){ // j 가 u
            mKernelY[ii][jj] = 1/(dConstant)*(-i)*exp(-i*i/(d2Sigma)) * exp(-j*j / (d2Sigma));
            mKernelX[jj][ii] = mKernelY[ii][jj];
            dScale += (i<0?mKernelY[ii][jj] : 0.0);
        }
    }
    // 이러면 이중포문 돌아서 모든 원소 나눗셈 해준다. operator 확인해봐라.
    mKernelX /= -dScale;
    mKernelY /= -dScale;

    // 1. Gradient Image 만들기 with FDG
    for(int i=nHalf; i<nRow-nHalf;i++)
        for(int j=nHalf; j<nCol-nHalf;j++){
            dGradX = dGradY = 0.0;
            for(int r = -nHalf, rr=0; r<=nHalf; r++, rr++)
                for(int c = -nHalf, cc=0; c<=nHalf; c++, cc++){
                    dGradX += igIn[i+r][j+c] * mKernelX[rr][cc]; // 가로방향
                    dGradY += igIn[i+r][j+c] * mKernelY[rr][cc]; // 세로방향
                }
            // magnitude
            igMag[i][j] = abs(dGradX)+abs(dGradY);

            // lowT 넘나?
            if(igMag[i][j]>lowT){
                igAng[i][j] = atan2(dGradY, dGradX) * (180.0/_PI)+ 0.5;  //(unsigned short)(oMath.Atan(dGradY, dGradX)+0.5);    이 씨발때문에... 존나 고생함..  // angle(DEG)
                igDir[i][j] = (unsigned char)((((int)(atan2(dGradY, dGradX) * (180.0/_PI)/22.5)+1)>>1) & 0x00000003);   // direction (RAD을 DEG로 바꿔서 계산)
//                igDir[i][j] = (unsigned char)((((int)(igAng[i][j]/22.5)+1)>>1) & 0x00000003); // 이거대로 하면 잘 안된다!!!!!
            }else{
                igMag[i][j]=0;
            }
        }

    //3.에서 pop용으로 쓰일 vector선언
    vector<EdgeInfo*> vtmp;

    //2. magnitude가 다 등록되었으로, Edge를 찾아서 등록하자
    for(int i=nHalf; i<nRow-nHalf; i++)
        for(int j=nHalf; j<nCol-nHalf; j++){
            if(igMag[i][j]==0)
                continue;
            else{ // 극대인지 check
                if(igMag[i][j]>igMag[i + dy[igDir[i][j]]][j + dx[igDir[i][j]]]
                        &&
                        igMag[i][j] > igMag[i - dy[igDir[i][j]]][j - dx[igDir[i][j]]]){
                    if(igMag[i][j] > highT){// 극대이면서 highT보다 높으면 Edge지.
                        igOut[i][j] = 255;

                        EdgeInfo* tmp = new EdgeInfo;
                        tmp->nEdgeX = j;
                        tmp->nEdgeY = i;
                        tmp->dEdgeAngD = igAng[i][j]; // RAD
                        tmp->nEdgeDir = igDir[i][j];
                        tmp->dEdgeMag = igMag[i][j];
                        Edge.push_back(tmp);
                        vtmp.push_back(tmp); // 3.에서 pop용으로 만들었음.

                    }else{ // 극대이긴 하지만, highT보다 작으므로, 애매한 녀석으로 등록.
                        igBuf[i][j] = 255;
                    }
                }
            }
        }

    // 3. 애매한 녀석들 처리 -> Edge 주변에 애매한 녀석들이 있으면, 걔도 Edge로 등록
    while(!(vtmp.size()==0)){
        int i=vtmp.back()->nEdgeY;
        int j=vtmp.back()->nEdgeX;
        vtmp.pop_back();
        for(int k=0; k<8; k++){
            if(igBuf[i+dx8[k]][j+dy8[k]]==255){
                igBuf[i+dx8[k]][j+dy8[k]]=0;
                igOut[i+dx8[k]][j+dy8[k]]=255;

                EdgeInfo* tmp = new EdgeInfo;
                tmp->nEdgeX = j+dy8[k];
                tmp->nEdgeY = i+dx8[k];
                tmp->dEdgeAngD = igAng[i+dx8[k]][j+dy8[k]]; // DEG
                tmp->nEdgeDir = igDir[i+dx8[k]][j+dy8[k]];
                tmp->dEdgeMag = igMag[i+dx8[k]][j+dy8[k]];

                Edge.push_back(tmp);
                vtmp.push_back(tmp);
            }
        }
    }

}

void Jeong::HoughCircle(const KImageGray& igIn, KImageGray &igOut, KImageGray &igVoting, int R)
{

    double  dAngleRAD;
    Point2d ptCen1, ptCen2;
    int     nGridCx, nGridCy;
    int     dx[8] = {1,1,0,-1,-1,-1,0,1};
    int     dy[8] = {0,1,1,1,0,-1,-1,-1};
    KImageGray igEdge(this->_jRow, this->_jCol);
    qDebug("%d,%d", igIn.Row(), igIn.Col());
    qDebug("check1");
    CannyEdgeDetection(igIn, igEdge, 30, 130);

    // 양자화 및 create voting table
    _dSx = 3;
    _dSy = 3;
    int nNumGridCy = (igIn.Row() % _dSy==0 ? (int)(igIn.Row()/_dSy) : (int)(igIn.Row()/_dSy)+1); // 양자화 → 몇개의 양자가 있을것인가
    int nNumGridCx = (igIn.Col() % _dSx==0 ? (int)(igIn.Col()/_dSx) : (int)(igIn.Col()/_dSx)+1); // 양자화
    _arVotes.Create(nNumGridCy, nNumGridCx); // row, col 순서
    qDebug("check2");
    //Cx = k*_dSx
    //Cy = k*_dSy

    // 반지름 크기 알고있다고 가정하고 한다.
    // 반지름 모를때는 3차원 배열을 선언해야함. 내 블로그에 소스 나와있음.


    double MaxV = 0;

    // Hough Transform Circle
    while(!(Edge.empty())){ // Edge는 EdgeInfo* 벡터로, Canny Edge한 결과이다.
        //complete circle centers for voting
        dAngleRAD = _RADIAN(Edge.back()->dEdgeAngD); // 라디안 값으로 바꿔줘야함
        ptCen1._nx = Edge.back()->nEdgeX - R*cos(dAngleRAD); // 엣지가 바깥으로 향한다고 가정하고 한다. 이게 아니라면 양쪽 다 해줘야한다.
        ptCen1._ny = Edge.back()->nEdgeY - R*sin(dAngleRAD);
        ptCen2._nx = Edge.back()->nEdgeX + R*cos(dAngleRAD); // 엣지가 안쪽을 향한다고 했을 때
        ptCen2._ny = Edge.back()->nEdgeY + R*sin(dAngleRAD); // 엣지가 안쪽을 향한다고 했을 때
        Edge.pop_back();

        // 엣지가 안쪽을 향한다고 했을 때
        if(ptCen1._nx>=0 && ptCen1._ny>=0 && ptCen1._nx <igIn.Col() && ptCen1._ny <igIn.Row()){
            nGridCx = (int)(ptCen1._nx/_dSx);    // k번째를 구한거다.
            nGridCy = (int)(ptCen1._ny/_dSy);    // k번째를 구한거다.

            // votes to avoid edge noises
            for(int i=-5; i<6; i++)
                for(int j=-5; j<6; j++){
                    if(nGridCx+j<0 || nGridCy+i<0 || nGridCx+j>=nNumGridCx || nGridCy+i>=nNumGridCy) continue;
                    _arVotes[nGridCy+i][nGridCx+j] += 0.7;
                    if(_arVotes[nGridCy+i][nGridCx+j] > MaxV) MaxV = _arVotes[nGridCy+i][nGridCx+j];
                }
            _arVotes[nGridCy][nGridCx] += 0.3; // 결국 얘는 1을 더해준꼴
            if(_arVotes[nGridCy][nGridCx]>MaxV)MaxV = _arVotes[nGridCy][nGridCx];
        }

        // 엣지가 바깥쪽을 향한다고 했을 때
        if(ptCen2._nx>=0 && ptCen2._ny<0 && ptCen2._nx <igIn.Col() && ptCen2._ny <igIn.Row()){
            nGridCx = (int)(ptCen2._nx/_dSx);    // k번째를 구한거다.
            nGridCy = (int)(ptCen2._ny/_dSy);    // k번째를 구한거다.

            // votes to avoid edge noises
            for(int i=-5; i<6; i++)
                for(int j=-5; j<6; j++){
                    if(nGridCx+j<0 || nGridCy+i<0 || nGridCx+j>=nNumGridCx || nGridCy+i>=nNumGridCy) continue;
                    _arVotes[nGridCy+i][nGridCx+j] += 0.7;
                    if(_arVotes[nGridCy+i][nGridCx+j] > MaxV) MaxV = _arVotes[nGridCy+i][nGridCx+j];
                }
            _arVotes[nGridCy][nGridCx] += 0.3; // 결국 얘는 1을 더해준꼴
            if(_arVotes[nGridCy][nGridCx]>MaxV)MaxV = _arVotes[nGridCy][nGridCx];
        }
    }
    qDebug("check3");
    // Voting 이미지 보기 위해서 다음과 같이 색칠함.
    for(int i=0; i<igIn.Row(); i++)
        for(int j=0; j<igIn.Col(); j++){
            igVoting[i][j] = (int)((_arVotes[(int)(i/_dSy)][(int)(j/_dSx)]) / MaxV * 255);
        }
    qDebug("check4");

    // 8방향 Non-maxima suppression (그냥 제일 voting 많이 된 local maxima를 찾는것)
    // 그와중에 Threshold를 넘어야 함.
    for(int i=0; i<nNumGridCy; i++)     // 행
        for(int j=0; j<nNumGridCx; j++){ // 열
            int cnt = 0;
            if(_arVotes[i][j] < MaxV-0.5) // threshold 걸어줬다. threshold보다 작으면 local maxima여도 의미가 없다.
                continue;
            for(int k=0; k<8; k++){
                int ny = i+dy[k]; // 행
                int nx = j+dx[k]; // 열
                if(nx<0 || ny<0 || nx>=nNumGridCx || ny>=nNumGridCy)
                    continue;
                if(_arVotes[i][j]<=_arVotes[ny][nx])
                    break;
                cnt++;
                if(cnt==8){
                    if((int)(i*_dSy)+(int)(_dSy/2)>=igIn.Row() || (int)(j*_dSx)+(int)(_dSx/2)>=igIn.Col()) continue;
                    CircleCenter.push_back(Point2i((int)(i*_dSy)+(int)(_dSy/2), (int)(j*_dSx)+(int)(_dSx/2)));
                }
            }
        }

    // 원 검출한 결과를 표시하기
    while(!CircleCenter.empty()){
        int a = CircleCenter.back()._nx; // 원의 중심
        int b = CircleCenter.back()._ny; // 원의 중심
        qDebug("(x, y) = (%d, %d)", a, b);
        CircleCenter.pop_back();

        for(int y=b-R; y<=b+R; y++)
            for(int x=a-R; x<=a+R; x++){
                if(x<0 || y<0|| x>=igOut.Col() || y>=igOut.Row())
                    continue;
                if(_SQR(x-a) + _SQR(y-b) <= R*R+50 && _SQR(x-a) + _SQR(y-b) >= R*R-50)
                    igOut[y][x] = 255;
            }
    }

}

void Jeong::GeneralizedHoughTransform(const KImageGray igIn, KImageGray &igOut)
{
    // Scale factor는 0.85로 고정한다.. scale까지 고려하면 너무 시간 오래걸린다.
    double dScaleFactor = 0.85; // 아래 코드에 s로 다시 선언해서 쓸거다.. 이걸로 고정하자.. 이거 scale도 하려면 4차원 배열 만들어야하고, 시간 너무걸린다..

    // 1. 모델 데이터 가공과정
    KImageGray igEdge(igIn.Row(), igIn.Col());
    CannyEdgeDetection(igIn, igEdge, 30, 150);
    qDebug("ROW = %d, Col = %d", igIn.Row(), igIn.Col());

    int x, y, sumX=0, sumY=0, Cx, Cy, cnt=0;
    int nDir;
    double dTmp, dAng, dDist;
    double dGradX, dGradY;

    qDebug("\n HT Start ");
    vector<Point2i> ModelPoint;
    ifstream fin;
    fin.open("plug.txt");

    // File 읽고 Model Edge Point 저장
    while(! fin.eof()){
        cnt++;
        fin >> x >> y;
        ModelPoint.push_back(Point2i(y,x)); // 행 열 순서로 넣었다.
        sumX+=x; sumY+=y;
    }

    // 중심점은 평균점으로 때린다.
    // Model의 Center(Cx,Cy)
    Cx = (int)(sumX/cnt);
    Cy = (int)(sumY/cnt);
    qDebug("(Cx,Cy) : %d, %d",Cx,Cy);


    if(fin.is_open())
        fin.close();

    // Model Shape Table Create

    for(int i=0; i< ModelPoint.size(); i++){
        //Edge Direction
        if(i == 0){ //Point 0 번째는 마지막과의 Edge 방향
            dGradX = ModelPoint[i+1]._nx - ModelPoint[ModelPoint.size()-1]._nx;
            dGradY = ModelPoint[i+1]._ny - ModelPoint[ModelPoint.size()-1]._ny;
        }
        else if(i == ModelPoint.size()-1){ //  마지막 point에서의 Edge 방향
            dGradX = ModelPoint[0]._nx - ModelPoint[i-1]._nx;
            dGradY = ModelPoint[0]._ny - ModelPoint[i-1]._ny;
        }
        else{ // 나머지 중간에 있는 점
            dGradX = ModelPoint[i+1]._nx - ModelPoint[i-1]._nx;
            dGradY = ModelPoint[i+1]._ny - ModelPoint[i-1]._ny;
        }
        // dir이랑 ang이랑은 다른거다!! hough circle에서는 원의 중심은 진짜 딱 중심이니까 dir과 ang이 일치했는데,
        // 여기서는 ang은 중심과 엣지 점간의 ang이고, dir은 엣지 점에서 바깥으로 나가는 방향을 말한다.
        nDir = (unsigned char)((((((int)(atan2(dGradY, dGradX) * (180.0/_PI)/22.5)+1)>>1) & 0x00000003))); // 4방향중 어딘가. 그러나 i-1, i+1점을 잇는 선분과는 수직해야함.  ERRRR
        dDist = sqrt(_SQR(ModelPoint[i]._nx - Cx) + _SQR(ModelPoint[i]._ny - Cy)); // sqrt( (Xi-Xc)^2 + (Yi-Yc)^2 )
        dAng = atan2((Cy-ModelPoint[i]._ny),(Cx-ModelPoint[i]._nx)); // angle RAD

        ModelInfo * tmp = new ModelInfo;
        tmp->nModelX = ModelPoint[i]._nx;
        tmp->nModelY = ModelPoint[i]._ny;
        tmp->dModelAngR = dAng; // RAD
        tmp->dModelDist = dDist;
        Model[nDir].push_back(tmp);
    }



    // 2. 양자화 및 Voting table 생성
    _dSx = 3;
    _dSy = 3;
    int nNumGridCy = (igIn.Row() % _dSy==0 ? (int)(igIn.Row()/_dSy) : (int)(igIn.Row()/_dSy)+1); // 양자화 → 몇개의 양자가 있을것인가
    int nNumGridCx = (igIn.Col() % _dSx==0 ? (int)(igIn.Col()/_dSx) : (int)(igIn.Col()/_dSx)+1); // 양자화

    // 3차원 배열 동적할당 궁금하면 내 블로그 찾아봐
    double ***_arVotes3;
    _arVotes3 = new double **[igIn.Row()];
    for(int i = 0; i<igIn.Row(); i++){
        _arVotes3[i] = new double*[igIn.Col()];
        for(int j = 0; j<igIn.Col(); j++){
            _arVotes3[i][j] = new double[360];
            for(int k=0; k<360; k++){
                _arVotes3[i][j][k] = 0;
            }
        }
    }

    qDebug("양자화 및 Voting table 생성완료");

    //
    // 3. Voting
    //

    double MaxV = 0;
    int nMaxGridX, nMaxGridY, nMaxThetaD;
    double s = 0.85;

    while(!(Edge.empty())){
        int Xi = Edge.back()->nEdgeX;
        int Yi = Edge.back()->nEdgeY;
        double dAngTempD = Edge.back()->dEdgeAngD; // DEG phi
        Edge.pop_back();

        for(int theta=0; theta<360; theta++){
            double dPhiD = dAngTempD - theta; // DEG phi prime
            //if(phi<0)phi+=360; // ERRRR
            int ndir = ((((int)(dPhiD/22.5)+1)>>1) & 0x00000003); // ERRRRR
            for(int i=0; i<Model[ndir].size(); i++){
                double dR = Model[ndir][i]->dModelDist;

                // 1. 안쪽일 경우
                int Xc1 = Xi - dR*s*cos(Model[ndir][i]->dModelAngR+_RADIAN(theta)); // 안쪽일경우
                int Yc1 = Yi - dR*s*sin(Model[ndir][i]->dModelAngR+_RADIAN(theta));
                if(Xc1>=0&&Yc1>=0&&Xc1<igIn.Col()&&Yc1<igIn.Row()){
                    int nGridCx1 = Xc1/_dSx;
                    int nGridCy1 = Yc1/_dSy;

                    for(int i=-1; i<2; i++)
                        for(int j=-1;j<2;j++){
                            if(nGridCy1+i<0||nGridCx1+j<0||nGridCy1+i>=nNumGridCy||nGridCx1+j>=nNumGridCx) continue;
                            _arVotes3[nGridCy1+i][nGridCx1+j][theta] += 0.7;
                            if(_arVotes3[nGridCy1+i][nGridCx1+j][theta]>MaxV){
                                MaxV = _arVotes3[nGridCy1+i][nGridCx1+j][theta];
                                nMaxGridX = nGridCx1+j;
                                nMaxGridY = nGridCy1+i;
                                nMaxThetaD = theta;
                            }
                        }
                    _arVotes3[nGridCy1][nGridCx1][theta] += 0.3;
                    if(_arVotes3[nGridCy1][nGridCx1][theta]>MaxV){
                        MaxV = _arVotes3[nGridCy1][nGridCx1][theta];
                        nMaxGridX = nGridCx1;
                        nMaxGridY = nGridCy1;
                        nMaxThetaD = theta;
                    }
                }

//                // 2. 바깥쪽일 경우
//                int Xc2 = Xi + dR*s*cos(Model[ndir][i]->dModelAngR+_RADIAN(theta)); // 바깥쪽일경우
//                int Yc2 = Yi + dR*s*sin(Model[ndir][i]->dModelAngR+_RADIAN(theta));
//              if(Xc2>=0 && Yc2>=0 && Xc2<igIn.Col() && Yc2<igIn.Row()){
//                  int nGridCx2 = Xc2/_dSx;
//                  int nGridCy2 = Yc2/_dSy;
//                  for(int i=-1; i<2; i++)
//                      for(int j=-1;j<2;j++){
//                            if(nGridCy2+i<0||nGridCx2+j<0||nGridCy2+i>=nNumGridCy||nGridCx2+j>=nNumGridCx) continue;
//                            _arVotes3[nGridCy2+i][nGridCx2+j][theta] += 0.7;
//                            if(_arVotes3[nGridCy2+i][nGridCx2+j][theta]>MaxV){
//                                MaxV = _arVotes3[nGridCy2+i][nGridCx2+j][theta];
//                                nMaxGridX = nGridCx2+j;
//                                nMaxGridY = nGridCy2+i;
//                                nMaxThetaD = theta;
//                            }
//                        }
//                    _arVotes3[nGridCy2][nGridCx2][theta] += 0.3;
//                    if(_arVotes3[nGridCy2][nGridCx2][theta]>MaxV){
//                        MaxV = _arVotes3[nGridCy2][nGridCx2][theta];
//                        nMaxGridX = nGridCx2;
//                        nMaxGridY = nGridCy2;
//                        nMaxThetaD = theta;
//                    }
//                }
            }
        }
    }
    qDebug("Voting");
    qDebug("MaxV : %f, MaxGridX : %d, MaxGridY : %d, nMaxThetaD : %d" , MaxV, nMaxGridX, nMaxGridY, nMaxThetaD );


    int Xc = nMaxGridX*_dSx + _dSx/2;
    int Yc = nMaxGridY*_dSy + _dSy/2;
    qDebug("Xc,Yc = %d, %d", Xc, Yc);

    for(int k=0; k<4; k++){
        for(int i=0; i<Model[k].size(); i++){
            double dR = Model[k][i]->dModelDist;
            double phi = Model[k][i]->dModelAngR+_RADIAN(nMaxThetaD); // RAD


            int Xi = Yc + dR*s*cos(phi);
            int Yi = Xc + dR*s*sin(phi);
            if(Xi<0||Yi<0||Xi>=igOut.Col()||Yi>=igOut.Row()) continue;
            igOut[Xi][Yi] = 255;
//            for(int i=-1; i<2; i++)
//                for(int j=-1; j<2; j++){
//                    if(Xi + j<0|| Yi+i<0 || Xi+j>=igOut.Row() || Yi+i>=igOut.Col())continue;
//                    igOut[Yi+i][Xi+j] = 255;
//                }

        }
    }
}





