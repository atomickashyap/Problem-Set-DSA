void rotate_arr(int *arr,int left,int right)
{
    while(left<right)
    {
        arr[left] = arr[left] ^ arr[right];
        arr[right] = arr[left] ^ arr[right];
        arr[left] = arr[left] ^ arr[right];
        left++;
        right--;
    }
}

void rotate(int *nums, int numsSize, int k){
     k = k % numsSize;
    rotate_arr(nums,0,numsSize-k-1);
    rotate_arr(nums,numsSize-k,numsSize-1);
    rotate_arr(nums,0,numsSize-1);
}