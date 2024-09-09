//time: O(2^n)
//space: O(n)
class Solution {
    bool isValid(string s) {
        int open = 0;
        for(char c : s) {
            if(c == '(') {
                open++;
            }
            else if(c == ')') {
                open--;
                if(open < 0) return false;
            }
        }
        return open == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        bool flag = true;
        for(char c : s) {
            if(c == '(' || c == ')') {
                flag = false;
                break;
            }
        }
        if(flag || isValid(s)) return {s};
        queue<string> q;
        q.push(s);
        vector<string> result;
        unordered_set<string> uset;
        uset.insert(s);
        while(!q.empty() && !flag) {
            int size = q.size();
            for(int k = 0; k < size; k++) {    
                string curr = q.front();
                //cout<<curr<<endl;
                q.pop();
                for(int i = 0; i < curr.length(); i++) {
                    if(curr[i] < 'a' || curr[i] > 'z') {
                        string child = curr.substr(0, i) + curr.substr(i+1);
                        //if(uset.find(child) != uset.end()) {
                            //cout<<child<<endl;
                            if(isValid(child)) {
                                if(uset.find(child) == uset.end()) result.push_back(child);
                                flag = true;
                            }
                            else {
                                if(uset.find(child) == uset.end()) q.push(child);
                            }
                            uset.insert(child);
                        //}
                    }
                }
            }
        }
        return result;
    }
};