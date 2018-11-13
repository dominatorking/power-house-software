
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class book
{public:
int m,j;
char date[8],add[100],mob[10];
    char name2[34];
    int id;
    char name[34];
void get()
    {cout<<"enter id";
    cin>>id;
        cout<<"enter name";
        cin>>name;
        cout<<"\n";
        cout<<"enter address";
        cin>>add;
        cout<<endl;
        cout<<"enter mobile number";
        cin>>mob;}
    void put()
    {
        cout<<"id is:"<<id<<endl<<"name is"<<name<<endl<<"address is"<<add<<endl<<"mobile number is"<<mob<<endl;
}
    int insert()
    {
        return id;
    }
    int record()
    {cout<<"enter date (format is dd|mm|yy)";
                     cin>>date;
        cout<<"enter amount";
        cin>>j;
        cout<<endl;

    }
    }s1,s2,s3,s4;
int main()
{int k,m,b,p;
   cout<<"\t"<< "\t"<< "\t"<< "\t"<< "\t"<< "Welcome"<<endl<<endl<<"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#"<<endl<<"\t"<< "\t"<< "\t"<< "\t" "Vidhuth vibhag(INDIA)"<<endl<<endl<<"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#"<<endl;
   cout<<"::-  want to add record(type 1)"<<endl;
   cout<<"::-  want to delete record(type 2)"<<endl;
   cout<<"::-  want to pay bill(type 3)"<<endl;
   cout<<"::-  want to see all records(type 4)"<<endl;
   cout<<"::-  want to see all payments(type 5)"<<endl;
   cout<<endl<<"@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#";
   cin>>k;

    if(k==1)                                      //printing class objects value in file
    {char ch='y';
    ofstream fout;
        fout.open("records.txt",ios::out|ios::app|ios::binary);
        while(ch=='y')
        {
            s2.get();
            s2.put();
            fout.write((char*)&s2,sizeof(s2));
cout<<"want to add more";
cin>>ch;
        }
    }
    if(k==4)                                                    //reading objects value in file

{

    ifstream fin;
        fin.open("records.txt",ios::in|ios::binary);
         fin.read((char*)&s1,sizeof(s1));
        while(!fin.eof())
        {

            s1.put();
             fin.read((char*)&s1,sizeof(s1));

        }

}
 if(k==2)                                                    //deleting   objects value in file

{
    int j;
cout<<"enter book id which is to be removed";
cin>>j;
    ifstream fin3;
    ofstream fout3;
        fin3.open("records.txt",ios::in|ios::binary);
        fout3.open("records2.txt",ios::out|ios::binary|ios::app);
fin3.read((char*)&s3,sizeof(s3));
        while(!fin3.eof())
        {


        if(s3.id==j)
        {

        }
            else
            {
                 fout3.write((char*)&s3,sizeof(s3));
            }
            fin3.read((char*)&s3,sizeof(s3));

        }
        fout3.close();
        fin3.close();

        remove("records.txt");
        rename("records2.txt","records.txt");}
        if(k==3)
        {cout<<"enter record id";
        cin>>m;

            ifstream fin4;
                        ofstream fout4;
                        fout4.open("records2.txt",ios::out|ios::binary|ios::app);
            fin4.open("records.txt",ios::in);
            fin4.read((char*)&s2,sizeof(s2));


while(!fin4.eof())
    {
if(s2.insert()==m)
   {

    s2.put();

s2.record();

    fout4.write((char*)&s2,sizeof(s2));
   }
   fin4.read((char*)&s2,sizeof(s2));
        }

        }
        if(k==5)
        {
            cout<<"enter record id";
        cin>>p;

            ifstream fin5;

                        fin5.open("records2.txt",ios::in|ios::binary);
                        fin5.read((char*)&s2,sizeof(s2));

                        while(!fin5.eof())
                        {
if(s2.id==p)
{cout<<s2.date;
cout<<endl;
    cout<<s2.j;
   cout<<endl;
}
                        fin5.read((char*)&s2,sizeof(s2));

                        }
        }
}
