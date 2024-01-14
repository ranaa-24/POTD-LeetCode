bool closeStrings(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;
    vector<int> freq1(26, 0), freq2(26, 0);
    // populate the freq of both
    for (char ch : word1)
        freq1[ch - 'a']++;
    for (char ch : word2)
        freq2[ch - 'a']++;

    // 1. All the unique char which there in String1 need's to there as well In string2
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] == 0 && freq2[i] != 0)
            return false; // word1 me nhi hai, but word2 m h ek particuler letter
        if (freq1[i] != 0 && freq2[i] == 0)
            return false; // word1 me hai, but word2 m nhi hai
    }

    // 2. Frequency of Char need's to be same there both of string as we can do Transform every occurrence of one existing           char into another existing character
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    return freq1 == freq2;
}