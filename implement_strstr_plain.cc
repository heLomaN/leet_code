class Solution
{
public:
  char *strStr (char *haystack, char *needle)
  {
        char *p = haystack;
        int lh = strlen(haystack);
        int ln = strlen(needle);

        if(ln ==0)
            return p;
        for(int i = 0;i < lh-ln+1;i++){
            int j = 0;
            for(;j < ln && haystack[i+j] == needle[j];j++){
                ;
            }
            if(j == ln-1){
                p = haystack+i;
                return p;
            }
        }
        return NULL;
                
  }
};
