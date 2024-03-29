#include<bits/stdc++.h>

using namespace std;


long int md5_int(string vetor){
	long int sum=0;
	for(int i=0;i<vetor.length();i++){
		sum += (int)vetor[i]*(int)vetor[i]*(int)vetor[i]*(int)vetor[i]*(int)vetor[i];
	}

	return sum%999999;
}


int main(int argc,char *argv[]){
  
  /* Variables */
  string user,user_test;
  string pswdSeed;
  string pswdLocal,pswdTest;
  string command;
  long int token=0;

  const char *c_command;
  char pswd_test[50],test_local[50],seed_hash[50],old_tokens[50];
  long int int_token[5];

  memset(pswd_test,'\0',sizeof(pswd_test));
  memset(seed_hash,'\0',sizeof(seed_hash));
  memset(test_local,'\0',sizeof(test_local));
  memset(old_tokens,'\0',sizeof(old_tokens));

  // Time
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int year,month,hour,day,min;

 	// Files
  FILE *seed = fopen("hash_seedPswd","r");
  FILE *local = fopen("hash_localPswd","r");
  FILE *test = fopen("hash_test","r");
  FILE *tokens = fopen("tokens","r");

  bool first = true;
  bool flag= false;

  while(true){
	  first = false;
	  
	  // User interaction
	  cout << "Username:";
	  cin >> user;
	  
	  cout << "Password:";
	  cin >> pswdSeed;

 		// Echo hash in file
 		command = "echo " + pswdSeed + "| md5sum > hash_seedPswd";
		pswdSeed.clear();
		c_command = command.c_str();
		system(c_command);

		fgets(seed_hash,sizeof(seed_hash),seed);
	  min = 123;
	  string _test;
	  string _seed(seed_hash);
	  _seed.erase(_seed.length() - 4);
	  int i;
	  int j;
		flag = false;

		while(true){
			now = time(0);
			ltm = localtime(&now);
			// Exec every time that minute is different to the last minute
			if(min!= (1 + ltm->tm_min)){
				tokens = fopen("tokens","r");
  			cout << endl;
  			//cout << "Enabled tokens:" << endl;
  			system("> tokens");
		  	// get various components of tm structure.
			  year = 1900 + ltm->tm_year;
			  month = 1 + ltm->tm_mon;
			  day = ltm->tm_mday;
			  hour = 1 + ltm->tm_hour;
			  min = 1 + ltm->tm_min;

  		  for (i=0;i<5;i++){
  		  	command = "echo -e " + _seed + to_string(year) + to_string(month) + to_string(day)+ to_string(hour) + to_string(min) + " | md5sum | awk '{ print $1 }' >> tokens";
  		  	//cout << command << endl;
  		  	c_command = command.c_str();
					system(c_command);
					fgets(old_tokens,sizeof(old_tokens),tokens);
					string _test(old_tokens);
					//cout << _test << endl;
          int_token[i] = (long int) md5_int(_test);
					//cout << to_string(i) + "-: "<<to_string(int_token[i]) << endl;
					_test.erase(std::remove(_test.begin(), _test.end(), '\n'),_test.end());
					_seed = _test;
					memset(old_tokens,'\0',sizeof(old_tokens));
  		  }
				fclose(tokens);
			}

			while(min == (1 + ltm->tm_min)){

				cout << endl;
				cout << "Insert a token:" << endl;
				cin >> token;
				now = time(0);
				ltm = localtime(&now);

				for(i=0;i<5;i++){
					if(token == int_token[i]){
						flag = true;
						break;
					}
					else
						flag = false;
				}

				for(j=4;j>=i;j--){
					int_token[j]=0;
					//cout << to_string(j) + "-: "<<to_string(int_token[j]) << endl;							
				}

				cout << endl;
				if(flag){

					cout << "Valid key!" << endl;
					cout << "OK!" << endl;
				}
				else{
				 	cout << "Try again!" << endl;
				 }	  	

				 cout << "-------------------------------" << endl;
			}	 
		}
	}
	 	
  return 0;
}



