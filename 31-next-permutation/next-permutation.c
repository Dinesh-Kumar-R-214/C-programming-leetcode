void nextPermutation(int* nums, int numsSize){
    if(numsSize <= 1) return;

    int i = numsSize - 2;
    while(i >= 0 && nums[i] >= nums[i+1]) i--;

    if(i >= 0){
        int j = numsSize - 1;
        while(nums[j] <= nums[i]) j--;
        // Swap nums[i] and nums[j]
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Reverse nums[i+1..numsSize-1]
    int left = i + 1, right = numsSize - 1;
    while(left < right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}
