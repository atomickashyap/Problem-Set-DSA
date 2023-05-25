void reverse(int * arr, int left ,int right)
{
    while(left < right)
    {
        arr[left] = arr[left] ^ arr[right];
        arr[right] = arr[left] ^ arr[right];
        arr[left] = arr[left] ^ arr[right];
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k){
    k = k%numsSize;
    int start  = 0; // starting index
    int end = numsSize -1; // end index
    reverse(nums, start, end-k);
    reverse(nums,end-k+1, end);
    reverse (nums,start,end);
}