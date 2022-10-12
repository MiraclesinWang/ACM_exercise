#include <bits/stdc++.h>
using namespace std; 

class node{
public:
    node *l, *r;
    int val, l_num, r_num;
};

class balance_tree{
private:
    node * rt;   // len(l) >= len(r)
    int len;
    double get_middle(){
        if(len%2) return (double)rt->val;
        return double(rt->val+rt->l->val) / 2.0;
    }
    double insert(int rm, int ad){
        node * tmp = rt;
        while(tmp->val != rm){
            if(rm < tmp->l->val) tmp = tmp->l;
            else tmp = tmp->r;
        }
    }
    
};

int main()
{
	a = balance_tree();
 } 
