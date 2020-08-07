#include<iostream>
#include<streambuf>
#include<ios>
#include<istream>
#include<ostream>
#include<fstream>

using namespace std;
void number_to_words(int *num,int size)
{   
    
    char ones[][10]={
                     "zero","one","two", "three","four",
                     "five","six","seven","eight","nine"
                    };
    char teen[][10]={
                     "ten","eleven","twelve","thirteen",
                     "fourteen","fifteen","sixteen","seventeen",
                     "eighteen","ninteen"
                    };
    char tens_mul[][10]={
                     "twenty","thirty","forty","fifty","sixty",
                     "seventy","eighty","ninty"
                    };
    char hun[][10]= {
                     "hundred","thousand"
                    };

    //for single digits
    if(size==1)
    {
            cout<<ones[*num];
    }

    //for double digits
    if(size==2)
    {
        if(*(num)==1)
            cout<<teen[*(num+1)];
        else
        {   if(*(num+1)!=0)
            cout<<tens_mul[*num-2]<<" "<<ones[*(num+1)];
            else
            cout<<tens_mul[*num-2];
        }
    }

    //for three digits
    if(size==3)
    {   
        if(*(num+1)==0&&*(num+2)==0)
            cout<<ones[*num]<<" "<<hun[0];
        else
        {
            cout<<ones[*num]<<" "<<hun[0]<<" ";
        
            if(*(num+1)==0)
                cout<<ones[*(num+2)]<<" ";
            else
            {
            if(*(num+1)==1)
                cout<<teen[*(num+2)];
            else
            {   if(*(num+2)!=0)
               cout<<tens_mul[*(num+1)-2]<<" "<<ones[*(num+2)];
               else
               cout<<tens_mul[*(num+1)-2];
            }
            }
        }
    }

    //for four digits number
    if(size==4)
    {   
    if(*(num+1)==0&&*(num+2)==0&&*(num+3)==0)
        cout<<ones[*num]<<" "<<hun[1];
    else
        {    
        if(*(num+1)==0&&*(num+2)==0)
            cout<<ones[*num]<<" "<<hun[1]<<" "<<ones[*(num+3)];
        else
        if(*(num+1)==0&&*(num+2)==1)
            cout<<ones[*num]<<" "<<hun[1]<<" "<<teen[*(num+3)];
        else
        if(*(num+2)==1)
            cout<<ones[*num]<<" "<<hun[1]<<" "<<ones[*(num+1)]<<" "<<hun[0]<<" "<<teen[*(num+3)];
        else
            if(*(num+3)==0)
            cout<<ones[*num]<<" "<<hun[1]<<" "<<ones[*(num+1)]<<" "<<hun[0]<<" "<<tens_mul[*(num+2)-2];
            else
            cout<<ones[*num]<<" "<<hun[1]<<" "<<ones[*(num+1)]<<" "<<hun[0]<<" "<<tens_mul[*(num+2)-2]<<" "<<ones[*(num+3)];     
        }
    }
}
int main()
{
    //Enter the test cases
    int test_case;
    cout<<"Enter the Test Case:: ";
    cin>>test_case;

    //array of test cases
    int arr[test_case];
    cout<<"Enter "<<test_case<<" numbers:: ";
    for(int i=0;i<test_case;i++)
    {
        cin>>arr[i];
    }
    
    int i=0;
    while(i<test_case)
    {
    //creating a pointer array
    int *p,s=0;
    p=(int *)malloc(sizeof(int));

    //counting the digits and putting the digits in array
    int count=0;
    if(arr[i]==0)
    {
        *(p+s)=0;
        count++;
    }
  
  //putting the number in the test array
    int b=arr[i];
    while(arr[i]>0)
    {
        *(p+s)=arr[i]%10;
        arr[i]/=10;
        count++;
        s++;
    }

    int temp;
    //reversing the array
   for(int i=0;i<(count+1)/2;i++)
   {
      temp=*(p+i);
      *(p+i)=*(p+count-(i+1));
      *(p+count-(i+1))=temp;
   }
  
    //calling the function
    cout<<b<<":: ";
    number_to_words(p,count);
    i++;
    cout<<"\n";
    }
}   