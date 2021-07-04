#include <bits/stdc++.h>
using namespace std;

int main()
{
  char original[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char replaced[] = {'y', 'n', 'l', 'k', 'x', 'b', 's', 'h', 'm', 'i', 'w', 'd', 'p', 'j', 'r', 'o', 'q', 'v', 'f', 'e', 'a', 'u', 'g', 't', 'z', 'c'};
  string s;
  int choice;
  cout << "1) Plain text to cipher text\n2) Cipher text to plain text\nEnter choice: ";
  cin >> choice;
  cin.ignore();
  string op = "";
  switch (choice)
  {
  case 1:
    cout << "Plain text(only lowercase alphabets): ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] >= 'a' && s[i] <= 'z')
      {
        auto itr = find(original, original + 26, s[i]);
        int index = distance(original, itr);
        op += replaced[index];
      }
      else if (isspace(s[i]))
      {
        op += " ";
      }
      else
      {
        cout << "Invalid string";
        return -1;
      }
    }
    cout << "Cipher Text: " << op;
    break;

  case 2:
    cout << "Cipher text(only lowercase alphabets): ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] >= 'a' && s[i] <= 'z')
      {
        auto itr = find(replaced, replaced + 26, s[i]);
        int index = distance(replaced, itr);
        op += original[index];
      }
      else if (isspace(s[i]))
      {
        op += " ";
      }
      else
      {
        cout << "Invalid string";
        return -1;
      }
    }
    cout << "Plain Text: " << op;
    break;

  default:
    return -1;
  }
  return 0;
}