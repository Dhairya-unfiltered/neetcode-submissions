class MedianFinder {
public:

      priority_queue<int>max;
      priority_queue<int,vector<int>,greater<int>>min;
      MedianFinder() {}
    
    void addNum(int num) {
        max.push(num);
        min.push(max.top());
        max.pop();
        if(max.size()+1<min.size()){
            max.push(min.top());
            min.pop();
        }
    }


    //3,4,5,6,7

    // add 3:
    //   max:
    //   min:3
    //   0+1<1 does not equal true

    // add 3:
    //   max: 3
    //   min: 4    (left most is the top most)
    //   1<2
    // add 5:
    //   max: 3
    //   min: 4,5    (left most is the top most)
    // add 6:
    //   max: 4,3
    //   min: ,5,6   (left most is the top most)
    
      
      
    
    double findMedian() {
        if((min.size())==(max.size())){
             return ((max.top()+min.top())/2.0);
        }

        return min.top();
    }
    //1,2,3,4,5
    //1,2,3,4,5,6
};
