#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
#define Width 30
#define BackgroudWidth 64
#define BackgroudHeight 36
class Snake;
class SnakePart;
class Snake {
private:
    std::vector<SnakePart> mySnake;// 使用vector容器，便于向后添加蛇身
    int length;
    std::string direction;
    cv::Point food;
public:
    Snake();
    void move(cv::Mat &img);
    void print(cv::Mat &img);
    cv::Point createfood();
    void control();
    bool ifcontinue();
};
class SnakePart {
    friend class Snake;
    friend void Snake::control();
private:
    cv::Point point;
public:   
    SnakePart(cv::Point pp);
};

SnakePart::SnakePart(cv::Point pp) {
    point = pp;
}

Snake::Snake() {
    length = 2;
    direction = "right";
    food = createfood();
    mySnake.push_back(SnakePart(cv::Point(2 * Width, Width)));
    mySnake.push_back(SnakePart(cv::Point(Width, Width)));
}
void Snake::move(cv::Mat &img) {
    img = cv::Scalar(255,255,255);
    cv::Point head = mySnake[0].point;//临时存储蛇头位置
    /*如何移动，通过string direction控制*/
    if (direction == "up")
        mySnake[0].point.y -= Width;
    else if (direction == "down")
        mySnake[0].point.y += Width;
    else if (direction == "left")
        mySnake[0].point.x -= Width;
    else if (direction == "right")
        mySnake[0].point.x += Width;
    /*判断是否吃到食物*/
    if(mySnake[0].point == food) {
        length++;
        mySnake.push_back(SnakePart(head));
        food = createfood();//随机生成食物位置（伪随机），1920/30=64,1080/30=36,一共64*36格
    }
    /*移动*/   
    for(int i = 1; i < length; i++) {
        cv::Point p = mySnake[i].point;//p为中间变量，记录上一个蛇身
        mySnake[i].point = head;
        head = p;
    }
}

void Snake::print(cv::Mat &img) {
    int i = 0;
    /*计分器*/
    cv::putText(img, "Length:", cv::Point(20, 30), 0, 1, cv::Scalar(255, 0, 0), 2);
    cv::putText(img, std::to_string(length), cv::Point(150, 30), 0, 1, cv::Scalar(255, 0, 0), 2);//打印蛇身长度
    /*打印蛇身*/
    for(i = 0; i < length; i++) {
        cv::rectangle(img, cv::Rect(mySnake[i].point.x, mySnake[i].point.y, Width, Width), cv::Scalar(0, 0, 0), -1);
    }
    /*打印食物*/
    cv::rectangle(img, cv::Rect(food.x, food.y, Width, Width), cv::Scalar(0, 0, 255), -1);
}

void Snake::control() {
    int c = cv::waitKey(300);//等待300ms
    if(c == 'w' && direction != "down")//禁止反向移动，因为反向移动会导致蛇头与第一段蛇身重合，导致判定游戏结束  
        direction = "up";
    else if(c == 's' && direction != "up")  
        direction = "down";
    else if(c == 'a' && direction != "right")  
        direction = "left";
    else if(c == 'd' && direction != "left") 
        direction = "right";
}

bool Snake::ifcontinue() {
    bool one = false;
    int i = 0;
    if(mySnake[0].point.x >= 1920 || mySnake[0].point.x < 0 || mySnake[0].point.y >= 1080 || mySnake[0].point.y < 0) {   
        one = true;
    }
    for(i = 1; i < length; i++) {
        if(mySnake[0].point == mySnake[i].point){
            one = true;
            break;
        }
    }
    return one;
}

cv::Point Snake::createfood() {
    cv::Point foodpoint = cv::Point(((rand() % 63) + 1) * Width, ((rand() % 35) + 1) * Width);//随机生成食物位置（伪随机），1920/30=64,1080/30=36,一共64*36格
    return foodpoint;
}

int main() {
    cv::Mat img(cv::Size(BackgroudWidth * Width, BackgroudHeight * Width), CV_8UC3, cv::Scalar(255, 255, 255));
    Snake snake1;
    srand(time(0));//更新随机数种子
    while(1) {
        snake1.move(img);
        snake1.print(img);
        cv::imshow("Snake Game", img);
        if(snake1.ifcontinue()) {
            cv::putText(img, "Game Over!", cv::Point(900,500), 0, 1, cv::Scalar(0, 0, 255), 2);
            cv::imshow("Snake Game", img);
            cv::waitKey();
            break;
        }
        snake1.control();
    }
    return 0;
}