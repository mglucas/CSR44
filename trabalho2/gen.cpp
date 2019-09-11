#include<bits/stdc++.h>

using namespace std;

int main(int argc,char *argv[]){
  
  /* Variables */
  string user;
  string pswdSeed;
  string pswdLocal;
  // Time
  time_t now = time(0);
  tm *ltm = localtime(&now);
  
  // // User interaction
  // cout << "Username:";
  // cin >> user;
  // cout << "Seed password:"
  // cin >> pswdSeed;
  // cout << "Local password:"
  // cin >> pswdLocal;

   // print various components of tm structure.
   cout << "Year:" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   cout << "Time: "<< 1 + ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec << endl;

  return 0;
}
