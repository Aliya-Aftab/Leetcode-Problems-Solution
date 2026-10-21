class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>st(wordList.begin(), wordList.end());
       if(st.find(endWord) == st.end()){
        return 0;
       } 
       queue<pair<string, int>>q;
       q.push({beginWord, 1});
       while(!q.empty()){
        string word = q.front().first;
        int count = q.front().second;
        if(word == endWord){
             return count;
        }
        q.pop();
        for(int i = 0; i < word.length(); i++){
            char original = word[i];
            for(char j = 'a'; j <= 'z'; j++){
                word[i] = j;
                if(st.find(word) != st.end()){
                    q.push({word, count+1});
                    st.erase(word);
                }
            }
            word[i] = original;
        }
       }
       return 0;
    }
};
// hit, 1 => hot, 2 => dot, 3 => lot, 4, dog, 4 => log, 5.=> 