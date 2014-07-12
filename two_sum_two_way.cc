class Solution
{
public:
  vector < int >twoSum (vector < int >&numbers, int target)
  {
    vector<int> num = numbers;
    sort(num.begin(),num.end());
    int p = 1,q = num.size()-1;
    while(p < q){
        if(num[p] + num[q] > target)
            --q;
        else if(num[p]+num[q] < target)
            ++p;
    }
    if(num[p]+num[q] == target)
        throw new exception();

    int left = find(numbers.begin(),numbers.end(),num[p]) - numbers.begin();
    int right = find(numbers.begin(),numbers.end(),num[q]) - numbers.begin();
    vector<int> result;
    result.push_back(left+1);
    result.push_back(right+1);
    return result;

            
  }
};
