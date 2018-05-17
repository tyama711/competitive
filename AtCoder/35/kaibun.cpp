#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string str;

  cin >> str;
  string::iterator it_begin = str.begin();
  string::iterator it_end   = str.end() - 1;
  bool fail_flag = false;
  while (it_begin < it_end) {
	if (*it_begin != '*' &&
		*it_end   != '*' &&
		*it_begin != *it_end) {
	  fail_flag = true;
	  break;
	}
	it_begin++;
	it_end--;
  }
  if (fail_flag)
	cout << "NO\n";
  else
	cout << "YES\n";

  return 0;
}
