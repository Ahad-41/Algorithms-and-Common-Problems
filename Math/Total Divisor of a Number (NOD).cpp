int divisorCount(int n)
{
    int totalDivisor = 1, count = 0;
    while (n % 2 == 0)
    {
        count++;
        n /= 2;
    }
    totalDivisor *= (count + 1);

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        totalDivisor *= (count + 1);
    }
    if (n > 2) totalDivisor *= 2;
    
    return totalDivisor;
}