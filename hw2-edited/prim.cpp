#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second

const int N = 1e6 + 5;

vector<pair<int, int>> adj[N];
vector<int> branches[N];

bool vis[N];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
    int n, k;
    double th;
    cin >> n >> k >> th;

    int a[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= k; i++) {
        int b;
        cin >> b;
        branches[i].pb(b);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int plow = abs(a[i] - a[j]);
            if(plow <= (th * (a[i] + a[j])) / 2.0) {
                adj[i].pb({j, plow});
                adj[j].pb({i, plow});
            }
        }
    }

    for(int i = 1; i <= k; i++) {
        int time;
        cin >> time;
        for(int j = 1; j < time; j++) {
            int b;
            cin >> b;
            for(int l = 0; l < branches[i].size(); l++) {
                int u = branches[i][l];
                if(u == b) {
                    branches[i].erase(branches[i].begin() + l);
                    l--;
                    continue;
                }
                if(vis[u]) continue;
                pq.push({0, u});
            }
        }

        while(!pq.empty()) {
            pll p = pq.top();
            pq.pop();

            int u = p.ss;
            if(vis[u]) continue;
            vis[u] = true;

            for(int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].ff;
                int w = adj[u][j].ss;
                if(!vis[v]) pq.push({w, v});
            }

            if(u != branches[i][0]) continue;
            branches[i].erase(branches[i].begin());
            cout << "k" << i - 1 << " " << time << endl << u - 1;
            int cur = u;
            while(!branches[i].empty()) {
                int nxt = -1;
                int mn = INT_MAX;
                for(int j = 0; j < adj[cur].size(); j++) {
                    int v = adj[cur][j].ff;
                    int w = adj[cur][j].ss;
                    if(vis[v]) continue;
                    if(w < mn) {
                        mn = w;
                        nxt = v;
                    }
                }
                if(nxt == -1) break;
                branches[i].erase(find(branches[i].begin(), branches[i].end(), nxt));
                cout << "->" << nxt - 1;
                cur = nxt;
            }
            cout << endl;
        }

        memset(vis, false, sizeof(vis));
    }

    return 0;
}
