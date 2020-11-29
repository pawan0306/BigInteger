
string gcd(string, string);
string gcd_util(string, string);
string divide(string, string);
string bin_div(string, string);
string fast_expo(string, long long);
string multiply(string, string);
string to_decimal(string);
string multiply_util(string, long);
string factorial(int);
string addition(string, string);
bool bin_comp(string, string);
bool comp(string, string);
string subtraction(string, string);
string to_binary(string);
bool is_zero(string);
string bin_subtraction(string, string);


string bin_subtraction(string str1,string str2){
    string res="";
    int len1=str1.length()-1,len2=str2.length()-1;
    int carry=0;
    int len=min(len1,len2);
    for(int i=0;i<=len;i++){
        if(str1[len1]<str2[len2]||(str1[len1]==str2[len2]&&carry==1)){
            res=(char)((str1[len1--]-str2[len2--]+2-carry)+48)+res;
            carry=1;
        }
        else {
            res=(char)((str1[len1--]-str2[len2--]-carry)+48)+res;
            carry=0;
        }
    }
    while(len1>=0){
        int val=str1[len1]-48-carry;
        if(val<0){
            res=(char)(val+2+48)+res;
            carry=1;
        }
        else{
            res=(char)(val+48)+res;
            carry=0;
        }
        len1--;
    }
    int count=0;
    if(res[0]=='0'){
        int i=0;
        while(res[i++]=='0')count++;
    }
    res=res.substr(count,res.length()-count);
    if(res=="")return "0";
    return res;
}
bool is_zero(string str){
    for(int i=0;i<str.length();i++)
        if(str[i]!='0')return false;
    return true;
}
string to_binary(string str){
    string bin="";
    int carry=0;
    string res="";
    int len=str.length()-1,val;
    do{
        carry=0;
        for(int i=0;i<=len;i++){
            val=((str[i]-48)+10*carry);
            carry=val%2;
            res=res+(char)(val/2+48);
        }
        if(res[0]=='0')res=res.substr(1,res.length()-1);
        str=res;
        len=str.length()-1;
        bin=(char)(carry+48)+bin;
        res="";
    }while(str.length());
    return bin;
}
string subtraction(string str1,string str2){
    string res="";
    int len1=str1.length()-1,len2=str2.length()-1;
    int carry=0;
    int len=min(len1,len2);
    for(int i=0;i<=len;i++){
        if(str1[len1]<str2[len2]||(str1[len1]==str2[len2]&&carry==1)){
            res=(char)((str1[len1--]-str2[len2--]+10-carry)+48)+res;
            carry=1;
        }
        else {
            res=(char)((str1[len1--]-str2[len2--]-carry)+48)+res;
            carry=0;
        }
    }
    while(len1>=0){
        int val=str1[len1]-48-carry;
        if(val<0){
            res=(char)(val+10+48)+res;
            carry=1;
        }
        else{
            res=(char)(val+48)+res;
            carry=0;
        }
        len1--;
    }
    int count=0;
    if(res[0]=='0'){
        int i=0;
        while(res[i++]=='0')count++;
    }
    res=res.substr(count,res.length()-count);
    return res;

}
bool comp(string str1,string str2){
    int len1=str1.length();
    int len2=str2.length();
    if(len1!=len2){
        if(len1>len2)
            return true;
        else return false;
    }
    else{
        for(int i=0;i<len1;i++){
            if(str1[i]==str2[i])continue;
            else if(str1[i]>str2[i])return true;
            else return false;
        }
        return false;
    }
}
bool bin_comp(string str1,string str2){
    int count=0;
    if(str1[0]=='0'){
        int i=0;
        while(str1[i++]=='0')count++;
    }
    str1=str1.substr(count,str1.length()-count);
    if(str1=="")return false;
    int len1=str1.length();
    int len2=str2.length();
    if(len1!=len2){
        if(len1>len2)
            return true;
        else return false;
    }
    else{
        for(int i=0;i<len1;i++){
            if(str1[i]==str2[i])continue;
            else if(str1[i]>str2[i])return true;
            else return false;
        }
        return true;
    }
}
string addition(string str1, string str2){
    string res="";
    int len1=str1.length()-1,len2=str2.length()-1;
    int len=min(len1,len2);
    int carry=0,val;
    for(int i=0;i<=len;i++){
        val=(str1[len1--]-48)+(str2[len2--]-48)+carry;
        carry=val/10;
        val=val%10;
        res=(char)(val+48)+res;
    }
    if(str1.length()>str2.length()){
        for(int i=len1;i>=0;i--){
            val=(str1[i]-48)+carry;
            carry=val/10;
            val=val%10;
            res=(char)(val+48)+res;
        }
    }
    else{
        for(int i=len2;i>=0;i--){
            val=(str2[i]-48)+carry;
            carry=val/10;
            val=val%10;
            res=(char)(val+48)+res;
        }
    }
    if(carry)res=(char)(carry+48)+res;
    return res;
    
}   
string factorial(int n){
    string res=to_string(1),res2;
    int carry=0,val;
    for(int i=2;i<=n;i++){
        int len=res.length(); 
        res2="";
        carry=0;
        for(int j=len-1;j>=0;j--){
            val=(res[j]-48)*i+carry;
            carry=val/10;
            val=val%10;
            res2=(char)(val+48)+res2;
        }
        if(carry) res2=to_string(carry)+res2;
        res=res2;
    }
    return res;
}
string multiply_util(string str, long m){
    string res="";
    string mul;
    long carry=0,val;
    int len=str.length()-1;
    for(int i=len;i>=0;i--){
        val=(str[i]-48)*m+carry;
        carry=val/10;
        val=val%10;
        res=(char)(val+48)+res;
    }
    if(carry)res=(char)(carry+48)+res;
    return res;
}
string to_decimal(string str){
    string res="0",temp="1";
    int len=str.length()-1;
    if(str[len]=='1')res="1";
    for(int i=len-1;i>=0;i--){
        temp=multiply_util(temp,2);
        if(str[i]=='1')res=addition(res,temp);
    }
    return res;
}    
string multiply(string str1, string str2){
    string res="0";
    string cu="";
    int len1=str1.length()-1;
    int len2=str2.length()-1;
    int len_res=res.length();
    int point=0;
    int val,carry=0;
    for(int i=len2;i>=0;i--){
        carry=0;
        cu="";
        for(int j=len1;j>=0;j--){
            val=(str1[j]-48)*(str2[i]-48)+carry;
            carry=val/10;
            val=val%10;
            cu=(char)(val+48)+cu;
        }
        if(carry)cu=(char)(carry+48)+cu;
        res=addition(cu,res.substr(0,len_res-point))+res.substr(len_res-point,point);
        point++;
        len_res=res.length();
    }
    return res;
}
string fast_expo(string str,long long n){
    if(n==1)return str;
    if(n%2==0){
        string res=fast_expo(str,n/2);
        return multiply(res,res);
    }
    else{
        string res=fast_expo(str,n-1);
        return multiply(res,str);
    }
}
string bin_div(string dvnd,string dvsr){
    if(comp(dvsr,dvnd))return dvnd;
    string res="";
    int len1=dvnd.length();
    int len2=dvsr.length();
    bool q=1;
    int i=len2;
    res=dvnd.substr(0,dvsr.length());
    while(q){
        if(bin_comp(res,dvsr)){
            res=bin_subtraction(res,dvsr);
        }
        else{
            if(i<len1){
                
                while(!bin_comp(res,dvsr)&&i<len1)
                res+=dvnd[i++];
                if(!bin_comp(res,dvsr))break;
                res=bin_subtraction(res,dvsr);
            }
            else q=0;
        }
    }
    int count=0;
    if(res[0]=='0'){
        int i=0;
        while(res[i++]=='0')count++;
        res=res.substr(count,res.length()-count);
    }
    if(res=="")return "0";
    return res;
}
string divide(string dvnd,string dvsr){
    return to_decimal(bin_div(dvnd,dvsr));
}
string gcd_util(string a,string b){
    if(a=="0")return b;
    if(b=="0")return a;
    return gcd_util(b,bin_div(a,b));
}
string gcd(string str1,string str2){
    string a=to_binary(str1);
    string b=to_binary(str2);
    string res=gcd_util(a,b);
    res=to_decimal(res);
    return res;
}
