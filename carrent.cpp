#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class carmodel 
{
    public :
    string cmodel,colour;int ch,seat,hr,carno;char ans;
    void get()
    {
       
        cout<<"\nEnter Car Model : ";cin>>cmodel;
        cout<<"\nEnter Car Colour : ";cin>>colour;
        cout<<"\nEnter Car Number : ";cin>>carno;
    } 
    void display()
    {
        cout<<"\nList of Available Cars for Rent : ";
        cout<<"\n---------------------------------------------\n";
        cout<<"\nCar Model : "<<cmodel;
        cout<<"\nCar Colour : "<<colour;
        cout<<"\nCar Number : "<<carno;
        cout<<"\n---------------------------------------------\n";

    }

};
carmodel c;
void write()
{
    ofstream fout;
    fout.open("Carrent.dat",ios::app|ios::binary);
    c.get();
    fout.write((char*)&c,sizeof(c));
    fout.close();
    cout<<"\nData Added Successfully...";
}
void read()
{
    ifstream fin;
    fin.open("Carrent.dat",ios::in|ios::binary);
    while(fin.read((char*)&c,sizeof(c)))
    {
        c.display();
    }
    fin.close();
}
void uplist()
{
    ifstream fin;
    fin.open("carrents.dat",ios::in|ios::binary);
    while(fin.read((char*)&c,sizeof(c)))
    {
        c.display();
    }
    fin.close();
}
void update()
{
    int ac,fl=0;string newmodel;
    fstream f;
    f.open("Carrent.dat",ios::out|ios::in|ios::binary);
    cout<<"\nEnter the Car Number whose Model You want to update : ";
    cin>>ac;
    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.carno==ac)
        {
            fl=1;
            cout<<"\nRecord Found";
            cout<<"\nEnter the Updated Model : ";cin>>newmodel;
            int t=f.tellp();
            c.cmodel=newmodel;
            f.seekp(t-sizeof(c));
            f.write((char*)&c,sizeof(c));
            cout<<"\nData Updated Successfully.....";
            break;
        }
    }
    if(fl==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    f.close();
}
void updatecolor()
{
    int ac,fl=0;string newcolor;
    fstream f;
    f.open("Carrent.dat",ios::out|ios::in|ios::binary);
    cout<<"\nEnter the Car Number whose Colour You want to update : ";
    cin>>ac;
    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.carno==ac)
        {
            fl=1;
            cout<<"\nRecord Found";
            cout<<"\nEnter the Updated Colur : ";cin>>newcolor;
            int t=f.tellp();
            c.colour=newcolor;
            f.seekp(t-sizeof(c));
            f.write((char*)&c,sizeof(c));
            cout<<"\nData Updated Successfully.....";
            break;
        }
    }
    if(fl==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    f.close();
}
void delete_specific()
{
    int ac,fl=0;
    fstream f;
    f.open("Carrent.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("new.dat",ios::app|ios::binary);
    cout<<"\nEnter Car Number : ";
    cin>>ac;
    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.carno!=ac)
        {

            fout.write((char*)&c,sizeof(c));
        }
        else{
            fl=1;
        }
    }
    f.close();
    fout.close();
    remove("Carrent.dat");
    rename("new.dat","carrent.dat");
    cout<<"\nSuccessful";

}
void select_car()
{
     fstream f;
    int acc,flag=0,hr;float price,km;string cm;
    f.open("carrent.dat",ios::in|ios::out|ios::binary);
    cout<<"\nEnter the Car Number of your Selected Car : ";
    cin>>acc;
    cout<<"\nEnter the Car Model : ";cin>>cm;
    while(f.read((char*)&c,sizeof(c)))
    {
        if((c.carno==acc)&&(c.cmodel == cm))
        {
            flag=1;
            cout<<"\nCar Selected Successfully...";
           if(cm=="Swift" || cm=="Grand-i10" || cm=="Wagonar" || cm=="swift" || cm=="grand-i10"||cm=="wagonar")
           {
              cout<<"\nOur Charges Are 13 rs. per Kilometer";
              price = 13;
           }
           else if(cm=="Verna"||cm=="Xcent"||cm=="Innova"||cm=="verna"||cm=="xcent"||cm=="innova")
           {
               cout<<"\nOur Charges Are 15 rs. per Kilometer";
               price = 15;
           }
           else 
           {
              cout<<"\nOur Charges Are 17 rs. per Kilometer";
              price = 17;
           }
           cout<<"\nIf you are Booking a Car For 24 Hours or More, Than extra Charges of 200 Rupees will be Applicable per Day";
           cout<<"\nEnter the Time Period For which You want the Car On rent (in Hours) : ";cin>>hr;
           cout<<"\nEnter Average Distance to your Destination in km : ";cin>>km;
            price = price * km;
            if(hr==24)
             price = price + 200;
             else if((hr>24) && (hr%24==0))
             {
                price = price + (hr/24)*200;
             }
             else 
             {
                price = price +200;
             }
            cout<<"\n\n-------------------------Recipt---------------------------";
            cout<<"\nTime Period (in Hours) : "<<hr;
            cout<<"\nAverage Distance : "<<km<<" km";
            cout<<"\nTotal Charge : "<<price<<" Rupees";
            cout<<"\nAdvance Payment : "<<(0.5*price)<<" Rupees";
            cout<<"\n---------------------------------------------------------------\n";
            cout<<"\nThank you for Choosing Zoom Car.. \nHave a Safe and Happy Journey!!";
            cout<<"\n---------------------------------------------------------------\n";
           int ac,fl=0;char av;
    fstream f;
    f.open("carrent.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("New.dat",ios::app|ios::binary);
    while(f.read((char*)&c,sizeof(c)))
    {
        if(c.carno!=acc)
        {

            fout.write((char*)&c,sizeof(c));
        }
        else{
            fl=1;
        }
    }
    f.close();
    fout.close();
    remove("carrent.dat");
    rename("New.dat","carrents.dat");
    cout<<"\nAvailability List Updated Successfully...";
    cout<<"\nWant to Check Avalability List Again ? (y/n) : ";cin>>av;
    if(av=='y')
    uplist();
    else 
    cout<<"\nThank You";

      }  } 
}
int main()
{
   string name,cn,email,pass;char dl;int nu;int carsle;
        cout<<"\n\t|| Welcome to Zoom Car || ";
        cout<<"\nWelcome to Sign-in/Sign-up Page...";
        cout<<"\nEnter\n1.For Sign-up Page (if you are New User)\n2.For Sign-in Page (if you are Existing Customer)";
        cout<<"\nEnter your Choice :  ";cin>>nu;
        if(nu==1)
        {
        cout<<"\nEnter your Name : ";cin>>name;
        cout<<"\nEnter your Contact Number : ";cin>>cn;
        cout<<"\nEnter your Email ID : ";cin>>email;
        cout<<"\nDo you have Driving Licence ? (y/n) : ";cin>>dl;
        if(dl=='n')
        goto nd;
        else 
        {
            cout<<"\n---------------------------------------------";
            cout<<"\nName : "<<name;
            cout<<"\nContact Number : "<<cn;
            cout<<"\nEmail ID : "<<email;
            cout<<"\n---------------------------------------------";
        }
        }
        else 
        {
            cout<<"\nPlease Enter Password : ";cin>>pass;
            if(pass == "Zoomcar_rent@123")
            cout<<"\nWelcome Back !";
            else 
            goto exit;
        }
    int ch;
    remove("Carrent.dat");
    while(1)
    {
        cout<<"\nEnter\n1.Enter the Available Cars\n2.Display All\n3.Update Car Model\n4.Update Car Colour\n5.Delete data of Specific car\n6.Rent Car\n0.EXIT";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:write();break;
            case 2:read();break;
            case 3:update();break;
            case 4:updatecolor();break;
            case 5:delete_specific();break;
            case 6:select_car();break;  
            case 0:exit(0);
            default:cout<<"\nInvalid Choice";
        }
    }
    exit:
    cout<<"\nInvalid Password!!";
    nd:
    cout<<"\nSORRY!!,We cannot provide our cars on Rent!!!!";
}
