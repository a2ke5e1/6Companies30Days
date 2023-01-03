class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        int bulls=0;
        int cows=0;
        vector<int> x(10,0);
        vector<int> y(10,0);

        for(int i = 0;i < secret.size(); i++)
        {
            if  ( secret[i]==guess[i] ) {
                bulls++;
            }
            else {
                x[guess[i]-'0']++;
                y[secret[i]-'0']++;
            }
        }
        for(int i=0; i < 10 ;i++){
            if( (x[i]!=0) && (y[i]!=0) ) {
                cows += min(x[i],y[i]);
            }
        }
        ans += to_string(bulls);
        ans += "A";  
        ans += to_string(cows);
        ans += "B";

        return ans;
    }
};