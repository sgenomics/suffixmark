#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "global_defs.h"
#include "SuffixTree.h"
#include "SearchTrans.h"
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc,char ** argv) {

  string s = argv[1];

  ifstream infile(argv[1]);


  //SuffixTree st;
  SearchTrans st;

  for(;!infile.eof();) {
    char c;
    infile.get(c);
    st.insert(c);
  }

  st.finalise();
  cout << "built suffix tree" << endl;

  cout << "processing positions" << endl;
  st.process_positions();
  cout << "processed positions" << endl;
  st.dump_stats();

  time_t t1,t2;
  time(&t1);
  for(size_t n=0;n<2000000;n++) {
    vector<uint8_t> s;
    s.push_back('r');
    s.push_back('a');
    s.push_back('c');
    s.push_back('k');
    st.all_occurs(s);
  }
  time(&t2);
  cout << "Time: " << t2-t1 << endl; 

}
