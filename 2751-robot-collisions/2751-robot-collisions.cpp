class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // {position, index}
        vector<pair<int,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }

        // sort by position
        sort(robots.begin(), robots.end());

        // stack will store indices of robots
        stack<int> st;

        for(auto &it : robots) {
            int i = it.second;

            if(directions[i] == 'R') {
                st.push(i);
            }
            else { // 'L'
                while(!st.empty() && healths[i] > 0) {
                    int j = st.top();

                    if(healths[j] < healths[i]) {
                        healths[j] = 0;
                        st.pop();
                        healths[i]--;
                    }
                    else if(healths[j] > healths[i]) {
                        healths[i] = 0;
                        healths[j]--;
                        break;
                    }
                    else {
                        healths[i] = 0;
                        healths[j] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> h;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) {
                h.push_back(healths[i]);
            }
        }

        return h;
    }
};