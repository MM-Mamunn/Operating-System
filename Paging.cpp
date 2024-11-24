#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int n;
    cout << "Enter the logical address: ";
    cin >> n;
    int page_table[] = {5, 6, 1, 2};
    int p = 0, d = 0;
    d |= n & (1 << 0);
    d |= n & (1 << 1);

    if (n & (1 << 2))
        p |= (1 << 0);
    if (n & (1 << 3))
        p |= (1 << 1);
    int f = page_table[p];
    int physical_address = d;
    if (f & (1 << 0))
        physical_address |= (1 << 2);
    if (f & (1 << 1))
        physical_address |= (1 << 3);
    cout << "The Physical address is : ";
    cout << physical_address << endl;
    return 0;
}
