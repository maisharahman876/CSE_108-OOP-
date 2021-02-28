#include<iostream>
#include<cstring>
using namespace std;

class Unit
{
    protected:
    int pos,step_size,cost,range,health,damage;
    int return_coin,last_health;
    char name[30];
    char arrowtype[50];
    char movetype[100];


public:

   bool if_in_range(int range,int pos)
    {
        if((pos+range)>=100)
            return 1;
        else
            return 0;
    }
    void move()
    {
        pos+=step_size;
    }
   bool if_lived()
    {
        if(health>0)
            return 1;
        else
            return 0;
    }

    bool moving()
    {
        if(step_size)
            return 1;
        else
            return 0;
    }

       void gamestate()
    {
        //int health=100;
        //bool ind=false;
       // coin-=cost;



         cout<<name;
        cout<<". Health:"<<health<<". ";
         if(moving())
          {
               move();

          }
          cout<<movetype<<". ";
        cout<<"Positioned at "<<pos<<".";
        if(if_in_range(range,pos))
        {
            cout<<name;
            cout<<" is shooting "<<arrowtype<<"."<<endl;

        }
         health-=40;
    }


        //<<"coin remaining "<<coin<<endl;
bool last_status()
{
     cout<<name<<".Health:"<<last_health<<". Unit died!"<<endl;
    // return last_health;
}




};
class Archer:public Unit
{
    //int pos;
public:
    Archer(int i)
    {
        pos=0;
    step_size=25;
    health=100;
    range=50;
    last_health=-20;
    cost=150;
    damage=25;
    strcpy(name,"Archer");
    strcpy(movetype,"Running");
    strcpy(arrowtype,"Advanced arrow");
    }





};
class AdvancedArcher:public Unit
{
   // int pos;
public:
    AdvancedArcher(int i)
    {
        pos=0;
    step_size=30;
    health=120;
    range=50;
    last_health=0;
    damage=50;
    cost=600;
     strcpy(name,"Advanced Archer");
    strcpy(movetype,"Riding horse");
    strcpy(arrowtype,"Improved arrow");
    }


};
class Bowman:public Unit
{
   // int pos;
public:
    Bowman(int i)
    {
        pos=0;
    step_size=0;
    health=60;
    range=110;
    cost=100;
    last_health=-20;
    return_coin=40;
    damage=10;
     strcpy(name,"Bowman");
    strcpy(movetype,"Stationary.");
    strcpy(arrowtype,"Basic arrow");
    }


};
class AdvancedBowman:public Unit
{
   // int pos;
public:
    AdvancedBowman(int i)
    {
        pos=0;
    step_size=0;
    health=85;
    range=130;
    last_health=-35;
    return_coin=60;
    cost=200;
    damage=15;
     strcpy(name,"Advanced Bowman");
    strcpy(movetype,"stationary");
    strcpy(arrowtype,"canon");
    }

};

int main()
{
    int coin=1600;
    int round=1;
    int Enemy_health=300;
    int choice;
    Unit *w;
    int i;
    while(1)
    {

         cout<<"coin remaining :"<<coin<<endl;
        cout<<"choose your option: "<<endl;
        cout<<"1.Archer (cost 150)"<<endl;
        cout<<"2.Advanced Archer (cost 600)"<<endl;
        cout<<"3.Bowman (cost 100)"<<endl;
        cout<<"4.Advanced Bowman (cost 200)"<<endl;
        cin>>choice;


        //cin>>choice;
        switch(choice)
        {
            case 1: w =  new Archer(0);


                    break;
            case 2: w = new AdvancedArcher(0);
            break;

            case 3: w =  new Bowman(0);

                    break;
            default : w = new AdvancedBowman(0);


                    break;
        }


        if(choice==1)
        {
            coin-=150;
            if(coin<0)
        {
            cout<<"you have no coin to afford this";
            break;
        }
             //cout<<"Round:"<<round<<endl;
             for(i=1;w->if_lived();i++)
             {
                  cout<<"Round:"<<round<<endl;
                w->gamestate();
                if(i!=1)
                     Enemy_health-=25;
                 if(Enemy_health<=0)
        {
            cout<<"Enemy is destroyed.you win!"<<endl;
            break;
        }

               // w->enemy_status();
                cout<<endl<<". EnemyTower's Health:"<<Enemy_health<<". Enemy tower is shooting fire arrow"<<endl;


                round++;
             }
              if(Enemy_health<=0)
        {
           // cout<<"you win!"<<endl;
            break;
        }
       // round++;
                cout<<"Round:"<<round<<endl;

             w->last_status();

        }
        else if(choice==2)
        {
            coin-=600;
            if(coin<0)
        {
            cout<<"you have no coin to afford this";
            break;
        }
             //cout<<"Round:"<<round<<endl;
              for(i=1;w->if_lived();i++)
             {
                  cout<<"Round:"<<round<<endl;
                w->gamestate();
                if(i!=1)
                     Enemy_health-=50;


                 if(Enemy_health<=0)
        {
            cout<<"Enemy is destroyed.you win!"<<endl;
            break;
        }
               // w->enemy_status();
                cout<<endl<<". EnemyTower's Health:"<<Enemy_health<<". Enemy tower is shooting fire arrow"<<endl;

                round++;
             }
              if(Enemy_health<=0)
        {
           // cout<<"you win!"<<endl;
            break;
        }
        //round++;
        cout<<"Round:"<<round<<endl;

             w->last_status();



        }
        else if(choice==3)
        {
            coin-=100;
            if(coin<0)
        {
            cout<<"you have no coin to afford this";
            break;
        }
             //cout<<"Round:"<<round<<endl;
             while(w->if_lived())
             {
                  cout<<"Round:"<<round<<endl;
                w->gamestate();
               // if(w->if_in_range())
                Enemy_health-=10;
                 if(Enemy_health<=0)
        {
            cout<<"Enemy is destroyed.you win!"<<endl;
            break;
        }
               // w->enemy_status();
                cout<<endl<<". EnemyTower's Health:"<<Enemy_health<<". Enemy tower is shooting fire arrow"<<endl;
                round++;
             }
              if(Enemy_health<=0)
        {
            //cout<<"you win!"<<endl;
            break;
        }
                //round++;
        cout<<"Round:"<<round<<endl;
             w->last_status();
             cout<<"bowman gave 40 coins while dying"<<endl;
             coin+=40;


    }
      else if(choice==4)
        {
            coin-=200;
            if(coin<0)
        {
            cout<<"you have no coin to afford this";
            break;
        }

             while(w->if_lived())
             {
                  cout<<"Round:"<<round<<endl;
                w->gamestate();
                Enemy_health-=15;
                 if(Enemy_health<=0)
        {
            cout<<"Enemy is destroyed.you win!"<<endl;
            break;
        }

               // w->enemy_status();
                cout<<endl<<". EnemyTower's Health:"<<Enemy_health<<". Enemy tower is shooting fire arrow"<<endl;
                round++;
             }
              if(Enemy_health<=0)
        {
           // cout<<"you win!"<<endl;
            break;
        }
       // round++;
                cout<<"Round:"<<round<<endl;


             w->last_status();
             cout<<"bowman gave 60 coins while dying"<<endl;
             coin+=60;


    }
}
}

