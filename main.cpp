#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> r, inf, v;

    for (int i = 0; i < 7; i++) {
        char t;
        cin >> t;
        int a = int(t - '0');
        double p = log2(i + 1);
        if (p == ceil(p))
            r.push_back(a);
        else {
            inf.push_back(a);
        }
        v.push_back(a);
    }

    int s1 = r[0] ^ inf[0] ^ inf[1] ^ inf[3];
    int s2 = r[1] ^ inf[0] ^ inf[2] ^ inf[3];
    int s3 = r[2] ^ inf[1] ^ inf[2] ^ inf[3];


    int sum = s1 + (s2 * 2) + (s3 * 4);
    //cout << sum << endl;
    if (sum == 0) {
        cout << "No problem\n";
    } else {
        cout << sum << " digit is wrong\n";
        double check = log2(sum);
        if (check == ceil(check)) {
            cout << check + 1 << " parity bit is wrong.\n";
            cout << check + 1 << " parity bit is equal to " << r[check] << endl;
            cout << "this bit must be equal " << !r[check] << endl;
        } else {
            int idx;
            if (sum == 3)
                idx = 1;
            else
                idx = sum - 3;
            cout << idx << " information bit is wrong\n";
            cout << idx << " information bit is equal to " << inf[idx - 1] << endl;
            cout << "this bit must be equal " << !inf[idx - 1] << endl;
        }
        v[sum - 1] = !v[sum - 1];
    }

    cout << "right message is ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;


    return 0;
}
