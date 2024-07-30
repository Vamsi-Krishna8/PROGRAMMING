// Approach 1
// TC O(n) SC O(n)

class Solution {
public:
  string help(string &s, string &match) {
    stack<char> st;
    for (char &x : s) {
      if (x == match[1] && !st.empty() && st.top() == match[0])
        st.pop();
      else
        st.push(x);
    }
    string temp;
    while (!st.empty()) {
      temp.push_back(st.top());
      st.pop();
    }
    reverse(temp.begin(), temp.end());
    return temp;
  }
  int maximumGain(string s, int x, int y) {
    int n = s.size();
    int ans = 0;
    string maxi = (x > y) ? "ab" : "ba";
    string mini = (x < y) ? "ab" : "ba";

    // first time

    string temp1 = help(s, maxi);
    int len = n - temp1.length();
    ans += (len / 2) * max(x, y);

    string temp2 = help(temp1, mini);
    ans += ((temp1.length() - temp2.length()) / 2) * min(x, y);

    return ans;
  }
};

// Approach 2
// TC => O(n) SC=>O(1);

class Solution {
public:
  string help(string &s, string &match) {
    int i = 0;
    for (int j = 0; j < s.length(); j++) {
      s[i] = s[j];
      i++;
      if (i >= 2 && s[i - 2] == match[0] && s[i - 1] == match[1])
        i -= 2;
    }
    s.erase(begin(s) + i, end(s));
    return s;
  }
  int maximumGain(string s, int x, int y) {
    int n = s.size();
    int ans = 0;
    string maxi = (x > y) ? "ab" : "ba";
    string mini = (x < y) ? "ab" : "ba";

    // first time
    string temp1 = help(s, maxi);
    int len = temp1.length();
    int removed = (n - len) / 2;
    ans += removed * max(x, y);

    // second time

    string temp2 = help(temp1, mini);
    removed = (len - temp2.length()) / 2;
    ans += removed * min(x, y);
    return ans;
  }
};