/**
 *
 * 计算器程序
 * 1. 采用逆波兰表示法代替普通的中缀表示法
 * 2. 实现功能包括加(+),减(-),乘(*),除(/) 四则运算
 * 3. 会涉及到数据结构栈的操作 (每个操作数被依次压入栈中,当一个运算符到达时;从栈中弹出相应数目的操作数(对二元运算符来说是两个操作数),把该运算符作用于弹出的操作数,并把运算结果再压入栈中)
 *
 */
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP	100		// 操作数或运算符的最大长度
#define NUMBER	'0'		// 标识找到一个数

#define MAXVAL	100		// 栈值的最大深度

#define BUFSIZE	100		// 缓冲区预读长度

/**
 * 把指定值压入栈中
 *
 * @param data	需要压入的数据
 */
void push(double data);

/**
 * 弹出并返回栈顶元素
 */
double pop();

/**
 * 获取下一个运算符或数值操作数
 */
int getop(char op[]);

/**
 * 读入下一个待处理的字符 (可能是压回的字符)
 */
int getch();

/**
 * 把字符放入到输入中
 */
void ungetch(int ch);

/**
 * 把字符串转换为相应的双精度浮点数
 *
 * @param ch	待转换的字符串 
 */
//double atof(char ch[]);


#endif	// __CALCULATOR_H__
