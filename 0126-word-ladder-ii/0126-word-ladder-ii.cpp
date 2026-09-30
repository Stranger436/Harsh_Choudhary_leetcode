class Solution {
public:

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {

        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto par : parent[word]) {
            path.push_back(par);

            dfs(par, beginWord, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        // endWord must be present
        if (st.find(endWord) == st.end())
            return {};

        queue<string> q;
        q.push(beginWord);

        // distance of every word from beginWord
        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        int shortestDistance = -1;

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int currDist = dist[word];

            // No need to explore beyond shortest distance
            if (shortestDistance != -1 &&
                currDist >= shortestDistance)
                continue;

            string temp = word;

            // Change every character
            for (int i = 0; i < temp.size(); i++) {

                char original = temp[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    // valid word
                    if (st.find(temp) == st.end())
                        continue;

                    // First time seeing this word
                    if (dist.find(temp) == dist.end()) {

                        dist[temp] = currDist + 1;

                        parent[temp].push_back(word);

                        q.push(temp);

                        if (temp == endWord)
                            shortestDistance = currDist + 1;
                    }

                    // Another shortest parent
                    else if (dist[temp] == currDist + 1) {

                        parent[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        // endWord was never reached
        if (dist.find(endWord) == dist.end())
            return {};

        // Generate all shortest paths
        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};