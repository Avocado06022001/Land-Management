#include<iostream>
using namespace std;
#include<vector>
#include<fstream>
class thongtinnguoisohuu{
private:
    string hovaten;
    int namsinh;
    string CMND;
    string diachi;
public:
    thongtinnguoisohuu(){}
    thongtinnguoisohuu(string hovaten, int namsinh, string CMND, string diachi){
        this->hovaten=hovaten;
        this->namsinh=namsinh;
        this->CMND=CMND;
        this->diachi=diachi;
    }
    string outputthongtinnguoisohuu(){
        string output;
        output="Ho va ten: "+hovaten+'\n'+"Nam sinh: "+to_string(namsinh)+'\n'+"So CMND: "+CMND+'\n'+"Dia chi thuong tru: "+diachi+'\n';
        return output;
    }
};

class ngaythang{
private:
    int ngay;
    int thang;
    int nam;
public:
    ngaythang(){}
    ngaythang(int ngay, int thang, int nam){
        this->ngay=ngay;
        this->thang=thang;
        this->nam=nam;
    }

    string outputngaythang(){
        string output;
        output=to_string(ngay)+"/"+to_string(thang)+"/"+to_string(nam);
        return output;
    }

    int getNam(){return this->nam;}
};

class datVietNam{
private:
    string sogiaychungnhan;
    thongtinnguoisohuu tt;
    int sothuadat;
    int sotobando;
    string diachithuadat;
    double dientich;
    ngaythang ngaycap;
    double dongiathue;
public:
    datVietNam(){}
    datVietNam(string sogiaychungnhan, string hovaten, int namsinh, string CMND, string diachi, int sothuadat, int sotobando, string diachithuadat, double dientich, int ngay, int thang, int nam, double dongiathue)
    : tt(hovaten,namsinh,CMND,diachi), ngaycap(ngay,thang,nam){
        this->sogiaychungnhan=sogiaychungnhan;
        this->sothuadat=sothuadat;
        this->sotobando=sotobando;
        this->diachithuadat=diachithuadat;
        this->dientich=dientich;
        this->dongiathue=dongiathue;
    }
    string outputthongtindat(){
        string outputdat;
        outputdat="So giay chung nhan: "+sogiaychungnhan+'\n';
        outputdat+=tt.outputthongtinnguoisohuu();
        outputdat+=("So thua dat: "+to_string(sothuadat)+'\n'+"So to ban do: "+to_string(sotobando)+'\n'+"Dia chi thua dat: "+diachithuadat+'\n'+"Dien tich mieng dat: "+to_string(dientich)+'\n'+"Ngay cap: "+ngaycap.outputngaythang()+'\n'+"Don gia thue: "+to_string(dongiathue)+'\n');
        return outputdat;
    }
    double getTienthue(){return this->dongiathue * this->dientich;}
    int getNam(){return ngaycap.getNam();}
};

class Thuadatnongnghiep :public datVietNam{
private:
    int thoihansudung;
public:
    Thuadatnongnghiep(string sogiaychungnhan, string hovaten, int namsinh, string CMND, string diachi, int sothuadat, int sotobando, string diachithuadat, double dientich, int ngay, int thang, int nam, double dongiathue, int thoihansudung):datVietNam::datVietNam(sogiaychungnhan,hovaten,namsinh,CMND,diachi,sothuadat,sotobando, diachithuadat, dientich, ngay, thang, nam, dongiathue){
        this->thoihansudung=thoihansudung;
    }
    string outputthongtindat(){
        string output2;
        output2=datVietNam::outputthongtindat();
        output2+=("Thoi han su dung dat: "+to_string(thoihansudung)+'\n');
        return output2;
    }
    int getThoihan(){return this->thoihansudung;}
};

class Thuadatphinongnghiep: public datVietNam{
public:
    Thuadatphinongnghiep(string sogiaychungnhan, string hovaten, int namsinh, string CMND, string diachi, int sothuadat, int sotobando, string diachithuadat, double dientich, int ngay, int thang, int nam, double dongiathue):datVietNam::datVietNam(sogiaychungnhan,hovaten,namsinh,CMND,diachi,sothuadat,sotobando, diachithuadat, dientich, ngay, thang, nam, dongiathue){}
};

class quanly{
private:
    vector<datVietNam*>list;
    vector<Thuadatnongnghiep*>list1;
public:
    void addEntity(datVietNam* v){
        list.push_back(v);
    }
    void addEntity1(Thuadatnongnghiep* v1){
        list1.push_back(v1);
    }
    void outputthongtindat(){
        for (int i=0; i<list.size(); i++){
            cout<<"Thong tin ma "<<i+1;
            cout<<endl;
            cout<<list[i]->outputthongtindat();
        }
    }

    void tienthuephaidong(){
        int num;
        cout<<"Chon mieng dat can tim thue: ";
        cin>>num;
        cout<<"Tien thue mieng dat do la: ";
        cout<<list[num]->getTienthue();
    }

    string tienthuecaonhat(){
        double max=list[0]->getTienthue();
        int index;
        for (int i=0; i<list.size(); i++){
            if (list[i]->getTienthue()>max){index=i;}
        }
        return list[index]->outputthongtindat();
    }

    string thuadathethan(){
        string tongthongtin;
        int namhientai=2021;
        for (int i=0; i<list1.size(); i++){
            if (list1[i]->getThoihan()<2021){
                tongthongtin+=(list1[i]->outputthongtindat()+'\n');
            }
        }
        return tongthongtin;
    }
};

int main(){
    quanly q;
    datVietNam* a1=new Thuadatnongnghiep("A123","tainguyen",2001,"225927246","Lehongphong",96,15, "auco", 350, 6, 2, 2019, 500, 2022);
    datVietNam* a2=new Thuadatnongnghiep("A246","minhphuong",2001,"292982346","binhchanh",87,23, "Haiphong", 250, 9, 8, 2017, 450, 2019);
    datVietNam* a3=new Thuadatphinongnghiep("B765","chinguyen",2001,"218765244","nguyenthiminhkhai",65,34, "Hanoi", 150, 10, 7, 2011, 600);
    Thuadatnongnghiep* a4=new Thuadatnongnghiep("A123","tainguyen",2001,"225927246","Lehongphong",96,15, "auco", 350, 6, 2, 2019, 500, 2022);
    Thuadatnongnghiep* a5=new Thuadatnongnghiep("A246","minhphuong",2001,"292982346","binhchanh",87,23, "Haiphong", 250, 9, 8, 2017, 450, 2019);
    q.addEntity(a1);
    q.addEntity(a2);
    q.addEntity(a3);
    q.addEntity1(a4);
    q.addEntity1(a5);
    q.outputthongtindat();
    cout<<endl;
    q.tienthuephaidong();
    cout<<endl;
    cout<<q.tienthuecaonhat();
    cout<<endl;
    cout<<q.thuadathethan();
    
}
