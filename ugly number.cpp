#include<iostream>
#include<streambuf>
#include<ios>
#include<istream>
#include<ostream>
#include<fstream>

using namespace std;
int main()
{
    //nth usgly number
    int n;
    cout<<"Enter the value for n:: ";
    cin>>n;

    //enter the value for a,b and c;
    int arr[3];
    for(int i=0;i<3;i++)
    {
        cout<<"Enter the value for arr["<<i<<"]:: ";
        cin>>arr[i];
        if(arr[i]==0)
        {
            cout<<"Zero Cannot be enter"<<"\n"<<"Enter the value for arr["<<i<<"] again:: ";
            cin>>arr[i];
        }
    }

    //creating dynamic memory for storing the numbers
    int numbers=1;
    int *p,i,s=0;
    p=(int *)malloc(sizeof(int));

    for(i=0;s<n;i++)
    {
        if(numbers%arr[0]==0||numbers%arr[1]==0||numbers%arr[2]==0)
        {
            *(p+s)=numbers;
            s++;
        }
        numbers++;
    }
    
    for(i=0;i<n;i++)
    {
        cout<<*(p+i)<<" ";
    } 
    cout<<"\n";
    cout<<*(p+n-1);
    
}