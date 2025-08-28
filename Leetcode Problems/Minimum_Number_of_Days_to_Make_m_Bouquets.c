int numberOfBouquets(int* bloomDay, int bloomDaySize, int day, int k){
    int count = 0, result = 0;
    for(int i=0;i<bloomDaySize;i++){
        if(bloomDay[i] <= day){
            count++;
        }
        else{
            count = 0;
        }
        if(count == k){
            result++;
            count = 0;
        }
    }
    return result;

}

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    int ans = -1, min = bloomDay[0], max = bloomDay[0], mid;
    for (int i = 1; i < bloomDaySize; i++) {
        if(bloomDay[i] > max) max = bloomDay[i];
        if(bloomDay[i] < min) min = bloomDay[i];
    }
    while(min <= max){
        mid = min + (max-min)/2;
        if(numberOfBouquets(bloomDay, bloomDaySize, mid, k) >= m){
            ans = mid;
            max = mid-1;
        }
        else{
            min = mid+1;
        }
    }
    return ans;
}