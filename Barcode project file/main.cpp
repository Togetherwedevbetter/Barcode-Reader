//this program is made by Aman Meena

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <QDir>
#include <fstream>
using namespace std;
void read_barcode();
void scan_barcode();
void read_qr();
void scan_qr();
void line();
int main()
{
    string text= "       BARCODE SCANNER";
    string name="Build By:-";
    string name1="          Aman Meena";
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t  ****************************************"<<endl
    <<"\t\t\t\t\t  ** __________________________________ **"<<endl
    <<"\t\t\t\t\t  **| ________________________________ |**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<" " <<" ||**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<text<< " ||**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<" " <<" ||**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<" "<<" ||**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<name<<" ||**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<name1<< " ||**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<" "<<" ||**"<<endl
    <<"\t\t\t\t\t  **|| " << setfill(' ') << left << setw(30) <<" "<< " ||**"<<endl

    <<"\t\t\t\t\t  **||________________________________||**"<<endl

    <<"\t\t\t\t\t  **|__________________________________|**"<<endl

    <<"\t\t\t\t\t  **                                    **"<<endl
    <<"\t\t\t\t\t  ****************************************"<<endl;
    getch();
    system("cls");
    int ch;
    do
    {
    cout<<"Select what you want to do\n"<<"1. Scan Barcode\n"<<"2. Read Barcode\n"<<"3. Scan QR\n"<<"4. Read QR\n"<<"0. Exit\n";
    cin>>ch;
    switch (ch)
    {
    case 1: {
            scan_barcode();
            }
        break;
    case 2: {
            read_barcode();
            }
        break;
    case 3: {
             scan_qr();
            }
        break;
    case 4: {
            read_qr();
            }
        break;
    case 0:    cout<<"exiting";
                break;
    default:
            cout<<"wrong choice try again\n";
        break;
    }
}while(ch!=0);

    getch();
    return 0;
}

void read_barcode()
{
    ifstream file;
        ifstream pr;
        ifstream amount;
        int i;
        int j=0;
        string barcode[50];
        string type[50];
        string price[50];
        int id[50];
        for(i=0;i<50;i++)
        {
            id[i]=i+1;
        }

        pr.open("D:/opencv/ZBar/bin/product.txt",ios::in);
        file.open("D:/opencv/ZBar/bin/zbar.txt",ios::in);
        amount.open("D:/opencv/ZBar/bin/price.txt",ios::in);
        if(!file)
        {
            if(!pr)
            {
                if(!amount)
                {
                    cout<<"error price";
                }
                cout<<"error product";
            }
        cout<<"error";
    }
        else
        cout<<setw(49)<<"Items Purchased\n"<<endl;
    cout<<"\t ";line();
    cout<<right<<setw(15)<<"S.no"<<setw(25)<<"Barcode"<<setw(20)<<"Item"
         <<setw(20)<<"Price"<<setw(12)<<endl;
    line();
        while(file>>barcode[j])
        {
            pr>>type[j];
            amount>>price[j];

            cout<<right<<setw(15)<<id[j]<<"  |"<<setw(30)<<barcode[j]<<"  |"<<setw(12)<<type[j]
            <<"  |"<<setw(18)<<price[j]<<"  |"<<endl;

            j++;
        }
        cout<<"\t ";line();
        amount.close();
        pr.close();
        file.close();
        getch();
}
void scan_barcode()
{
    cout<<"\nopening camera to scan barcodes and QR code\n";
    cout<<"press enter to allow";
    getch();
    QDir::setCurrent("D:\\opencv\\ZBar\\bin");
    system("zbarcam.bat");

    cout << "Barcodes Readed Successfully!" << endl;

}

void scan_qr()
{
    cout<<"\nopening camera to scan barcodes and QR code\n";
    cout<<"press enter to allow";
    getch();
    QDir::setCurrent("D:\\opencv\\ZBar\\bin");
    system("zbarcamqr.bat");

    cout << "QR Readed Successfully!" << endl;

}
void line()
{
    for(int i=1;i<41;i++)
    cout<<"--";
    cout<<"\n";
}

void read_qr()
{
    ifstream qr;
    int i=0;
    string qrr[50];
    qr.open("D:/opencv/ZBar/bin/qr.txt",ios::in);
    if(!qr)
    {
        cout<<"error";
    }
    else
        while(qr>>qrr[i]){
            cout<<qrr[i]<<"\n";
            i++;
        }
    qr.close();
    getch();
}

