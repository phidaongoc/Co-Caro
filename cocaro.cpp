#include<stdio.h>
#include<iostream>
using namespace std;
# define max 500
char A[max][max];
void khoidong(char A[max][max], int &m)
{
    cout << " Moi ban nhap kich thuoc ban choi:";
    cin>>m;
    while (m <= 5)
    {
        cout << "Moi ban nhap lai kich thuoc ban choi:";
        cin >> m;
    }
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<m; j++)
        {
            A[0][j] = j;
            A[i][0] = i;
            if (i != 0 && j != 0)
                A[i][j] = '.';
        }
    }
}
void xuat(char A[max][max], int &m)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
            {   if(i==0||j==0)
                    printf("%4d",A[i][j]);
                else
                    printf("%4c",A[i][j]);                
            }
            cout<<endl;
    }
} 
void nhap1(char A[max][max], int &m, int &i1, int &j1, char S1[10])
{
    cout<<" Moi nguoi choi"<<" "<<S1<< " nhap:"<<endl;
    cout<<" Nhap hang:";
    cin>>i1;
    cout<<" Nhap cot:";
    cin>>j1;
    if(i1<=0||j1<=0||A[i1][j1]=='O'||A[i1][j1]=='X'||i1>=m||j1>=m)
        {
            cout<<" Moi ban nhap lai:";
            cout<<" Nhap hang:";
            cin>>i1;
            cout<<" Nhap cot:";
            cin>>j1;
        }
    else
        A[i1][j1]='O';   
}     
void nhap2(char A[max][max], int &m, int &i2, int &j2, char S2[10])
{
    cout<<" Moi nguoi choi"<<" "<<S2<< " nhap:"<<endl;
    cout<<" Nhap hang:";
    cin>>i2;
    cout<<" Nhap cot:";
    cin>>j2;
    if(i2<=0||j2<=0||A[i2][j2]=='O'||A[i2][j2]=='X'||i2>=m||j2>=m)
        {
            cout<<" Moi ban nhap lai:";
            cout<<" Nhap hang:";
            cin>>i2;
            cout<<" Nhap cot:";
            cin>>j2;
        }
    else
        A[i2][j2]='X';   
} 
int full(char A[max][max], int &m)
{
    int dem=0;
    for(int i=0; i<m; i++)
        {
            for(int j=0; j<m;j++)
                if(A[i][j]=='.')
                    dem++;
        }
    if(dem==0)
        return 0;
    else
        return 1;
}
void xetdong( char A[max][max], int &m, int &win, char S1[], char S2[])
{   int demo=0, demx= 0;
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<m; j++)
                {
                    if(A[i][j]=='O')
                    {
                        demo++;
                        if(demo==5&&A[i][j-5]!='X'&&A[i][j+1]!='X')
                             {
                                 cout<<"Nguoi choi"<<" "<< S1<< "win";
                                 win=1;
                             }                       
                    }
                    else
                        demo=0;
                    if(A[i][j]=='X')
                    {
                        demx++;
                        if(demx==5&&A[i][j-5]!='O'&&A[i][j+1]!='O')
                             {
                                 cout<<"Nguoi choi"<<" "<< S2<< "win";
                                 win=2;
                             }                           
                    }
                    else
                        demx=0;
                    
                }
        }
}  
void xetcot( char A[max][max], int &m, int &win, char S1[], char S2[])
{   int demo=0, demx= 0;
        for(int j=1; j<m-5+1; j++)
        {
            for(int i=1; i<m-j+1; i++)
                {
                    if(A[i][j]=='O')
                    {
                        demo++;
                        if(demo==5&&A[i-5][j]!='X'&&A[i+1][j]!='X')
                             {
                                 cout<<"Nguoi choi"<<" "<< S1<< "win";
                                 win=1;
                             }                       
                    }
                    else
                        demo=0;
                    if(A[i][j]=='X')
                    {
                        demx++;
                        if(demx==5&&A[i-5][j]!='O'&&A[i+1][j]!='O')
                             {
                                 cout<<"Nguoi choi"<<" "<< S2<< "win";
                                 win=2;
                             }                           
                    }
                    else
                        demx=0;
                    
                }
        }
} 
void xetcheoduoi( char A[max][max], int &m, int &win, char S1[], char S2[])
{   int demo=0, demx= 0;
        for(int i=1; i<m-5+1; i++)
        {           
            for(int j=1; j<m-i+1; j++) 
                {
                    if(A[i+j-1][j]=='O'&&A[i+j-1][j]==A[i+j][j+1])
                    {
                        demo++;
                        if(demo==4&&A[i+j-1-5][j-5]!='X'&&A[i+j-1+2][j+2]!='X')
                             {
                                 cout<<"Nguoi choi"<<" "<< S1<< "win";
                                 win=1;
                             }                       
                    }
                    else
                        demo=0;
                    if(A[i+j-1][j]=='X'&&A[i+j-1][j]==A[i+j][j+1])
                    {
                        demx++;
                        if(demx==4&&A[i+j-1-5][j-5]!='O'&&A[i+j-1+2][j+2]!='O')
                             {
                                 cout<<"Nguoi choi"<<" "<< S2<< "win";
                                 win=2;
                             }                       
                    }
                    else
                        demx=0;
                    
                }
        }
}
void xetcheotren( char A[max][max], int &m, int &win, char S1[], char S2[])
{   int demo=0, demx= 0;
        for(int j=2; j<m-5+1; j++)
        {           
            for(int i=1; i<m-j+1; i++) 
                {
                    if(A[i][j+i-1]=='O'&&A[i][j+i-1]==A[i+1][i+j])
                    {
                        demo++;
                        if(demo==4&&A[i-5][j+i-1-5]!='X'&&A[i+2][i+j-1+2]!='X')
                             {
                                 cout<<"Nguoi choi"<<" "<< S1<< "win";
                                 win=1;
                             }                       
                    }
                    else
                        demo=0;
                    if(A[i][j+i-1]=='X'&&A[i][j+i-1]==A[i+1][i+j])
                    {
                        demx++;
                        if(demx==4&&A[i-5][j+i-1-5]!='O'&&A[i+2][i+j-1+2]!='O')
                             {
                                 cout<<"Nguoi choi"<<" "<< S2<< "win";
                                 win=2;
                             }                       
                    }
                    else
                        demx=0;
                    
                }
        }
}
void xetcheophuduoi( char A[max][max], int &m, int &win, char S1[], char S2[])
{   int demo=0, demx= 0;
        for(int i=m; i>5; i--)
        {           
            for(int j=1; j<i; j++) 
                {
                    if(A[i-j+1][j]=='O'&&A[i-j+1][j]==A[i-j][j+1])
                    {
                        demo++;
                        if(demo==4&&A[i-j+1-5][j-5]!='X'&&A[i-j+1-2][j+2]!='X')
                             {
                                 cout<<"Nguoi choi"<<" "<< S1<< "win";
                                 win=1;
                             }                       
                    }
                    else
                        demo=0;
                     if(A[i-j+1][j]=='X'&&A[i-j+1][j]==A[i-j][j+1])
                    {
                        demx++;
                        if(demx==4&&A[i-j+1-5][j-5]!='O'&&A[i-j+1-2][j-2]!='O')
                             {
                                 cout<<"Nguoi choi"<<" "<< S2<< "win";
                                 win=2;
                             }                       
                    }
                    else
                        demx=0;                 
                }
        }
}
void xetcheophu( char A[max][max], int &m, int &win, char S1[], char S2[])
{   int demo=0, demx= 0;
        for(int i=m; i>5; i--)
        {           
            for(int j=1; j<i; j++) 
                {
                    if(A[i][j+1]=='O'&&A[i][j+1]==A[i-1][j+2])
                    {
                        demo++;
                        if(demo==4&&A[i-5][j+1-5]!='X'&&A[i-2][j+2]!='X')
                             {
                                 cout<<"Nguoi choi"<<" "<< S1<< "win";
                                 win=1;
                             }                       
                    }
                    else
                        demo=0;
                      if(A[i][j+1]=='X'&&A[i][j+1]==A[i-1][j+2])
                    {
                        demo++;
                        if(demx==4&&A[i-5][j+1-5]!='O'&&A[i-2][j+2]!='O')
                             {
                                 cout<<"Nguoi choi"<<" "<< S2<< "win";
                                 win=2;
                             }                       
                    }
                    else
                        demx=0;              
                }
        }
}
int main()
{
    char A[max][max];
    int m, win, i1, h, j1, i2, j2;
    int k=0;
    char S1[10], S2[10];
    cout<<" Moi nhap ten nguoi choi 1:";
    cin>>S1;
    cout<<" Moi nhap ten nguoi choi 2:";
    cin>>S2;
    khoidong(A,m);
    xuat(A,m);  
    h=full(A,m);
    while(h==1&&win==0)
    {
        if(k==0)
        {
            nhap1(A,m,i1,j1,S1);
            k++;
        }
        else
        {
            nhap2(A,m,i2,j2,S2);
            k--;
        }
        xuat(A,m);
        xetdong(A,m,win,S1,S2);  
        xetcot(A,m,win,S1,S2); 
        xetcheoduoi(A,m,win,S1,S2);
        xetcheotren(A,m,win,S1,S2);
        xetcheophuduoi(A,m,win,S1,S2);
        xetcheophu(A,m,win,S1,S2);            
    }    
    return 0;
}