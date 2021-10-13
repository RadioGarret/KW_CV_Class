#include <QFileDialog>
#include <QPainter>

#include "mainframe.h"
#include "ui_mainframe.h"
#include "imageform.h"
#include "jeong.h"
#include <QDebug>

MainFrame::MainFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainFrame)
{
    ui->setupUi(this);

    _plpImageForm       = new KPtrList<ImageForm*>(10,false,false);
    _q_pFormFocused     = 0;

    //객체 맴버의 초기화

    //get a current directory
    char st[100];
    GetCurrentDirectoryA(100,st);

    //리스트 출력창을 안보이게
    ui->listWidget->setVisible(false);
    this->adjustSize();

    //UI 활성화 갱신
    UpdateUI();
}

MainFrame::~MainFrame()
{ 
    delete ui;         
    delete _plpImageForm;


}

void MainFrame::CloseImageForm(ImageForm *pForm)
{
    //ImageForm 포인터 삭제
    _plpImageForm->Remove(pForm);

    //활성화 ImageForm 초기화
    _q_pFormFocused     = 0;

    //관련 객체 삭제

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::UpdateUI()
{
    if(ui->tabWidget->currentIndex() == 0)
    {
        ui->buttonSepiaTone->setEnabled( _q_pFormFocused &&  _q_pFormFocused->ID() == "OPEN" );    

    }
    else if(ui->tabWidget->currentIndex() == 1)
    {

    }
    else if(ui->tabWidget->currentIndex() == 2)
    {

    }    
}

void MainFrame::OnMousePos(const int &nX, const int &nY, ImageForm* q_pForm)
{

    UpdateUI();
}

void MainFrame::closeEvent(QCloseEvent* event)
{
    //생성된 ImageForm을 닫는다.
    for(int i=_plpImageForm->Count()-1; i>=0; i--)
        _plpImageForm->Item(i)->close();

    //리스트에서 삭제한다.
    _plpImageForm->RemoveAll();
}


void MainFrame::on_buttonOpen_clicked()
{
    //이미지 파일 선택
    QFileDialog::Options    q_Options   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

    if(q_stFile.length() == 0)
        return;

    //이미지 출력을 위한 ImageForm 생성    
    ImageForm*              q_pForm   = new ImageForm(q_stFile, "OPEN", this);

    _plpImageForm->Add(q_pForm);
    q_pForm->show();

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonDeleteContents_clicked()
{
    //생성된 ImageForm을 닫는다.
    for(int i=_plpImageForm->Count()-1; i>=0; i--)
        _plpImageForm->Item(i)->close();

    //리스트에서 삭제한다.
    _plpImageForm->RemoveAll();
}

void MainFrame::on_buttonSepiaTone_clicked()
{
    //포커스 된 ImageForm으로부터 영상을 가져옴
    KImageColor   icMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icMain = _q_pFormFocused->ImageColor();
    else
        return;

    //hue, saturation 값 가져오기
    double dHue = ui->spinHue->text().toDouble();
    double dSat = ui->spinSaturation->text().toDouble(); // 위와 같은 식으로

    KImageGray gHue(icMain.Row(), icMain.Col()); //<unsigned char>
    KImageGray gSat(icMain.Row(), icMain.Col());
    KImageGray gVal(icMain.Row(), icMain.Col());

    KArray<KHSV> hsv(icMain.Row(), icMain.Col());

    icMain.RGBtoHSV(hsv);
    for(int i=0;i<icMain.Row();i++){
        for(int j=0;j<icMain.Col();j++){
            // hue, sat, val 표현
            gHue._ppA[i][j] = (unsigned char)((hsv._ppA[i][j].h + 60.0) * 255.0 / 360.0);
            gSat._ppA[i][j] = (unsigned char)(hsv._ppA[i][j].s * 255.0);
            gVal._ppA[i][j] = (unsigned char)(hsv._ppA[i][j].v);

            // making sepiaTone
            hsv._ppA[i][j].h = dHue;
            hsv._ppA[i][j].s = dSat;
        }
    }

    icMain = icMain.FromHSV(hsv);

    //출력을 위한 ImageForm 생성
    ImageForm*  q_pForm = new ImageForm(icMain, "Sepia Tone", this);
    ImageForm*  q_pHue  = new ImageForm(gHue, "Hue", this);
    ImageForm*  q_pSat  = new ImageForm(gSat, "Sat", this);
    ImageForm*  q_pVal  = new ImageForm(gVal, "Val", this);
    _plpImageForm->Add(q_pForm);
    _plpImageForm->Add(q_pHue);
    _plpImageForm->Add(q_pSat);
    _plpImageForm->Add(q_pVal);
    q_pForm->show();
    q_pHue->show();
    q_pSat->show();
    q_pVal->show();

    //UI 활성화 갱신
    UpdateUI();
}


void MainFrame::on_buttonShowList_clicked()
{
    static int nWidthOld = ui->tabWidget->width();

    if(ui->listWidget->isVisible())
    {
        nWidthOld = ui->listWidget->width();
        ui->listWidget->hide();
        this->adjustSize();
    }
    else
    {        
        ui->listWidget->show();
        QRect q_rcWin = this->geometry();

        this->setGeometry(q_rcWin.left(), q_rcWin.top(), q_rcWin.width()+nWidthOld, q_rcWin.height());
    }
}

void MainFrame::on_buttonContrast_clicked()
{
    //포커스 된 ImageForm으로부터 영상을 가져옴
    KImageGray   igMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        igMain = _q_pFormFocused->ImageGray();
    else
        return;



    KImageGray  result;

    // From, To 값 갖고오기
    int FromMin = ui->spinFromMin->text().toInt();
    int FromMax = ui->spinFromMax->text().toInt();
    int ToMin   = ui->spinToMin->text().toInt();
    int ToMax   = ui->spinToMax->text().toInt();

    Jeong j = Jeong(igMain);
    result = j.LumiContrast(FromMin, FromMax, ToMin, ToMax);

    //출력을 위한 ImageForm 생성
    ImageForm*  q_pForm = new ImageForm(result, "Luminance Contrast", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonOtsuBetween_clicked()
{
    //포커스 된 ImageForm으로부터 영상을 가져옴
    KImageGray   igMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        igMain = _q_pFormFocused->ImageGray();
    else
        return;

    Jeong mk(igMain);

    // Optimal T
    unsigned int threshold;
    threshold = mk.OtsuBetween();
    printf("optimal T : %d\n", threshold);

    // Thresholding
    for(int i=0;i<mk.Row(); i++){
        for(int j=0;j<mk.Col();j++){
            if(igMain._ppA[i][j] < threshold)
                igMain._ppA[i][j] = 0;
            else
                igMain._ppA[i][j] = 255;
        }
    }

    //출력을 위한 ImageForm 생성
    ImageForm*  q_pForm = new ImageForm(igMain, "Threshold", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonLabeling_clicked()
{
    //포커스 된 ImageForm으로부터 영상을 가져옴
    KImageGray   igMain;
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageGray().Address() &&  _q_pFormFocused->ID() == "OPEN")
        igMain = _q_pFormFocused->ImageGray();
    else{
        printf("No image\n");
        return;
    }

    Jeong mk(igMain);

    // Optimal T
    unsigned int threshold;
    threshold = mk.OtsuBetween();

    // 1. Thresholding
    for(int i=0;i<mk.Row(); i++){
        for(int j=0;j<mk.Col();j++){
            if(igMain._ppA[i][j] < threshold)
                igMain._ppA[i][j] = 0;
            else
                igMain._ppA[i][j] = 255;
        }
    }

    KImageGray  igOpen = igMain;
    KImageGray  igOpenClose = igMain;

    // 2. Opening
    igOpen = mk.Opening(igMain);

    // 3. Closing
    igOpenClose = mk.Closing(igOpen);

    // 4. Labeling
    KImageColor* ptr = new KImageColor(mk.Row(),mk.Col());
    KImageWord temp;
    temp = mk.Labeling(igOpenClose, ptr);

    //출력을 위한 ImageForm 생성
    ImageForm*  q_pForm = new ImageForm(igMain, "Threshold", this);
    ImageForm*  q_pForm1 = new ImageForm(igOpen, "Opening", this);
    ImageForm*  q_pForm2 = new ImageForm(igOpenClose, "Opening->Closing", this);
    ImageForm*  q_pForm3 = new ImageForm(*ptr, "Labeling", this);
    _plpImageForm->Add(q_pForm);
    _plpImageForm->Add(q_pForm1);
    _plpImageForm->Add(q_pForm2);
    _plpImageForm->Add(q_pForm3);
    q_pForm->show();
    q_pForm1->show();
    q_pForm2->show();
    q_pForm3->show();

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonHistoEqualization_clicked()
{
    //포커스 된 ImageForm으로부터 영상을 가져옴
    KImageColor   icMain;

    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN")
        icMain = _q_pFormFocused->ImageColor(); // 사진을 icMain 변수에 담음
    else
        return;


    Jeong mk(icMain);

    KImageColor icOutput(icMain.Row(), icMain.Col());

    mk.HistoEqualize(icMain, icOutput);
    ImageForm*  q_pForm = new ImageForm(icOutput, "Histogram Equalization", this);
    _plpImageForm->Add(q_pForm);
    q_pForm->show();
    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonHistoMatching_clicked()
{
    ImageForm*  q_pForm;
    KImageColor   icMain;
    ImageForm*  q_pOutput;


    // 1. 폴더모양 열어서 바꾸고 싶은파일 선택
    if(_q_pFormFocused != 0 && _q_pFormFocused->ImageColor().Address() &&  _q_pFormFocused->ID() == "OPEN"){
        icMain = _q_pFormFocused->ImageColor();
        Jeong mk(icMain);

        // reference가 될 이미지 파일 선택 (on_buttonOpen_clicked 마냥)
        do{
            QFileDialog::Options    q_Options   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
            QString                 q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

            if(q_stFile.length() == 0)
                return;

            q_pForm = new ImageForm(q_stFile,"Target", this);
            _plpImageForm->Add(q_pForm);
            q_pForm->show();
            if(!q_pForm->ImageColor().Address())
                delete q_pForm;
        }while(!q_pForm->ImageColor().Address()); // 없으면 만족하므로, 다시해


        // Histogram Matching 수행
        KImageColor icTarget = q_pForm->ImageColor();
        KImageColor icOutput(icMain.Row(), icMain.Col());

        mk.HistoMatch(icMain, icTarget, icOutput);
        q_pOutput = new ImageForm(icOutput, "Matched Image", this);


    }else{
        qDebug()<<"No Image";
        return;
    }


    // 이미지 출력
    _plpImageForm->Add(q_pOutput);
    q_pOutput->show();

    //UI 활성화 갱신
    UpdateUI();
}
