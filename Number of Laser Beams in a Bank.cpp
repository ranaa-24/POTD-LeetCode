int numberOfBeams(vector<string> &bank)
{
    int onesInPrevRow = 0;
    int tot = 0;
    for (int i = 0; i < bank.size(); i++)
    {
        int onesInCurrRow = cnt(bank[i]);
        if (onesInCurrRow == 0)
            continue;
        tot += onesInCurrRow * onesInPrevRow;
        onesInPrevRow = onesInCurrRow;
    }
    return tot;
}

int cnt(string row)
{
    int count = 0;
    for (char it : row)
    {
        count += it - '0';
    }
    return count;
}