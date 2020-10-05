int decode(char**s){
    int ans;
    for(int i=0;i<4;i++){
        int cnt=0;
        for(int j=0;s[i][j]!='\0';j++){
            for(int k=0;s[4][k]!='\0';k++){
                if(s[i][k]==s[3][k]){
                    cnt++;
                    break;
                }
            }
        }
        ans=ans*10+cnt;
    }
    return ans;
}