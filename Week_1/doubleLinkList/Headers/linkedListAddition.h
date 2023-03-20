#ifndef LLA_H_INCLUDED
#define LLA_H_INCLUDED

#include "linkedList.h"

// 为了方便快速测试 
// 传入LNode* p,在 p 后生成值为 e 的节点
Status InsertNode(LNode *p,ElemType e);



/**
 *  @name        : Status PrintList(LinkedList *L);
 *	@description : 打印单向链表,当链表为空返回 Error
 *	@param		 : L(the head node)
 *	@return		 : Status 
 *  @notice      : 不要打印成环的链表
 */
Status PrintList(LinkedList L);

// when p->next = NULL connect p to q
Status CreatLoop(LNode *p,LNode*q);

#endif