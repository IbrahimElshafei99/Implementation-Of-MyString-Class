#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *String;
public:
    //default constructor
    MyString(){}
    //parameterize constructor
    MyString(char *a)
    {
        String = new char[strlen(a)+1];
        String=a;
        //cout<<"parameterize"<<endl;
    }
    //copy constructor
    MyString(const MyString &object)
    {
        String=new char[strlen(object.String)+1];
        strcpy(String,object.String);
        cout<<String<<endl;
    }
    //destructor
    ~MyString(){delete String;}
    void Remove()
    {
        int S=(strlen(String))-1;
        char *R=new char[S];
        for(int i=0; i<S;i++)
        {
          R[i]=String[i];
        }
        cout<<R<<endl;
    }
    void Add(char a)
    {
        int S=strlen(String);
        char *A=new char[S+2];
        for(int i=0; i<S;i++)
        {
          A[i]=String[i];
        }
        A[S]=a;
        A[S+1]='\0';
        cout<<A<<endl;
    }
    int Length()
    {
       return strlen(String);
    }
    void Copy(int p,int l)
    {
        char *C=new char[strlen(String)];
        int np=p-1;
        int L=np+l;
        for(int i=np;i<L;i++)
        {
            C[i]=String[i];
        }
        cout<<C<<endl;
    }
    void Swap(MyString &ob)
    {
        MyString T;
        T=ob;
        ob=*this;
        *this=T;
    }
    MyString operator+(const MyString &s2)
    {
        MyString O;
        int Size=strlen(String) + strlen(s2.String);
        char *sum=new char[Size+1];
        strcpy(sum,String);
        strcat(sum,s2.String);
        //O=sum;
        for(int i=0; i<Size;i++)
        {
          O.String[i]=sum[i];
        }
        return O;
    }
    void Compare(MyString &s2)
    {
        cout<<strcmp(String,s2.String)<<endl;
    }
    //first index is 1
    void Substring(int Start,int End)
    {
        int start=Start-1;
        char *sub=new char[strlen(String)];
        for(int i=0;i<End;i++)
        {
            sub[i]=String[i+start];
        }
        cout<<sub<<endl;
    }
    void Trim()
    {
        char *Tr=new char[strlen(String)];
        int s=strlen(String);
        for(int i=0;i<s;i++)
        {
            if(String[i]==' '){}
            else
                Tr[i]=String[i];
        }
        cout<<Tr<<endl;
    }
    void ToLowerCase()
    {
        char *LC=new char[strlen(String)];
        int s=strlen(String);
        for(int i=0;i<s;i++)
        {
            if(String[i]>='A' && String[i]<='Z')
                LC[i]=String[i] + 32;
            else
                LC[i]=String[i];
        }
        cout<<LC<<endl;
    }
    void ToUpperCase()
    {
        char *UC=new char[strlen(String)];
        int s=strlen(String);
        for(int i=0;i<s;i++)
        {
            if(String[i]>='a' && String[i]<='z')
                UC[i]=String[i] - 32;
            else
                UC[i]=String[i];
        }
        cout<<UC<<endl;
    }
    //Indexes start from 1
    int IndexOf(char Index)
    {
        int s=strlen(String);
        for(int i=0;i<s;i++)
        {
            if(String[i]==Index)
                return i+1;
        }
    }
    //Indexes start from 1
    int LastIndexOf(char Lindex)
    {
        int s=strlen(String);
        for(int i=s;i>0;i--)
        {
            if(String[i]==Lindex)
                return i+1;
        }
    }
    void Replace(char oldChar, char newChar)
    {
        int s=strlen(String);
        for(int i=0;i<s;i++)
        {
            if(String[i]==oldChar)
            {
              String[i]=newChar;
            }
        }
        cout<<String<<endl;
    }

    void show()
    {
        cout<<String<<endl;
    }

};

int main()
{
    char UserString[1000];
    char UserString2[1000];
    cout<<"Write your string"<<endl;
    cin>>UserString;
    int x;
    MyString object(UserString), objectSum;
    cout<<"Enter the number of function"<<endl;
    cout<<"1-> Remove"<<endl<<"2-> Add"<<endl<<"3-> Length"<<endl<<"4-> Copy"<<endl<<"5-> Swap"<<endl;
    cout<<"6-> Compare"<<endl<<"7-> Concatenate two strings"<<endl<<"8-> Substring"<<endl<<"9-> Trim"<<endl<<"10-> ToLowerCase"<<endl;
    cout<<"11-> ToUpperCase"<<endl<<"12-> FirstIndexOf"<<endl<<"13-> LastIndexOf"<<endl<<"14-> Replace"<<endl;
    cin>>x;
    while(x>0&&x<15)
    {
    if(x==1) //Remove
        object.Remove();
    else if(x==2){ //Add
        char ch;
        cout<<"Write a character"<<endl;
        cin>>ch;
        object.Add(ch);
    }
    else if(x==3){//Length
        int len;
        len=object.Length();
        cout<<len<<endl;
    }
    else if(x==4){ //Copy
        int pos,cLen;
        cout<<"Enter the position then the length"<<endl;
        cin>>pos>>cLen;
        object.Copy(pos,cLen);
    }
    else if(x==5){ //Swap
        cout<<"Write the second string"<<endl;
        cin>>UserString2;
        MyString object2(UserString2);
        object.Swap(object2);
        cout<<"S1: ";
        object.show();
        cout<<endl;
        cout<<"S2: ";
        object2.show();
        cout<<endl;
    }
    else if(x==6){ //Compare
        cout<<"Write the second string"<<endl;
        cin>>UserString2;
        MyString object3(UserString2);
        object.Compare(object3);
    }
    else {}/*
    case 7:/*

        break;
    case 8:

        break;
    case 9:

        break;
    case 10:

        break;
    case 11:

        break;
    case 12:

        break;
    case 13:

        break;
    case 14:

        break;*/
    }
    //MyString f1(SS),f2(ch),f;
    //f1.Swap(f2);
    //f1.Remove();
    //f=f1+f2;//.operator+(f2);
    //f1.Copy(1,4);
    //f1.Compare(f2);
    //f1.Substring(1,7);
    //f1.Trim();
    //f1.ToUpperCase();
    /*int x;
    x=f1.LastIndexOf('m');
    cout<<x;*/
    //f1.Replace('m','a');
    return 0;
}
