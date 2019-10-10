int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*' || c=='%'){
        return 2;
    }
   else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPostfix(string s){
    s='('+s+')';
    //cout<<s<<endl;
    string postfix="";
    stack<char> st;
    int len=s.length();
    for(int i=0;i<len;i++){
        //cout<<s[i]<<"  ";
        if(s[i]=='('){//opening bracket aya to push kar do stack me
            st.push(s[i]);
        }
        else if((s[i]>=97 && s[i]<=122)||(s[i]>=65 && s[i]<=90)){//if char then add it in postfix expression
            postfix=postfix+s[i];
        }
        else if(s[i]==')'){//if closing bracket then pop stack till we encounter ')' and also pop it out
            while(!st.empty() && st.top()!='('){
                 postfix=postfix+st.top();
                 st.pop();
            }
            st.pop();
        }
        else{//if we encounter an operator
        if(st.top()=='('){
            st.push(s[i]);
        }
        else{
             while(!st.empty() && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                postfix += c; 
            } 
            st.push(s[i]); 
        } 
        }
        /*if(!st.empty())
        cout<<st.top()<<"  ";
        cout<<postfix<<endl;*/
    }
    return postfix;
}

/*
5
(a+b)*(c+d)
(a-(b^c))+(d)
a+(b*c-(d/e^f)*g)*h
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D
*/
