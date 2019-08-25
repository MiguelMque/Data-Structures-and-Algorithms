#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <ctype.h>
#include <sstream>
using namespace std;




int polishNotationCalculator(string str){

	stack <int> n;
	bool wasN;
	string num = "";

	/*for(int i = 0; i < str.size(); i++){

		if(str.at(i) == ' ' && wasN){
			stringstream g(num);
			int value;
			g >> value;
			n.push(value);
			num = "";
			wasN = false;
		} else if (isdigit(str.at(i))) {
		       	
			wasN = true;
			num += str.at(i);
                
		} else if (str.at(i)!=' '){


			op.push(str.at(i));

		}
	
	}*/


	for(int i = 0; i < str.size(); i++){


		 if(str.at(i) == ' ' && wasN){
                        stringstream g(num);
                        int value;
                        g >> value;
                        n.push(value);
                        num = "";
                        wasN = false;
                } else if (isdigit(str.at(i))) {
                        
                        wasN = true;
                        num += str.at(i);
                
                } else if (str.at(i)!=' '){
		 		int r = 0;
                                int b = n.top();
                                n.pop();
                                int a = n.top();
                                n.pop();

                	switch(str.at(i)){

				case '*':
					r = a*b;
					n.push(r);
					break;

				case '+':
					r = a+b;
					n.push(r);
					break;

				case '-':
					r = a-b;
					n.push(r);
					break;
					
				case '/':
					r = a/b;
					n.push(r);
					break;

			}
                
                }



	}

		


	return n.top();

}








int main(){



	cout <<	polishNotationCalculator("6 5 - 4 +");	


	return 0;

}
