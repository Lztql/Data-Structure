/*=============================
 * 树的孩子链表(带双亲)的存储表示
 =============================*/

#ifndef CTREE_H
#define CTREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include "Status.h"     //**▲01 绪论**//
#include "LinkQueue.h"  //**▲03 栈和队列**//

/* 树的最大结点数 */
#define MAX_TREE_SIZE 1024

/* 单个结点最大的孩子数量 */
#define MAX_CHILD_COUNT 8

/* 树的元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/* 孩子结点定义 */
typedef struct CTNode {
    int child;              // 该孩子在树中的索引
    struct CTNode* next;    // 指向下一个孩子
} CTNode;

/* 指向孩子结点的指针 */
typedef CTNode* ChildPtr;

/* (双亲)树的结点定义 */
typedef struct {
    int parent;             // 双亲位置域
    TElemType data;         // 当前结点
    ChildPtr firstchild;    // 孩子链表头指针
} CTBox;

/*
 * (双亲)树类型定义
 *
 *【注】
 * 1.树中结点在nodes中"紧邻"存储，没有空隙
 * 2.树根r可能出现在nodes的任意位置
 * 3.除根结点外，其他结点依次按层序顺着根结点往下排列（这一点与教材图示可能会有区别）
 * 4.nodes数组是循环使用的（这一点教材未提到）
 * 5.这里假设nodes空间是足够大的，可以视需求将其改为动态分配存储
 */
typedef struct {
    CTBox nodes[MAX_TREE_SIZE]; // 存储树中结点
    int r;  // 树根位置(索引)
    int n;  // 树的结点数
} CTree;


/*
 * 树中某个结点的信息
 *
 * 注：相比双亲表存储结构，不需要再寄来当前结点的第一个孩子在树中的索引
 * */
typedef struct{
    int row;            // 当前结点所处的行
    int col;            // 当前结点所处的列
    int childIndex;     // 当前结点是第几个孩子
    int lastChild;      // 当前结点的最后一个孩子在树中的索引
} Pos;


/*
 * 初始化
 *
 * 构造空树。
 */
Status InitTree(CTree* T);

/*
 * 判空
 *
 * 判断树是否为空树。
 */
Status TreeEmpty(CTree T);

/*
 * 树深
 *
 * 返回树的深度（层数）。
 */
int TreeDepth(CTree T);


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 获取树T的结点信息，具体包含哪些信息，请参照Pos类型的定义
static void getPos(CTree T, Pos pt[]);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前结构
void PrintGraph(CTree T);

// 图形化输出当前结构内部实现
static void Print(CTree T, Pos pt[], int i);

// 图形化输出树的排列结构，仅限内部测试使用
static void PrintFramework(CTree T);

#endif