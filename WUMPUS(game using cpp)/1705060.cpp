#include <iostream>
#include <cmath>
#include <sstream>
#include<cstdlib>
#include<cstdio>

using namespace std;

#define GRIDSIZE 4
#define UP      0
#define DOWN    2
#define LEFT    3
#define RIGHT   1
#define MAX_SHOTS 3


string to_string(int x) {
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}


class Position {

    int x, y;

public:

    Position (int x, int y) {
        this->x = x;
        this->y = y;
    }

    Position() {

    }

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight() {
        if(x<3)
        x++;
    }

    void moveLeft() {
        if(x>0)
        x--;
    }

    void moveUp() {
        if(y<3)
        y++;
    }

    void moveDown() {
        if(y>0)
        y--;
    }

    bool isAdjacent(Position p) {
        //implement the function
        if((p.getX()-x==1&&(p.getY()==y))||((x-p.getX())==1&&(p.getY()==y))||((x==p.getX())&&(p.getY()-y==1))||((x==p.getX())&&(y-p.getY())))
         return 1;
         else
            return 0;
    }

    bool isSamePoint(Position p) {
        if(p.getX()==x&&p.getY()==y)
            return 1;
        //implement the function
        else
        return 0;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

};


class Wumpus {

    bool killed;
    Position p;

public:

    Wumpus(int x, int y) {
        p = Position(x, y);
        killed = false;
    }

    Wumpus() {
        //...
        int a=0,b=0;
        while(a==0&&b==0)
        {
        a=rand()%4;
        b=rand()%4;
        }
        p=Position(a,b);
        killed=false;
    }

    void kill() {
        killed = true;
        p=Position(-1,-2);
    }

    Position getPosition() {
        return p;
    }
    void setPosition(Position pos)
    {
        p=pos;
    }
    int getx()
{
    return p.getX();
}
int gety()
{
    return p.getY();
}


};
class Pit {

    bool killed;
    Position p;
     Wumpus wumpus;

public:

    Pit(int x, int y) {
        p = Position(x, y);
        killed = false;
    }

    Pit() {
        //...
        int a=0,b=0;
        Position temp;
        temp=wumpus.getPosition();
        while((a==0&&b==0)||temp.isSamePoint(p))
        {
        a=rand()%4;
        b=rand()%4;
        }
        p=Position(a,b);

    }



    Position getPosition() {
        return p;
    }
     void setPosition(Position pos)
    {
        p=pos;
    }


};


class Player {

 int direction;

       Position p;



public:

 int total_shots;

    bool killed;

    Player() {
        //...
        p=Position(0,0);
        killed=false;
        total_shots=MAX_SHOTS;
        direction=0;

    }

    void turnLeft() {
        //...
        direction=(direction+3)%4;

    }

    void turnRight() {
        direction=(direction+1)%4;
        //...
    }

    void moveForward() {
        //...
        if(direction==UP)
            p.moveUp();
        else if(direction==DOWN)
            p.moveDown();
        else if(direction==RIGHT)
            p.moveRight();
        else
            p.moveLeft();
    }

    bool isAdjacent(Position pos) {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos) {
        return p.isSamePoint(pos);
    }

    void kill() {
        killed = true;

    }
int getx()
{
    return p.getX();
}
int gety()
{
    return p.getY();
}
int getdirection()

{
    return direction;
}
int getshot()
{
    return total_shots;
}

    string getPositionInfo() {
        return "Player is now at " + to_string(p.getX()) + ", " + to_string(p.getY());
    }

    string getDirectionInfo() {
        string s;
        if (direction == UP) s = "up";
        if (direction == DOWN) s = "down";
        if (direction == LEFT) s = "left";
        if (direction == RIGHT) s = "right";
        return "Player is moving at direction: " + s;
    }

};



class WumpusWorld {

private:

    Player player;
    Pit pit;
    Wumpus wumpus;
    Position gold_position;
    bool ended;

public:

    WumpusWorld() {
        //...
        Position pw,pp;
        pw=wumpus.getPosition();
        pp=pit.getPosition();
        int a=0,b=0;
         gold_position=Position(a,b);
        while((a==0&&b==0)||pw.isSamePoint(gold_position)||pp.isSamePoint(gold_position))
        {
            a=rand()%4;
            b=rand()%4;

        }
        gold_position=Position(a,b);
        wumpus.setPosition(pw);
        pit.setPosition(pp);
        ended=false;


    }

    WumpusWorld(int wumpus_x, int wumpus_y) {
        //..
        wumpus=Wumpus(wumpus_x,wumpus_y);
        Position temp;
        temp=pit.getPosition();
        int a=0,b=0;
        gold_position=Position(a,b);
        while((a==0&&b==0)||temp.isSamePoint(gold_position)||(a==wumpus_x&&b==wumpus_y))
        {
            a=rand()%4;
            b=rand()%4;
        }
        gold_position=Position(a,b);
        ended=false;

    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y) {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        gold_position=Position(gold_x,gold_y);
        int a=0,b=0;

        while((a==0&&b==0)&&(a==gold_x&&b==gold_y)||(a==wumpus_x&&b==wumpus_y))
        {
            a=rand()%4;
            b=rand()%4;

        }

         pit=Pit(a,b);
         ended=false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y) {
        //...
        wumpus=Wumpus(wumpus_x,wumpus_y);
        pit=Pit(pit_x,pit_y);
        gold_position=Position(gold_x,gold_y);
        ended=false;
    }

    void moveForward() {
        player.moveForward();
        return showGameState();
    }

    void turnLeft() {
        player.turnLeft();
        return showGameState();
    }

    void turnRight() {
        player.turnRight();
        return showGameState();
    }

    void shoot() {
        //..
         player.total_shots--;
        Position tw,tp;
        tw=wumpus.getPosition();
        int wx,wy,px,py,pd;
        wx=wumpus.getx();
        wy=wumpus.gety();
        px=player.getx();
        py=player.gety();
        pd=player.getdirection();
         if(pd==UP && wy>py&&wx==px)
        {
        cout<<"Scream"<<endl;
        wumpus.kill();
        }

        else if(pd==DOWN && py>wy&&wx==px)
        {
            cout<<"Scream!"<<endl;
            wumpus.kill();
        }
        else if(pd==RIGHT && px>wx&&py==wy)
        {
            cout<<"Scream!"<<endl;
            wumpus.kill();
        }
        else if(pd==LEFT && wx>px&&wy==py)
        {
            cout<<"Scream!"<<endl;
            wumpus.kill();
        }
        else
        {
            if(player.total_shots<=0)
                cout<<"No shots Remaining";
            else
            cout<<"MISSED. Available Shots: "<<player.getshot()<<endl;
        }

    }

    void showGameState() {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.killed==false&&player.isAdjacent(wumpus.getPosition())) {
            cout << "stench!" << endl;
        }

        if (player.killed==false&&player.isSamePoint(wumpus.getPosition())) {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }
         if (player.killed==false&&player.isSamePoint(pit.getPosition())) {
            cout << "You are rotted" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }
        if(player.isAdjacent(pit.getPosition()))
        {
            cout<<"Breeze!"<<endl;
        }

        if (player.isSamePoint(gold_position)) {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver() {
        return ended;
    }

};


int main()
{

Position pos;
    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // take the six integers input from file
    FILE *fp;
    fp=fopen("wumpus.txt","r");
    fscanf(fp,"%d",&wumpus_x);
    fscanf(fp,"%d",&wumpus_y);
    fscanf(fp,"%d",&gold_x);
    fscanf(fp,"%d",&gold_y);
    fscanf(fp,"%d",&pit_x);
    fscanf(fp,"%d",&pit_y);

    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    w.showGameState();
    while (!w.isOver()) {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1) {
            w.moveForward();
        } else if (c == 2) {
            w.turnLeft();
        } else if (c == 3) {
            w.turnRight();
        } else if (c == 4) {
            w.shoot();
        }
    }
    return 0;
}
