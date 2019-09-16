#include<bits/stdc++.h>

using namespace std;

int main(int argc,char *argv[]){
  
  /* Variables */
  string user,user_test;
  string pswdSeed;
  string pswdLocal,pswdTest;
  string command;
  const char *c_command;
  char pswd_test[50],test_local[50],seed_hash[50],old_tokens[50];
  int int_token[5];

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

  while(true){
		if(first){
		  first = false;
		  
		  // User interaction
		  cout << "Username:";
		  cin >> user;
		  cout << "Seed password:";
		  cin >> pswdSeed;

		  // Senha semente
		  command = "echo " + pswdSeed + "| md5sum > hash_seedPswd";
		  pswdSeed.clear();
		  c_command = command.c_str();
		  system(c_command);
		  
		  // Senha local
		  cout << "Local password:";
		  cin >> pswdLocal;
		  command = "echo " + pswdLocal + "| md5sum > hash_localPswd";
		  pswdSeed.clear();
		  c_command = command.c_str();
		  system(c_command);
	  	}
	  	else{
	  		cout << endl;

			  // Verify password
			  // User interaction
			  cout << "Username:";
			  cin >> user_test;
			  if(strcmp(user.c_str(),user_test.c_str())){
			  	cout << "Invalid user!" << endl;
			  	break;
			  }
			  else{
					// Get new password	
					cout << "Local password:";
			  	cin >> pswdTest;
			 		// Echo hash in file
			 		command = "echo " + pswdTest + "| md5sum > hash_test";
		  		pswdTest.clear();
		  		c_command = command.c_str();
		  		system(c_command);
		  		// Returns hash from file
					fgets(pswd_test,sizeof(pswd_test),test);
					fgets(test_local,sizeof(test_local),local);

		  		if(!strcmp(pswd_test,test_local)){
		  			cout << "Correct password!!!" << endl;
		  			cout << "Generating tokens" << endl;

		  			fgets(seed_hash,sizeof(seed_hash),seed);
					  min = 123;

					  string _test;
					  string _seed(seed_hash);
					  _seed.erase(_seed.length() - 4);

						while(true){
							now = time(0);
  						ltm = localtime(&now);
							// Exec every time that minute is different to the last minute
			  			if(min!= (1 + ltm->tm_min)){
			  				tokens = fopen("tokens","r");
				  			cout << "min" << endl;
				  			system("> tokens");
						  	// get various components of tm structure.
							  year = 1900 + ltm->tm_year;
							  month = 1 + ltm->tm_mon;
							  day = ltm->tm_mday;
							  hour = 1 + ltm->tm_hour;
							  min = 1 + ltm->tm_min;

				  		  for (int i=0;i<5;i++){
				  		  	command = "echo -e " + _seed + to_string(year) + to_string(month) + to_string(day)+ to_string(hour) + to_string(min) + " | md5sum | awk '{ print $1 }' >> tokens";
				  		  	//cout << command << endl;
				  		  	c_command = command.c_str();
		  						system(c_command);
		  						fgets(old_tokens,sizeof(old_tokens),tokens);
		  						string _test(old_tokens);
		  						//cout << _test << endl;
		  						int_token[i] = stoi(_test,0,10);
		  						cout << to_string(int_token[i]) << endl;
		  						_test.erase(std::remove(_test.begin(), _test.end(), '\n'),_test.end());
		  						_seed = _test;
		  						memset(old_tokens,'\0',sizeof(old_tokens));
				  		  }

				  		  fclose(tokens);

		  		  	}
		  		  }
		  		} 	
			  }
	  	}
  }


  return 0;
}
