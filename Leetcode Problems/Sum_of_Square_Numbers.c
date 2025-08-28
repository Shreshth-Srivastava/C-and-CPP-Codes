bool judgeSquareSum(int c) {
    long long start = 0, end = (int)sqrt((double)c);
    while(start <= end){
        if( (start*start + end*end) > c ){
            end--;
        }
        if( (start*start + end*end) < c ){
            start++;
        }
        if( (start*start + end*end) == c ){
            return true;
        }
    }
    return false;
}