class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(int i:hand){
            mp[i]++;
        }
        for(auto i=mp.begin();i!=mp.end();){
            if(i->second>0){
                for(int j=0;j<groupSize;j++){
                    if(mp[i->first+j]>0){
                        mp[i->first+j]--;
                    }else{
                        return false;
                    }
                }
            }else{
                i++;
            }
        }
        return true;
    }
};
