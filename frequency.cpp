#include<iostream> 
#include<streambuf>
#include<ios>
#include<istream>
#include<ostream>
#include<fstream>

using namespace std;
int main()
{
    // create an array
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //creating a temp array
    int ar[n];
    for(int i=0;i<n;i++)
    {
        ar[i]=arr[i];
    }

    //checking frequency
    int count=1;
    for(int i=0;i<n;i++)
    {   
        if(ar[i]!=0)
        {   cout<<ar[i]<<"=";
            for(int j=i+1;j<n;j++)
            {
                if(ar[j]==ar[i])
                {
                    count++;
                    ar[j]=0;
                }
            }
             cout<<" "<<count<<"\n";  
        }count=1;    
    }
}