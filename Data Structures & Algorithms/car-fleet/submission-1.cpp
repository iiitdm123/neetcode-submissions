class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> time;
        int n = position.size();
        vector<pair<int, int>> sorted_by_position;
        for(int i=0;i<n;i++) {
            sorted_by_position.push_back({position[i], speed[i]});
        }
        sort(sorted_by_position.begin(), sorted_by_position.end());
        for (int i = 0; i < n; i++) {
            float current_time = (float)(target - sorted_by_position[i].first) / sorted_by_position[i].second;
            // cout << current_time << endl;
            if (i == 0) {
                time.push(current_time);
            }
            else if (current_time >= time.top()) {
                while(!time.empty() && current_time >= time.top()) {
                    time.pop();
                }
                time.push(current_time);
            } else {
                time.push(current_time);
            }
        }
        return time.size();
    }
};
