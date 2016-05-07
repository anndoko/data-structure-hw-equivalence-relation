//
//  List.hpp
//  DataStructure_homework4[equivalence]
//
//  Created by Yu-An Ko on 2016/5/7.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#pragma  warning(push, 0)
#include <fstream>
#include <iostream>
using namespace std;

enum Boolean {FALSE,TRUE};
class ListNode {
    friend void equivalence();
private:
    int data;
    ListNode *link;
    ListNode(int d) {data =d; link=0;};
    ListNode(const ListNode &b) {data=b.data; link=b.link;};
};
typedef ListNode *ListNodePtr;
extern void equivalence();

#endif /* List_hpp */
