#include <bits/stdc++.h>
using namespace std;

int main()
{
  char list[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int choice;
  cout << "1) Plain text to cipher text\n2) Cipher text to plain text\nEnter choice: ";
  cin >> choice;
  int k;
  cout << "Key(must be a number and greater than 0 and less than 26)?: ";
  cin >> k;
  cin.ignore();
  if (k < 1 || k > 25)
  {
    cout << "Invalid key";
    return -1;
  }
  string s;
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
        auto itr = find(list, list + 26, s[i]);
        int index = distance(list, itr);
        int out = (index + k) % 26;
        op += list[out];
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
    cout << "Cipher text: " << op;
    break;

  case 2:
    cout << "Cipher text(only lowercase alphabets): ";
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] >= 'a' && s[i] <= 'z')
      {
        auto itr = find(list, list + 26, s[i]);
        int index = distance(list, itr);
        int out;
        if (index - k < 0)
          out = 26 - ((k - index) % 26);
        else
          out = (index - k) % 26;
        op += list[out];
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
    cout << "Plain text: " << op;
    break;

  default:
    return -1;
  }
  return 0;
}