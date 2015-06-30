#include "basic.h"
/*class myfunc{
    bool operator()(Interval &x, Interval &y){
        return x.start > y.start;
    }
};*/

bool myfunc(Interval &x, Interval &y){
    return x.start > y.start;
}


vector<Interval> merge(vector<Interval> &intervals) {
    // write your code here
    sort(intervals.begin(),intervals.end(),myfunc);
    int start = intervals[0].start;
    int end = intervals[0].end;
    vector<Interval> res;
    for(int i = 1;i<intervals.size();i++){
        if(intervals[i].start > end){
            Interval tmp(start,end);
            res.push_back(tmp);
            start = intervals[i].start;
            end = intervals[i].end;
        }
        else{
            end = max(end,intervals[i].end);
        }
    }
    Interval tmp(start,end);
    res.push_back(tmp);
    return res;
}
    
int main(){

}
