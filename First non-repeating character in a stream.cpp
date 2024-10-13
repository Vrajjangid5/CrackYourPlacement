	string FirstNonRepeating(string s){
		    vector<int> freq(26);
		    queue<char>q;
		    string ans="";
		    for(int i=0;i<s.size();i++){
		        char ch=s[i];
		        freq[ch-'a']++;
		        q.push(ch);
		        while(!q.empty()){
		            if(freq[q.front()-'a']>1){
		                q.pop();
		            }else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}
