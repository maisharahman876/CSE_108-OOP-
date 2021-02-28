#include<iostream>
#include<cstdlib>
using namespace std;

class stack
{
    int tos,max_size;
    int *stck;
public:
    stack()
    {
        tos=0;
       // size=10;
        max_size=10;
        stck=new int(10);
    }
    stack(int n)
    {
     stck=new int[n];
     tos=0;
       // stck=(int*)realloc(stck,size+4*n);
          max_size=n;
    }
   /* stack(const stack &obj)
    {
        size=obj.size;
        resize();

    }
    */
    void resize()
    {
        stck=(int *)realloc(stck,tos+10*4);
    }
     void push(int n)
     {
         if (tos==max_size)
            resize();
        stck[tos++] = n;

     }
    void push(int a[],int s)
    {

        if((s+tos)>max_size)
            resize();
            max_size=tos+s;

       int i;
       for(i=0;i<s;i++)
       {
            push(a[i]);

       }
       //stck[tos++]=a[i];

    }
    void push(stack st)
    {
        if((tos+st.tos)>max_size)
            resize();
            max_size=max_size+st.tos;
            while((st.tos))
            {
                push(st.pop());
            }

    }

    int pop()
    {
        if(tos==0)
            cout<<"stack is empty"<<endl;
            else

            return stck[--tos];
    }


int top()
{
    return stck[tos-1];
}
int s()
{
    return tos;
}
double similarity(stack st)
{
    int count=0;
    double avg_size=(tos+st.s())/2;
    if(tos>st.s())
    {
        while(!is_empty())
        {
            if(pop()==st.pop())
                count++;
        }
    }
    else
        while(!st.is_empty())
    {
        if(st.pop()==pop())
        {
            count++;
        }
    }
    return (count/avg_size);
}

~stack()
{
     delete[] stck;
}
bool is_empty()
{
    return (!tos);
}
};
   int main()
    {
        stack obj;
        int i,j,n,s;
        int ara[10];
        while(1)
        {
            cout<<"1:push an element"<<endl;
            cout<<"2:push an array"<<endl;
            cout<<"3:push a stack"<<endl;
            cout<<"4:pop"<<endl;
            cout<<"5:top"<<endl;
            cout<<"6:size"<<endl;
            cout<<"7:similarity"<<endl;
            cout<<"8:Exit"<<endl;
            cin>>i;
             //stack x=obj;
            if(i==1)
            {
               cin>>n;

               obj.push(n);
            }
            // stack y=obj;
            else if(i==2)
            {
               cout<<"enter size"<<endl;
               cin>>s;

               for(j=0;j<s;j++)

               {
                  cin>>ara[j];
               }
               obj.push(ara,s);

            }
             //stack z=obj;
            else if(i==3)
            {
                cout<<"Enter the size of stack"<<endl;
                cin>>s;
                stack obj2(s);

                for(j=0;j<s;j++)
                {
                    cin>>n;
                    obj2.push(n);

                }
                obj.push(obj2);
            }
            else if(i==4)
            {

                cout<<obj.pop()<<endl;
            }
            else if(i==5)
            {
                cout<<obj.top()<<endl;
            }
            else if(i==6)
            {
           cout<< obj.s()<<endl;
            }

            else if(i==7)
            {
                cout<<"Enter the size of stack"<<endl;
                cin>>s;
                stack obj3(s);

                for(j=0;j<s;j++)
                {
                    cin>>n;
                    obj3.push(n);


                }

               cout<< obj.similarity(obj3)<<endl;
            }
            else
            {
                 while(!obj.is_empty())
                {
                    cout<<obj.pop()<<endl;
                }
                break;

            }



        }
        return 0;
    }
