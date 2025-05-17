/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* path;
int pathTop;
int** ans;
int ansTop;
int cnt[8];//标记path中是否已有此索引值，这也是同46题不同点
void backTracking(int* nums,int numsSize,int startIndex,int** returnColumnSizes){
    if(pathTop==numsSize){
        (*returnColumnSizes)[ansTop] = pathTop;
        ans[ansTop] = (int*)malloc(sizeof(int)*pathTop);
        for(int i = 0;i<pathTop;i++){//装入子集
            ans[ansTop][i] = path[i];
        }
        ansTop++;
        return;
    }
    int cnt_1[21];//同一层相同元素只能读一次
    memset(cnt_1,0,sizeof(cnt_1));
    //递归组合
    for(int i = startIndex;i<numsSize;i++){
        if(cnt[i]||cnt_1[nums[i]+10]) continue;//此索引本轮已访问过或此值在此层已访问过
        path[pathTop++] = nums[i];
        cnt[i] = 1;//本组合相应索引位置已访问
        cnt_1[nums[i]+10] = 1;//本层相同元素已访问
        backTracking(nums,numsSize,0,returnColumnSizes);
        cnt[i] = 0;//退出路径则解除标记
        pathTop--;
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    memset(cnt,0,sizeof(cnt));
    path = (int*)malloc(sizeof(int)*8);//开到最大
    ans = (int**)malloc(sizeof(int*)*10000);
    *returnColumnSizes = (int*)malloc(sizeof(int)*10000);
    pathTop = 0;
    ansTop = 0;
    //从0开始递归
    backTracking(nums,numsSize,0,returnColumnSizes);
    *returnSize = ansTop;
    free(path);
    return ans;
}
