#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
using namespace std;

struct Person
{
     char name[20];
     int accno;
     float balance;
        
};
int main()
{
     struct Person p;
     FILE *fp;
     char c;
     int ch;
     while(1)
     {
          cout<<"\n\n 1. Add Records in the File";
          cout<<"\n 2. Display Content of File";
          cout<<"\n 3. Display Name of Person whose Balance is Greater than 10,000";
          cout<<"\n 4. Exit";
          cout<<"\n\n Enter Your Choice : ";
          cin>>ch;
          switch(ch)
          {
               case 1:
                    fp=fopen("person.txt","ab");
                    while (1)
                    {
                         cout<<"\n Enter Person Name   :  ";
                         cin>>p.name;
                         fflush(stdin);
                         cout<<"\n Enter Account No.   :  ";
                         cin>>p.accno;
                         fflush(stdin);
                     
                         cout<<"\n Enter Balance       :  ";
                         cin>>p.balance;
                         fflush(stdin);
                      
                         fwrite(&p,sizeof(p),1,fp);
                         fflush(stdin);
                         cout<<"\n\n Do You Want to Continue?(Y/N) : ";
                         cin>>c;
                         if(c=='n' || c=='N')
                              break;
                    }
                    fclose(fp);
                    break;
                    
               case 2:
                    fp=fopen("person.txt","rb");
                    while (fread(&p,sizeof(p),1,fp))
                    {
                         while(1)
                         {
                              cout<<"\n Account No : "<<p.accno;
                              cout<<"\n Name       : "<<p.name;
                              cout<<"\n Balance    : "<<p.balance<<endl;
                              break;
                         }
                    }
                    fclose(fp);
                    break;

               case 3:
                    fp=fopen("person.txt","rb");
                    while(fread(&p,sizeof(p),1,fp))
                    {
                         if(p.balance>10000)
                         {

                              while(1)
                              {
                                   cout<<"\n Account No : "<<p.accno;
                                   cout<<"\n Name       : "<<p.name;
                                   cout<<"\n Balance    : "<<p.balance<<endl;
                                   break;
                              }
                         }
                    }
                    fclose(fp);
                    break;
               case 4:
                    exit(0);
               default:
                    cout<<"\n Invalid Choice";
          }
     }
     return 0;
}