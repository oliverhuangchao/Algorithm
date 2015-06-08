#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stack>

std::string largestNumber(std::vector<int>& num);
std::vector<int> twoSum(std::vector<int> &numbers,int target);
bool canJump2(int x[],int n);
int ldistance(std::string s1, std::string s2);
//int getLD(std::string& x, std::string& y,int i,int j,std::vector<std::vector<int>>& value);
int getLD(std::string& x, std::string& y,int i,int j,int** value);
inline int min3(int,int,int);
int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost);
