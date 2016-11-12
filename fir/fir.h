#ifndef __FIR_H__
#define __FIR_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	15	// 棋盘大小

// 记录落子玩家:0.没有玩家   1.玩家1   2.玩家2
int whoseTurn = 0;
// 记录玩家落子对应棋盘坐标：0.未落子   1.玩家1   2.玩家2
int chessboard[N + 1][N + 1] = {0};

/**
 * 初始化游戏信息
 */
void initGame(void);

/**
 * 打印游戏棋盘
 * 1. 星号 (*), 表示未落子的位置
 * 2. 实心圆 (●), 表示玩家1的棋子
 * 3. 空心圆 (○), 表示玩家2的棋子
 */
void printChessboard(void);

/**
 * 游戏进行时, 处理相关的动作
 * 1. 将玩家的落子添加到相关位置
 * 2. 判断玩家是否获胜
 */
void playChess(void);

/**
 * 检测玩家落子是否符合条件;不符合则重新要求玩家输入直到符合为止, 符合则保存落子位置
 * 1. 满足棋盘位置坐标
 * 2. 满足对应位置之前未落子
 *
 * @param int
 * 		玩家落子行号
 * @param int
 * 		玩家落子列号
 * @param int
 * 		保存落子时, 对应玩家类型:1. 玩家1   2.玩家2
 */
void checkMove(int *, int *, int);

/**
 * 判断玩家是否获胜逻辑实现 
 * 即检验玩家落子后横,竖,或者两个斜线方向中是否有一个方向以及满足获胜条件
 * @param int
 * 		落子的行号
 * @param int
 * 		落子的列号
 * 		
 * @return	int:0.未满足获胜的条件   1.获胜
 */
int judge(int, int);

/**
 * 每进行一次游戏后, 将游戏时的相关数据进行初始化
 */
void clearGame(void);

/**
 * 退出游戏
 */
void destroy(void);

/**
 * 清空屏幕
 */
void clearScreen(void);


#endif // __FIR_H__
