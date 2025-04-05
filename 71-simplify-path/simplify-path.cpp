class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string ans ="";
        string temp;
        stack<string> s;
        while(getline(ss,temp,'/')){
            
            if(temp =="." || temp=="") continue;
            else if(temp==".."){
              if(!s.empty()) s.pop();
            }
            else{
                s.push(temp);
            }
        }
        while(!s.empty()){
            
        ans = "/" + s.top() + ans;
        s.pop();
        }
        if(ans=="") return "/";
        return ans;
        
    }
};