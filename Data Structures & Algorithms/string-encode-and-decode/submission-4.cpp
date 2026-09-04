class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_string = "";
        for(auto str : strs){
            string number = to_string(str.size() );
            encode_string = encode_string + number + "*" + str;
        }
        return encode_string;
    }

    vector<string> decode(string s) {
        vector<string> decode_string;
        for(int i = 0; i < s.size(); ){
            int star_pos = s.find('*', i);
            int number = std::stoi(s.substr(i, star_pos - i));

            // s.substr(起始位置, 擷取長度)
            string str = s.substr(star_pos + 1, number);
            decode_string.push_back(str);
            i = star_pos + 1 + number;
        }

        return decode_string;
    }
};
