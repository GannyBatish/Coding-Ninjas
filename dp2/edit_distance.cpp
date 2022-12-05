int editDistance(string s1, string s2) {
  if (s1.length() == 0 || s2.length() == 0) {
    return max(s1.length(), s2.length());
  }

  if (s1[0] == s2[0]) {
    return editDistance(s1.substr(1), s2.substr(1));
  } else {
    // Insert
    int a = editDistance(s1.substr(1), s2);
    // Delete
    int b = editDistance(s1, s2.substr(1));
    // Replace
    int c = editDistance(s1.substr(1), s2.substr(1));

    return min(a, min(b, c)) + 1;
  }
}