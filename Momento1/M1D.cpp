class Solution {
public:

    void search(string airport, vector<string> &itinerary, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &map) {
        while (!map[airport].empty()) {
            string top = map[airport].top();
            map[airport].pop();
            search(top, itinerary, map);
        }
        itinerary.insert(itinerary.begin(),airport);
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {

        vector<string> itinerary;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;

        for(int i = 0; i < tickets.size(); i++) {
            map[tickets[i].first].push(tickets[i].second);
        }

        search("JFK", itinerary, map);
        return itinerary;
    }
};
