class Solution {
public:
    string reorderSpaces(string text) {
        vector<string>words;
        string word;
        int space=0;
        // for(auto ch:text){
        //     if(ch==' '){
        //         space++;
        //     }
        // }
        // for(int i=0;i<text.size();i++){
        //     if(text[i]!=' '  && (i==0 || text[i-1]==' ')){
        //         words++;
        //     }
        // }
        for(auto ch:text){
            if(ch==' '){
                space++;
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
            }
            else{
                word+=ch;
            }
        }
        if (!word.empty()) words.push_back(word);
     int n=words.size();
     if(n==1){
        string res=words[0];
        for(int i=0;i<space;i++){
            res+=' ';
        }
        return res;
     }
       int mids=space/(n-1);
       int es=space%(n-1);
       string gap="";
       for(int i=0;i<mids;i++){
        gap+=" ";
       }
       string res="";
     
       for(int i=0;i<n;i++){
        res+=words[i];
        if(i<n-1){
            res+=gap;
        }
       }
       for(int i=0;i<es;i++){
        res+=' ';
       }

return res;
    }
};