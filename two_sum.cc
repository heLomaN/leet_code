class Solution
{
public:
  vector < int >twoSum (vector < int >&numbers, int target)
  {
    vector < int >result;
      unordered_map < int, int >index;
    for (int i = 0; i < numbers.size (); i++)
      {
	index[numbers[i]] = i;
      }

    for (int i = 0; i < numbers.size (); i +)
      {
	if (index.count (target - numbers[i])
	    && i != index[target - numbers[i]])
	  {
	    result.push_back (i+1);
	    result.push_back (index[target - numbers[i]]+1);
	    break;
	  }
      }
    return result;


  }
};
