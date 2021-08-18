#include <bits/stdc++.h>
using namespace std;

string playfair_cipher(string key, string s, string c)
{
  char alphas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  vector<char> v1, v2;

  for (char i : key)
    if (find(v1.begin(), v1.end(), i) == v1.end())
      v1.push_back(i);

  for (char i : alphas)
    if (find(v1.begin(), v1.end(), i) == v1.end())
      v2.push_back(i);

  // char arr[5][5];
  vector<vector<char>> arr;
  int v1_length = 0, v2_length = 0;
  for (int i = 0; i < 5; i++)
  {
    vector<char> row;
    for (int j = 0; j < 5; j++)
    {
      // cout << v1[j] << " ";
      if (v1_length < v1.size())
      {
        row.push_back(v1[v1_length]);
        v1_length++;
      }
      else
      {
        row.push_back(v2[v2_length]);
        v2_length++;
      }
    }
    arr.push_back(row);
  }
  // for (auto i : arr)
  // {
  //   for (auto j : i)
  //     cout << j << " ";
  //   cout << endl;
  // }
  vector<string> v3;
  s.erase(s.find_last_not_of("\t\n\v\f\r ") + 1);
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == s[i + 1])
    {
      string temp;
      temp += s[i];
      temp += 'x';
      v3.push_back(temp);
    }
    else
    {
      string temp;
      temp += s[i];
      temp += s[i + 1];
      v3.push_back(temp);
      i++;
    }
  }
  string s1 = v3[v3.size() - 1];
  if (s1[1] < 'a' || s1[1] > 'z')
    v3[v3.size() - 1][1] = 'x';
  // for (auto i : v3)
  //   cout << i << " ";
  // cout << endl;
  string text;
  for (auto str : v3)
  {
    int r1, r2, c1, c2;
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        if (str[0] == arr[i][j])
        {
          r1 = i;
          c1 = j;
        }

        if (str[1] == arr[i][j])
        {
          r2 = i;
          c2 = j;
        }
      }
    }
    if (r1 == r2)
    {
      // cout << str[0] << str[1] << endl;
      // cout << v3[r1] << endl;
      if (c == "encrypt")
      {
        str[0] = arr[r1][(c1 + 1) % 5];
        str[1] = arr[r2][(c2 + 1) % 5];
      }
      else
      {
        if (c1 - 1 < 0)
        {
          str[0] = arr[r1][4];
          str[1] = arr[r2][(c2 - 1) % 5];
        }
        else if (c2 - 1 < 0)
        {
          str[0] = arr[r1][(c1 - 1) % 5];
          str[1] = arr[r2][4];
        }
        else
        {
          str[0] = arr[r1][(c1 - 1) % 5];
          str[1] = arr[r2][(c2 - 1) % 5];
        }
      }
    }
    else if (c1 == c2)
    {
      if (c == "encrypt")
      {
        str[0] = arr[(r1 + 1) % 5][c1];
        str[1] = arr[(r2 + 1) % 5][c2];
      }
      else
      {
        if (r1 - 1 < 0)
        {
          str[0] = arr[4][c1];
          str[1] = arr[(r2 - 1) % 5][c2];
        }
        else if (r2 - 1 < 0)
        {
          str[0] = arr[(r1 - 1) % 5][c1];
          str[1] = arr[4][c2];
        }
        else
        {
          str[0] = arr[(r1 - 1) % 5][c1];
          str[1] = arr[(r2 - 1) % 5][c2];
        }
      }
    }
    else
    {
      str[0] = arr[r1][c2];
      str[1] = arr[r2][c1];
    }
    // cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    // cout << str << endl;
    text += str + ' ';
  }
  return text;
}

int main()
{
  string s, key;
  string technique;
  cout << "Type 'encrypt' for Encryption and 'decrypt' for Decryption: ";
  cin >> technique;
  if (technique.compare("encrypt") && technique.compare("decrypt"))
  {
    cout << "Invalid choice";
    return -1;
  }
  cin.ignore();
  cout << "Key(only lowercase alphabets and length must be greater than 0 and less than 26): ";
  getline(cin, key);
  if (key.length() < 1 || key.length() > 25)
  {
    cout << "Invalid length of key";
    return -1;
  }
  for (int i = 0; i < key.length(); i++)
  {
    if (key[i] >= 'a' and key[i] <= 'z')
      continue;
    else
    {
      cout << "Invalid Key";
      return -1;
    }
  }
  if (technique == "encrypt")
  {
    cout << "Plain text(only lowercase alphabets): ";
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
  }

  else if (technique == "decrypt")
  {
    cout << "Cipher text(only lowercase alphabets and must be in even length): ";
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    if (s.length() % 2 != 0)
    {
      cout << "Odd length isn't valid of cipher text";
      return -1;
    }
  }

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] >= 'a' and s[i] <= 'z' || isspace(s[i]))
      continue;
    else
    {
      cout << "Invalid String";
      return -1;
    }
  }
  if (technique == "encrypt")
    cout << "Cipher text: " << playfair_cipher(key, s, technique);
  else
    cout << "Plain text: " << playfair_cipher(key, s, technique);

  return 0;
}