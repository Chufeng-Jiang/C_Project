#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


#define WIDE 60			// 宽度
#define HIGH 20			// 高度

// 一个身体的对象
struct BODY {
	int X;	//身体的横坐标
	int Y;	//身体的纵坐标
};

// 定义蛇对象
struct SNAKE {
	struct BODY body[WIDE * HIGH];	//这个蛇身体最长是满屏幕的长度
	int size;	//记录身体长度
}snake;			// 一个蛇对象

// 定义食物对象
struct FOOD {
	int X; 	//食物出现的横坐标
	int Y;	//食物出现的纵坐标
}food;			// 一个食物对象

int score = 0;	// 分数

int kx = 0;			// 用户按下 asdw 任意一个按键所得到的坐标值，用于更改蛇进行的方向。
int ky = 0;

int lastX = 0;		// 蛇尾的坐标。
int lastY = 0;

int sleepSecond = 400; // 控制蛇的运行速度

// 声明函数
void initSnake(void);
void initFood(void);
void initUI(void);
void playGame(void);
void initWall(void);
void showScore(void);

#endif
