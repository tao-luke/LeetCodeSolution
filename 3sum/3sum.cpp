class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result{};
        short size = nums.size();
        sort(nums.begin(),nums.end());
        for(short i = 0; i <size;i++){
            if (i > 0 && nums[i] == nums[i-1])continue; //dup n1
            short j = i+1;
            short k = size-1;
            while(j < k){
                if (nums[j]+nums[k] == -nums[i]){
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    while(j < k && nums[k] == nums[k-1])k--;
                    while(j < k && nums[j]  == nums[j+1])j++;
                    k--;j++;
                } 
                else if (nums[j]+nums[k] < -nums[i]) j++;
                else k--;
            }
        }
        return result;
    }
    void heapSort(vector<int>& nums){
        heapify(nums);
        for(short i = nums.size()-1;i >=0;i--){
            swap(nums[0],nums[i]);
            fix_down(nums,0,i);
        }
    }
    short parent(short i){
        return (i-1)/2;
    }
    short leftChild(short i){
        return 2*i+1;
    }
    short rightChild(short i){
        return 2*i+2;
    }
    void fix_down(vector<int>& nums, short i,short size){
        while(leftChild(i) < size){//while i is not last layer
            if (rightChild(i) < size && nums[rightChild(i)] > nums[leftChild(i)]){
                //if yes right child, and right > left
                if (nums[i] < nums[rightChild(i)]){
                    swap(nums[i],nums[rightChild(i)]);
                    i = rightChild(i);
                }else return;
            }
            else if (nums[i] < nums[leftChild(i)]){
                swap(nums[i],nums[leftChild(i)]);
                i = leftChild(i);
            }else return;
        }
    }
    void heapify(vector<int>& nums){
        short size = nums.size();
        for(short i = parent(size-1);i >=0;i--){
            fix_down(nums,i,size);
        }
    }
};