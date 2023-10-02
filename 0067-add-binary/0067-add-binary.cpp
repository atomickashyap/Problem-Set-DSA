class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = size(a)-1;
        int len_b = size(b)-1;
        int carry = 0;
        string str = "";
        while(len_a>=0 && len_b>=0)
        {
            if((a[len_a] == '1') && (b[len_b] == '1'))
            {
                if(carry == 0)
                {
                    carry = 1;
                    str+='0';
                }
                else{
                    carry = 1;
                    str+='1';
                }
            }
            else if((a[len_a] == '0') && (b[len_b] == '0'))
            {
                    cout<<"a";
                if(carry == 0)
                    str+='0';
                else{
                    carry =0;
                    str+='1';
                }
            }
            else{
                if(carry==0 )
                {
                    
                    str+='1';
                }
                else{
                    carry = 1;
                    str+='0';
                }
            }
            len_a--,len_b--;
        }
        while(len_a>=0)
        {
            if(a[len_a] == '1')
            {
                if(carry == 0)
                {
                    carry = 0;
                    str+='1';
                }
                else{
                    carry = 1;
                    str+='0';
                }
            }
            else{
                if(carry == 0)
                {
                    carry = 0;
                    str+='0';
                }
                else{
                    carry = 0;
                    str+='1';
                }
            }
            len_a--;
        }
        while(len_b>=0)
        {
            if(b[len_b] == '1')
            {
                if(carry == 0)
                {
                    carry = 0;
                    str+='1';
                }
                else{
                    carry = 1;
                    str+='0';
                }
            }
            else{
                if(carry == 0)
                {
                    carry = 0;
                    str+='0';
                }
                else{
                    carry = 0;
                    str+='1';
                }
            }
            len_b--;
        }
        if(carry ==1)
            str+='1';
     reverse(str.begin(),str.end());
    return str;
    }
};