//
//  equivalence.cpp
//  DataStructure_homework4[equivalence]
//
//  Created by Yu-An Ko on 2016/5/7.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//
#include "List.hpp"

void equivalence()
//input the equivalence pairs and output the equivalence classes
{	ifstream inFile("/Users/Anndo/Documents/NTUST_DataStructure/00-1 homework/DataStructure_homework4/DataStructure_homework4[equivalence]/DataStructure_homework4[equivalence]/equiv.in",ios::in); //"equiv.in" is th input file
    if(!inFile){
        cerr<<"Cannot open input file"<< endl;
        return;
    }
    
    int i,j,n;
    inFile>>n;// read number of objects
    // initialize seq and out
    ListNodePtr *seq = new ListNodePtr[n];
    //Boolean *out=new Boolean[n];
    Boolean out[12];
    for(i=0;i<n;i++){
        seq[i]=0;
        out[i]=FALSE;
    }
    //phase 1: input equivalence pairs
    // inFile >> i >> j;
    do { // check end of file
        inFile >> i >>j;
        ListNode *x = new ListNode(j); x->link=seq[i]; seq[i]=x; // add j to seq[i]
        ListNode *y = new ListNode(i); y->link=seq[j]; seq[j]=y; // add i to seq[j]
        //	inFile >> i >> j;
    } while(inFile.good());
    
    //phase 2:output equivalence classes
    for(i=0;i<n;i++)
        if(out[i]==FALSE) { // NEEDS TO BE OUTPUT
            cout << endl <<"A new class: "<<i;  out[i]= TRUE;
            ListNode *x = seq[i]; ListNode *top = 0; // init stack
            while(1) {		// find rest of class
                while(x) {	//process the list
                    j = x->data;
                    if(out[j]==FALSE) {
                        cout<<", "<<j;
                        out[j]=TRUE;
                        ListNode *y = x->link;
                        x->link = top;
                        top=x;
                        x=y;
                    }
                    else x = x->link;
                }// end of while(x)
                if (!top) break;
                else{
                    x = seq[top->data];
                    top = top->link;  // unstack
                }
            }// end of while(1)
        }// end of if(out[i]=FALSE)
    /* There is a serious problem of this program:
     The original linked list has been destroyed by the above while loop
     However, the following program try to release (delete) memory as
     if the original liked list is intact */
    /*  for(i=0;i<n;i++)
     while(seq[i]) { 
     cout <<"here" << i << endl;
     ListNode *delnode = seq[i];  
     seq[i]=delnode->link;  
     delete delnode;
     }
     */
    //		delete seq; 
    //		delete []out;
}; // end of equivalence

// modified from equivalence() that is wrong
// when forming the linked list, you have to copy instead of using the node data directly.

