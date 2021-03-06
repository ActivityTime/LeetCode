/*
* 遍历一遍数组，对于每一个整数num[i]，把这个整数，在假设的顺序排列数组里的<b>索引</b>，也就是「num[i]-1」（注意，这是一个索引）做上标记，目的是和没有出现在数组里的整数的索引区分开来。

* 再遍历一遍（这个数组或者你自己新建的数组，后边会解释），根据标记，返回最终结果。

怎么做标记区分开出现的和没出现的整数？举两个例子。

1. 新建一个数组a，初始化为1，见到第一个数4，把a[3]改为0，见到3，把a[2]改为0，见到2把a[1]改为0，依次继续。突然，见到了第二个2出现了，这时候改不改都无所谓，因为a[2]已经是0了。<b>注意</b>，这个地方的数字本来应该是缺少的那一个，也就是我们寻找的结果，是几呢，5，所以他本来应该把a[4]改成0，但是现在没有改。
所以，再遍历一次你新建的a数组，哪个索引 i 对应的数值是 1 ，则 i+1 就是我们要找的那个未出现在数组里的整数（因为我们利用了顺序数组的性质进行的改值操作）。

2. 方法1自己开辟了一个数组a，能不能在原数组上改呢？能，改成原来值的负值是一个不错的选择，虽然我们根本不关心它的值为负还是为0，只是需要区分在其中的整数和不在其中的整数的区别罢了。但是在把当前数值转换成索引的时候会变动后边的数值，取负值可以用绝对值函数abs，不影响后边的变换。改成0就不行了。
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0 ; i < nums.size(); i++){
            int index = abs(nums[i])-1;
            if(nums[index]>0)
                nums[index] = -nums[index];
            }
        for(int j=0; j< nums.size(); j++){
            if(nums[j] > 0)
                res.push_back(j+1);
        }
        return res;
    }
};