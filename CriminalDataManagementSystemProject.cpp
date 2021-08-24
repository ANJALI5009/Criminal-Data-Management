#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#define MAX 1000
#include<map>

using namespace std;

 char password[10]="1234";
char user_name[20],user_password[10];

class Login{
public:

Login(){
    system("cls");
    cout<<"\n\t\t\t\t\tCRIMINAL DATA MANAGEMENT SYSTEM\n"<<endl;
cout<<setfill('*')<<setw(60)<<"LOGIN"<<setfill('*')<<setw(70)<<"\n\n\t Enter ID:";
cin>>user_name;
cout<<"\tEnter Password:";
cin>>user_password;
}

};
class Criminal
{
 private:
   int p_wno,p_firno;
   char p_criminalname[MAX],p_witness[50][MAX],p_crimedetails[MAX],p_allocatedofficer[MAX],p_criminalstatus[MAX],p_crimedate[MAX];

     int g_wno,g_firno,g_cno;
   char g_name[MAX],g_criminalname[50][MAX],g_witness[50][MAX],g_crimedetails[MAX],g_allocatedofficer[MAX],g_criminalstatus[MAX],g_crimedate[MAX];


 public:

    void p_read()
    {
     cout<<"Enter FIR No:";
     cin>>p_firno;
       cout<<"Enter Criminal Name:";
       cin.ignore();
      gets(p_criminalname);

      cout<<"Enter Crime Date:";
    gets(p_crimedate);
     cout<<"Enter Allocated officer Name:";
     gets(p_allocatedofficer);
     cout<<"Enter Crime Status:";
     gets(p_criminalstatus);
      cout<<"Enter Criminal Details:";
     gets(p_crimedetails);
     cout<<"Enter Witness No::";
     cin>>p_wno;
     if(p_wno>=1)
        {
           for(int i=0;i<p_wno;i++)
             {
                cout<<"Enter Witness:";
                cin.ignore();
             gets(p_witness[i]);

             }
     }
              else if(p_wno==0)
        cout<<"No witness\n";

     }


     void p_show()
     {
       cout<<"\n\nFIR No:"<<p_firno;
        cout<<"\nCriminal Name:"<<p_criminalname;
         cout<<"\nCrime Date:"<<p_crimedate;
          cout<<"\nAllocated officer Name:"<<p_allocatedofficer;
           cout<<"\nCrime Status:"<<p_criminalstatus;
            cout<<"\nWitnesses are:";
         if(p_wno>=1)
         {
           for(int i=0;i<p_wno;i++)
             {
                cout<<"\n\tWitness is:"<<p_witness[i];

             }
         }
         else{
            cout<<"\tNo Witness";
         }
       cout<<"\nCriminal Details:"<<p_crimedetails;
     }

     int getno()
     {
         return p_firno;
     }



       void g_read()
    {
     cout<<"Enter FIR No:";
     cin>>g_firno;
       cout<<"Enter Gang Name:";
       cin.ignore();
      gets(g_name);
       cout<<"Enter Number of Criminal::";
     cin>>g_cno;
            for(int i=0;i<g_cno;i++)
             {
                cout<<"Enter Criminal Name:";
                cin.ignore();
                gets(g_criminalname[i]);
             }

      cout<<"Enter Crime Date:";
    gets(g_crimedate);
     cout<<"Enter Allocated officer Name:";
     gets(g_allocatedofficer);
     cout<<"Enter Crime Status:";
     gets(g_criminalstatus);
      cout<<"Enter Criminal Details:";
     gets(g_crimedetails);
     cout<<"Enter Witness No::";
     cin>>g_wno;
     if(g_wno>=1)
        {
           for(int i=0;i<g_wno;i++)
             {
                cout<<"Enter Witness:";
                cin.ignore();
             gets(g_witness[i]);

             }
     }
              else if(g_wno==0)
        cout<<"No witness\n";

     }


     void g_show()
     {
       cout<<"\n\n\nFIR No:"<<g_firno;
        cout<<"\nGang Name:"<<g_name;
         cout<<"\nCriminals Names are:";
           for(int i=0;i<g_cno;i++)
             {
                cout<<"\n\t"<<g_criminalname[i];

             }

         cout<<"\nCrime Date:"<<g_crimedate;
          cout<<"\nAllocated officer Name:"<<g_allocatedofficer;
           cout<<"\nCrime Status:"<<g_criminalstatus;
            cout<<"\nWitnesses are:";
         if(g_wno>=1)
         {
           for(int i=0;i<g_wno;i++)
             {
                cout<<"\n\t"<<g_witness[i];

             }
         }
         else{
            cout<<"\tNo Witness";
         }
       cout<<"\nCriminal Details:"<<g_crimedetails;
     }

     int g_getno()
     {
         return g_firno;
     }

};




Criminal p,g;

//PERSON RECORD
 void p_add()
   {
       fstream FILE;
       FILE.open("p_criminal.txt",ios::out|ios::app|ios::binary);
      cout<<"\nEnter Criminal Details:\n\n";
     p.p_read();
     FILE.write((char*)&p,sizeof(p));
    FILE.close();
   }
   void p_modify()
   {
        fstream FILE;
        int no;
       FILE.open("p_criminal.txt",ios::in|ios::out|ios::binary);
             long pos;
            cout<<"\nEnter a FIR No. you want to Edit:";
            cin>>no;

             while(!FILE.eof())
           {
               pos=FILE.tellg();
               FILE.read((char*)&p,sizeof(p));
               if(p.getno()==no)
               {
                    cout<<"\n Enter New Criminal Record:\n";

                   p.p_read();
                   FILE.seekg(pos);
                    FILE.write((char*)&p,sizeof(p));
                    cout<<"\nRECORD UPDATED\n";
                   break;
               }
               else
               {
                   cin.ignore();
                 cout<<"Record Not Found";
                 break;
               }

           }
           FILE.close();
   }
   void p_delete()
   {
        fstream FILE,fp2;
        int no;
        cout<<"\n\nPlease Enter FIR number You Want To Delete:";
    cin>>no;
    FILE.open("p_criminal.txt",ios::in|ios::out);
    fp2.open("Temp.txt",ios::out);
    FILE.seekg(0,ios::beg);
    while(FILE.read((char*)&p,sizeof(p)))
    {
        if(p.getno()!=no)
        {
            fp2.write((char*)&p,sizeof(p));

        }
    }
    fp2.close();
    FILE.close();
    remove("p_criminal.txt");
    rename("Temp.txt","p_criminal.txt");

    if(p.getno()==no)
    cout<<"\n\n\tRecord Deleted ";
    else
        cout<<"\n\n\tRecord Not Found";
   }
   void p_view()
   {
        fstream FILE;
        int no;
        FILE.open("p_criminal.txt",ios::in|ios::binary);
           FILE.seekg(0,ios::beg);
           while(FILE.read((char*)&p,sizeof(p)))
           {
               p.p_show();
           }
          FILE.close();
   }



   //GANG RECORD
 void g_add()
   {
       fstream file;
       file.open("g_criminal.txt",ios::out|ios::app|ios::binary);
      cout<<"\nEnter Criminal Details:\n\n";
     g.g_read();
     file.write((char*)&g,sizeof(g));
    file.close();
   }
   void g_modify()
   {
        fstream file;
        int no;
      file.open("g_criminal.txt",ios::in|ios::out|ios::binary);
             long pos;
            cout<<"\nEnter a FIR Number you want to Modify:";
            cin>>no;

             while(!file.eof())
           {
               pos=file.tellg();
               file.read((char*)&g,sizeof(g));
               if(g.g_getno()==no)
               {
                    cout<<"\n Enter New Criminal Record:\n";

                   g.g_read();
                   file.seekg(pos);
                   file.write((char*)&g,sizeof(g));
                    cout<<"\nRECORD UPDATED\n";
                   break;
               }
               else
               {
                   cin.ignore();
                 cout<<"Record Not Found";
                 break;
               }

           }
          file.close();
   }
   void g_delete()
   {
        fstream file,fp2;
        int no;
        cout<<"\n\nPlease Enter FIR number You Want To Delete:";
    cin>>no;
    file.open("g_criminal.txt",ios::in|ios::out);
    fp2.open("g_Temp.txt",ios::out);
    file.seekg(0,ios::beg);
    while(file.read((char*)&g,sizeof(g)))
    {
        if(g.g_getno()!=no)
        {
            fp2.write((char*)&g,sizeof(g));

        }
    }
    fp2.close();
    file.close();
    remove("g_criminal.txt");
    rename("g_Temp.txt","g_criminal.txt");
     if(g.g_getno()==no)
    cout<<"\n\tRecord Deleted ";
    else
        cout<<"\nRecord Not Found";
   }
   void g_view()
   {
        fstream FILE;
        int no;
        FILE.open("g_criminal.txt",ios::in|ios::binary);
           FILE.seekg(0,ios::beg);
           while(FILE.read((char*)&p,sizeof(p)))
           {
               p.g_show();
           }
          FILE.close();
   }








int main(){
    system("COLOR 3F");
int choice;

    int crime_code,search_c;
       char crime_name[30];
        map<int,string>crime_l;
        map<int,string>::iterator it;

Login obj;
if(strcmp(user_password,password)==0){
do{
system("cls");

cout<<"\n\t\tCRIMINAL DATA MANAGEMENT SYSTEM\n\n";
cout<<setfill('*')<<setw(120);
cout<<"\n\n1.CRIME RECORD\n2.CRIMINAL RECORD\n3.VIEW DETALIS\n4.EXIT\n\n"<<setfill('*')<<setw(82)<<"\n\nEnter Your Choice:";
cin>>choice;

switch(choice)
{
case 1:int inner_choice;
       do{
             cout<<setfill('*')<<setw(162);
            cout<<"\n\t1.Add Crime Details\n\t2.Modify Crime Details\n\t3.Delete Crime Details\n\t4.View list of crime\n\t5.Exit\n"<<setfill('*')<<setw(82)<<"\n\nEnter Your Choice:";
        cin>>inner_choice;
       switch(inner_choice)
       {
     case 1:cout<<"\nEnter Crime Section Number:";
     cin>>crime_code;
      cout<<"Enter Crime Name:";
       cin>>crime_name;
      crime_l.insert(pair<int,string>(crime_code,crime_name));
        cout<<"\nSUCCESSFULLY RECORDED\n";
        break;

     case 2:
         cout<<"Enter Section Number you want to Update:";
        cin>>search_c;

    it=crime_l.find(search_c);
    if(search_c==(*it).first)
        {
              cout<<"Enter Crime Section Number";
     cin>>crime_code;
      cout<<"Enter Crime Name:";
       cin>>crime_name;
               crime_l.erase(search_c);
      crime_l.insert(pair<int,string>(crime_code,crime_name)) ;
     cout<<"\n\tSUCCESSFULLY UPDATED\n";
    }
    else
        cout<<"\nCrime Record Not found"<<endl;
        break;

     case 3:
        cout<<"Enter Section Number you want to Delete:";
     cin>>crime_code;
    if(crime_l.count(crime_code)!=0)
    {
         crime_l.erase(crime_code);
         cout<<"\nSUCCESSFULLY DELETED\n";
    }

    else
        cout<<"\nCrime Record Not Found\n";
        break;

     case 4:
            cout<<"\nList of Crime:-\n\n";
            cout<<"SECTION NUMBER\tCRIME NAME\n";
            for(it=crime_l.begin();it!=crime_l.end();it++)
             cout<<(*it).first<<" \t\t "<<(*it).second<<endl;

        break;

     case 5:
        break;
     default:cout<<"WRONG CHOICE";
        break;

       }
      }while(inner_choice!=5);

    break;




case 2:int inner_choice1;
       do{
            cout<<setfill('*')<<setw(117);
            cout<<"\n\t1.SINGLE CRIMINAL FILE\n\t2.GANG CRIMINAL FILE\n\t3.EXIT\n"<<setfill('*')<<setw(82)<<"\n\nEnter Your Choice:";
        cin>>inner_choice1;
       switch(inner_choice1)
       {
     case 1:

int inner_choice12;
       do{
            cout<<"\n\n"<<setfill('*')<<setw(180);
            cout<<"\n\n\t\t1.Add Criminal Details\n\t\t2.Modify Criminal Details\n\t\t3.Delete Criminal Details\n\t\t4.View Criminal Details\n\t\t5.Exit\n"<<setfill('*')<<setw(82)<<"\n\nEnter Your Choice:";
        cin>>inner_choice12;
       switch(inner_choice12)
       {
     case 1: p_add();
        break;


     case 2:p_modify();
            break;


     case 3:p_delete();
             break;


     case 4:p_view();
        break;

     case 5:
        break;

     default:cout<<"WRONG CHOICE";
        break;

       }
      }while(inner_choice12!=5);
       break;






     case 2:int inner_choice13;
       do{
            cout<<"\n\n"<<setfill('*')<<setw(180);
            cout<<"\n\n\t\t1.Add Gang Criminal Details\n\t\t2.Modify Gang Criminal Details\n\t\t3.Delete Gang Criminal Details\n\t\t4.View Gang Criminal Details\n\t\t5.Exit\n"<<setfill('*')<<setw(82)<<"\n\nEnter Your Choice:";
        cin>>inner_choice13;
       switch(inner_choice13)
       {
     case 1: g_add();
        break;


     case 2:g_modify();
            break;


     case 3:g_delete();
             break;


     case 4:g_view();
        break;

     case 5:
        break;

     default:cout<<"WRONG CHOICE";
        break;

       }
      }while(inner_choice13!=5);

        break;

   case 3:
             break;

     default:cout<<"WRONG CHOICE";
        break;
       }
      }while(inner_choice1!=3);
      break;


     case 3: int inner_choice3;
       do{
            cout<<"\n\n"<<setfill('*')<<setw(134);
            cout<<"\n\t1.CRIME RECORDS\n\t2.SINGLE CRIMINAL FILE\n\t3.GANG CRIMINAL FILE\n\t4.EXIT\n"<<setfill('*')<<setw(82)<<"\n\nEnter Your Choice:";
        cin>>inner_choice3;
       switch(inner_choice3)
       {
     case 1: cout<<"\nCrime Record:-\n";
             cout<<"SECTION NUMBER\tCRIME NAME\n";
            for(it=crime_l.begin();it!=crime_l.end();it++)
             cout<<(*it).first<<" \t\t "<<(*it).second<<endl;
           break;


     case 2:p_view();
        break;




     case 3:g_view();
        break;

        case 4:
             break;

     default:cout<<"WRONG CHOICE";
        break;

       }
      }while(inner_choice3!=4);
      break;




case 4:
    break;

default:cout<<"WRONG CHOICE";
break;

}

}while(choice!=4);
}

else {
      char rn,r;
      r='y';
cout<<"\n\t\tWRONG PASSWORD\n"<<endl;
cout<<"Enter 'y' if You Want To Retry:";
cin>>rn;
   if(r==rn)
     main();
   }
return 0;
}
