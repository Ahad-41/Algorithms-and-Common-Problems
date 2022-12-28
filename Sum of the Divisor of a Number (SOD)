int sumOfDivisor(int n)
{
    int totalSum = 1, count = 0, sum = 1;
    while (n % 2 == 0)
    {
        count++;
        sum += pow(2, count);
        n /= 2;
    }
    totalSum *= sum;

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        count = 0;
        sum = 1;
        while (n % i == 0)
        {
            count++;
            sum += pow(i, count);
            n /= i;
        }
        totalSum *= sum;
    }
    if (n > 2) totalSum *= (n+1);
    
    return totalSum;
}
