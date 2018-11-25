//I have searched for \\n not "\n" (as line ending) because the example code showed so
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

unsigned int FindFunctionDefn( const char* strFunctionName, const char* strSourceCode ){
    ll lineNo=1;
    for(ll i=0;;++i){ 
        if(strSourceCode[i]=='\\' && strSourceCode[i+1]=='n'){ //I have searched for \\n not "\n" (as line ending) because the example code showed so
            if(strSourceCode[i+2]!='\0'){
                lineNo++;
            }
            else
                break;
        }
        else if(strSourceCode[i]==strFunctionName[0]){
            ll j=1;
            for(;strFunctionName[j]!='\0';++j){
                if(strSourceCode[i+j]!=strFunctionName[j]){
                    break;
                }
            }
            if(strFunctionName[j]=='\0'){
                int c=0;
                for(int k=i+1;strSourceCode[k]!='\0';++k){
                    if(c==0 && strSourceCode[k]==')'){
                        c=1;
                    }
                    else if(c==1){
                        if(strSourceCode[k]=='{'){
                            return lineNo;
                        }
                        else if(strSourceCode[k]==';'){
                            c=0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
         
    char strFunctionName[] = "func2"; 
    char strSourceCode[] = "int func1(){ return 0; }\\n int func2(){ return 1; }\\n" "int main(int argc, char*argv[]){ return func2(); }\\n";
    int l=FindFunctionDefn( strFunctionName, strSourceCode );
    cout<<l;
    
    return 0;
}
