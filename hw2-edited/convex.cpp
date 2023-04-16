#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    double th;
    cin >> n >> k >> th;
    cout << n << " " << k << " " << th << endl;

    int a[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;

    vector<int> branches[k + 1];
    for(int i = 1; i <= k; i++) {
        int b;
        cin >> b;
        branches[i].push_back(b);
        while(cin.peek() != '\n') {
            cin >> b;
            branches[i].push_back(b);
        }
        for(unsigned int j = 0; j < branches[i].size(); j++) {
            cout << branches[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int plow = abs(a[i] - a[j]);
            if(plow <= (th * (a[i] + a[j])) / 2.0) {
                cout << i << " " << j << " " << plow << endl;
            }
        }
    }

    int time;
    for(int i = 1; i <= k; i++) {
        cin >> time;
        cout << time << " ";
        for(int j = 1; j < time; j++) {
            int b;
            cin >> b;
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}
