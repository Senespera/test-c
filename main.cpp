#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
using namespace std;

string gen_random(const int len) {
    
    string tmp_s;
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
    
}

int main(int argc, char** argv) {
	int x, i, j, correct;
	string answer[5], a1, a2;
	bool jcheck[5];
	for(i=1;i<=5;i++) jcheck[i]=false;
	
	srand((unsigned) time(0));
	int result = 1 + (rand() % 1);//% 3
	cout << result << "\n";
	switch(result){
		case 1: a1=gen_random(3); srand((unsigned) time(0)); a2=gen_random(4);
	cout << "Enter a "<<a1<<" pointer for the "<<a2<<" structure " << "\n"; 
	correct=1 + (rand() % 4); answer[correct]="struct "+a2+" *"+a1;
	for (i=1; i<=4; i++) {
		if (i!=correct) 
			{do {j = 1 + (rand() % 3);} while (jcheck[j]=false);
			jcheck[j]=true; switch(j){
				case 1: answer[i]="struct *"+a2+" &"+a1;break;
				case 2: answer[i]="struct &"+a2+" *"+a1;break;
				case 3: answer[i]="struct "+a2+" &"+a1;break;
			}
			}};
	for (i=1;i<=4;i++) cout << i <<") " << answer[i] << "\n";
	cin >> x; if (x!=correct) cout << "Wrong" << "\n"; else cout << "Correct" << "\n";
			break;
	
		case 2: cout << "Question 2" <<"\n"; break;
		case 3: cout << "Question 3" <<"\n"; break;
		default: cout << "Error" << "\n"; break;
	}

	return 0;
}
