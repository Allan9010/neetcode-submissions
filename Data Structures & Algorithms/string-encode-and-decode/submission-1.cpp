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
            string number_string = {""};
            while(s[i] != '*'){
                number_string += s[i];
                ++i;
            }
            int number = std::stoi(number_string);
            string str = "";
            for(int j = i + 1; j < i + 1 + number; ++j){
                str += s[j];
            }
            decode_string.push_back(str);
            i = i + 1 + number;
        }

        return decode_string;
    }
};
