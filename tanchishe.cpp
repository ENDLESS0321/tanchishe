#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
using namespace std;
using namespace cv;
#define Width 30
#define BackgroudWidth 64
#define BackgroudHeight 36
class Snake;
class SnakePart;
class Snake
{
private:
    vector<SnakePart> mySnake;//使用vector容器，便于向后添加蛇身
    int length;
    string direction;
public:
    Snake();
    void move(Point &foodpoint,Mat &img);
    void print(Mat &img);
    Point createfood();
    void control();
    bool ifcontinue();
};
class SnakePart
{
    friend class Snake;
    friend void Snake::control();
private:
    Point point;
public:   
    SnakePart(Point pp);
};

SnakePart::SnakePart(Point pp)
{
    point=pp;
}

Snake::Snake()
{
    length = 2;
    direction = "right";
    mySnake.push_back(SnakePart(Point(2*Width, Width)));
    mySnake.push_back(SnakePart(Point(Width, Width)));
}
void Snake::move(Point &foodpoint, Mat &img)
{
    Point head=mySnake[0].point;//临时存储蛇头位置
    if (direction=="up")
        mySnake[0].point.y-=Width;
    else if (direction=="down")
        mySnake[0].point.y+=Width;
    else if (direction=="left")
        mySnake[0].point.x-=Width;
    else if (direction=="right")
        mySnake[0].point.x+=Width;
    if(mySnake[0].point==foodpoint)
    {
        length++;
        mySnake.push_back(SnakePart(head));
        foodpoint=Point(((rand()%63)+1)*Width,((rand()%35)+1)*Width);//随机生成食物位置（伪随机），1920/30=64,1080/30=36,一共64*36格
    }   
    for(int i=1;i<length;i++)
    {
        Point p=mySnake[i].point;//p为中间变量，记录上一个蛇身
        mySnake[i].point=head;
        head=p;
    }
    rectangle(img,Rect(foodpoint.x,foodpoint.y,Width,Width),Scalar(0,0,255),-1);
    print(img);
}
void Snake::print(Mat &img)
{
    int i=0;
    putText(img,"Length:",Point(20,30),0,1,Scalar(255,0,0),2);
    putText(img,std::to_string(length),Point(150,30),0,1,Scalar(255,0,0),2);//打印蛇身长度
    for(i=0;i<length;i++)
    {
        rectangle(img,Rect(mySnake[i].point.x,mySnake[i].point.y,Width,Width),Scalar(0,0,0),-1);
    }
}
void Snake::control()
{
    int c=waitKey(300);//等待300ms
        if(c=='w'&&direction!="down")//禁止反向移动，因为反向移动会导致蛇头与第一段蛇身重合，导致判定游戏结束  
            direction="up";
        else if(c=='s'&&direction!="up")  
            direction="down";
        else if(c=='a'&&direction!="right")  
            direction="left";
        else if(c=='d'&&direction!="left") 
            direction="right";
}
bool Snake::ifcontinue()
{
    bool one=false;
    int i=0;
    if(mySnake[0].point.x>=1920||mySnake[0].point.x<0||mySnake[0].point.y>=1080||mySnake[0].point.y<0)
        {   
            one=true;
        }
    for(i=1;i<length;i++)
    {
        if(mySnake[0].point==mySnake[i].point)
        {
            one=true;
            break;
        }
    }
    return one;
}
Point Snake::createfood()
{
    Point foodpoint=Point(((rand()%63)+1)*Width,((rand()%35)+1)*Width);//随机生成食物位置（伪随机），1920/30=64,1080/30=36,一共64*36格
}
int main()
{
    Mat img(Size(BackgroudWidth*Width,BackgroudHeight*Width),CV_8UC3,Scalar(255,255,255));
    Snake snake1;
    int i=0;
    Point foodpoint=Point(((rand()%(BackgroudWidth-1))+1)*Width,((rand()%(BackgroudHeight-1))+1)*Width);
    rectangle(img,Rect(foodpoint.x,foodpoint.y,Width,Width),Scalar(0,0,255),-1);
    srand(time(0)); // 更新随机数种子
    while(1)
    {
        img=Scalar(255,255,255);
        snake1.move(foodpoint,img);
        // 重新绘制食物
        rectangle(img,Rect(foodpoint.x,foodpoint.y,Width,Width),Scalar(0,0,255),-1);
        snake1.print(img);
        imshow("Snake Game",img);
        if(snake1.ifcontinue())
        {
            putText(img,"Game Over!",Point(900,500),0,1,Scalar(0,0,255),2);
            imshow("Snake Game",img);
            waitKey();
            break;
        }
        snake1.control();
    }
    return 0;
}