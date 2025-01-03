class Solution {
public:
//here comparison is done at each segment if values equal continue else return whichever greater
    int compareVersion(string version1, string version2) {
        int v1=0;
        int v2=0;
        int i=0;
        int j=0;
        while(i<version1.size()||j<version2.size())
        {
          while(i<version1.size() && version1[i]!='.')
          {
            v1 = v1*10+(version1[i]-'0');
            i++;
          }
          i++; //skipping '.' 
          while(j<version2.size() && version2[j]!='.')
          {
            v2 = v2*10+(version2[j]-'0');
            j++;
          }
          j++;
          if(v1>v2) return 1;
          if (v2>v1) return -1;
          v1=0;
          v2=0;
           
        }
          return 0; 
        }
      
       
};