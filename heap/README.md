
leetcode 480 超时
```c++
class Solution {
    class CusWD
    {
        multiset<int> ms;
        int max;
    public:
        CusWD(int k):max(k){}

        void pop(int value)
        {
            if(!ms.empty())
            {
                auto it = ms.find(value);
                if(it != ms.end())
                {
                    // cout<<"pop "<<value<<endl;
                    ms.erase(it);
                }
            }
        }

        void push(int value)
        {
            // cout<<"push "<<value<<endl;
            ms.insert(value);
        }

        double median()
        {
            if(!ms.empty())
            {
                int half = max & 1 ? max / 2 : max / 2 - 1;

                auto it = ms.begin();
                for(int i = 0; i < half; ++i)
                {
                    ++it;
                }
                if(max & 1)
                {
                    return *(it);
                }
                else
                {
                    return ((long)*(it) + (long)*(++it))/2.0;
                }
            }
            return 0;
        }
    };

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        CusWD wd(k);
        for(int i = 0; i < k; ++i)
        {
            wd.push(nums[i]);
        }

        ans.push_back(wd.median());
        for(int i = k; i < nums.size(); ++i)
        {
            wd.pop(nums[i-k]);
            wd.push(nums[i]);
            ans.push_back(wd.median());
        }

        return ans;
    }
};
```

k=321时报错

```c++
class Solution {

    class CusDW
    {
    public:
        priority_queue<int> low; //max-heap
        priority_queue<int, vector<int>, greater<int>> high; //min-heap
        unordered_map<int, int> hash;
        int max;
        long int lowCount = 0;
        long int highCount = 0;
        int bias = 0;

        void balance()
        {
            if (lowCount - bias > highCount)
            {
                if(!low.empty())
                {
                int tmp = low.top();
                low.pop();
                --lowCount;
                high.push(tmp);
                ++highCount;
                }
            }
            else if (lowCount - bias < highCount)
            {
                if(!high.empty())
                {
                int tmp = high.top();
                high.pop();
                --highCount;
                low.push(tmp);
                ++lowCount;
                }
            }
        }


        CusDW(int k):max(k){
            bias = k & 1 ? 1 : 0;
        }

        void pop(int value)
        {
            hash[value]++;
            if(!low.empty() && value <= low.top())
            {
                --lowCount;
            }
            else
            {
                --highCount;
            }

            while (!low.empty() && hash[low.top()] > 0)
            {
                --hash[low.top()];
                low.pop();
            }

            while (!high.empty() && hash[high.top()] > 0)
            {
                --hash[high.top()];
                high.pop();
            }
        }

        void push(int value)
        {
            if (low.empty())
            {
                if(high.empty() || value <= high.top())
                {
                    low.push(value);
                    ++lowCount;
                }
                else
                {
                    // while (high.empty() || value <= high.top())
                    {
                        int tmp = high.top();
                        high.pop();
                        low.push(tmp);
                        --highCount;
                        ++lowCount;
                    }

                    if (value <= low.top())
                    {
                    low.push(value);
                    ++lowCount;
                    }
                    else
                    {
                    high.push(value);
                    ++highCount;
                    }

                }
            }
            else if (!low.empty() && value <= low.top())
            {
                low.push(value);
                ++lowCount;
            }
            else
            {
                high.push(value);
                ++highCount;
            }

            balance();
        }
        
        double get_median()
        {
            if(max & 1)
            {
                return low.top();
            }
            else
            {
                return ((long)low.top() + (long)high.top()) / 2.0;
            }
        }
    };

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        ans.reserve(nums.size() - k + 1);
        CusDW dw(k);
        for (int i = 0; i < k; ++i)
        {
            dw.push(nums[i]);
        }

        ans.push_back(dw.get_median());

        for (int i = k; i <nums.size(); ++i)
        {
            // cout << "low: "<<endl;
            // auto lowTmp = dw.low;
            // auto lowSize = lowTmp.size();
            // for (int i = 0; i < lowSize; ++i)
            // {
            //     cout << lowTmp.top() << " ";
            //     lowTmp.pop();
            // }
            // cout << endl;

            // cout << "high: "<<endl;
            // auto highTmp = dw.high;
            // auto highSize = highTmp.size();
            // for (int i = 0; i < highSize; ++i)
            // {
            //     cout << highTmp.top() << " ";
            //     highTmp.pop();
            // }
            // cout << endl;
            // cout << endl;
            dw.pop(nums[i-k]);
            dw.push(nums[i]);
            ans.push_back(dw.get_median());
        }
        return ans;
    }
};
```

正确版本  
其实只有四种情况：
1. 小堆加入`nums[i]`，小堆删除`nums[i-k]`
2. 小堆加入`nums[i]`，大堆删除`nums[i-k]`
3. 大堆加入`nums[i]`，大堆删除`nums[i-k]`
4. 大堆加入`nums[i]`，大堆删除`nums[i-k]`
所以`balance`只有-2，0，2。
每次要先删除再加入。

```c++
class Solution {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    unordered_map<int, int> hash;

    double cal_ans(int k)
    {
        if(k & 1)
        {
            return small.top();
        }
        else
        {
            return ((double)(small.top() + (double)big.top())*0.5);
        }
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        ans.reserve(nums.size() - k + 1);
        for (int i = 0; i < k; ++i)
        {
            small.push(nums[i]);
        }

        for (int i = 0; i < k/ 2; ++i)
        {
            big.push(small.top());
            small.pop();
        }

        ans.push_back(cal_ans(k));

        for (int i = k; i < nums.size(); ++i)
        {
            int balance = 0;

            // 第一步：先看需要删除的元素在哪个堆中
            hash[nums[i-k]]++;

            if (!small.empty() && nums[i-k] <= small.top())
            {
                balance++;
            }
            else
            {
                balance--;
            }

            // 第二步：看加入的元素应该放在哪个堆中
            if (!small.empty() && nums[i] <= small.top())
            {
                small.push(nums[i]);
                balance--;
            }
            else
            {
                big.push(nums[i]);
                balance++;
            }

            // 第三步：调整
            if(balance < 0)
            {
                big.push(small.top());
                small.pop();
            }
            else if (balance > 0)
            {
                small.push(big.top());
                big.pop();
            }

            // 第四步：删除需要删除的元素，注意每次top的时候要先判断empty
            // 为什么要先删除数字较小的堆？
            while(!small.empty() && hash[small.top()])
            {
                hash[small.top()]--;
                small.pop();
            }
            while(!big.empty() && hash[big.top()])
            {
                hash[big.top()]--;
                big.pop();
            }

            ans.push_back(cal_ans(k));
        }
        return ans;
    }
};
```