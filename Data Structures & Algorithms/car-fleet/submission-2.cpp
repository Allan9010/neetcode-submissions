class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); ++i){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        int fleet = 0;
        double maxtime = 0.0;
        for(int i = position.size() - 1; i >= 0; --i){
            if( ((target - cars[i].first) * 1.0 / cars[i].second) > maxtime){
                maxtime = (target - cars[i].first) * 1.0 / cars[i].second;
                fleet++;
            }
        }

        
        return fleet;
    }
};
