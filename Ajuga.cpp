#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(unsigned long long x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<unsigned long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // 3 27
    // 8 8 2 2
    // not quadrat 
    
    // himpunan dalam himpunan
    // 4 4 1
    //
    vector<int> h(n, -1);
    int ck = 0;
    vector<bool> take(n, false);
    for(int i = 0; i < n - 1; i++){
        if(take[i]){
            continue;
        }
        for(int j = i + 1; j < n; j++){
            if(take[j]) continue;
            else{
                if(isPerfectSquare(a[i] * a[j])){
                    if(take[i]){
                        h[j] = ck;
                        take[i] = true;
                        take[j] = true;
                    } else{
                        ck++;
                        h[i] = ck;
                        h[j] = ck;
                        take[i] = true;
                        take[j] = true;
                    }
                    // cout << a[i] << " " << a[j] << "\n";
                    // for(int i = 0; i < n; i++) cout << h[i] << " ";
                    // cout << "\n";
                }
            }
        }
    }
    
    
    int ans = 0;
    for(int i = 0; i < n; i++) if(h[i] == -1) ans++;
    
    if(ck == 0) {
        cout << "-1";
        return;
    }
    cout << ans + ck + 1;
    
    
    // if a * b = squared number and b * c = squared number so a * c also squared number
    // 8 3 27 2 8 7
    // 8 2 8 2
    // 3 27
    
}

int main() {
    solve();
    
    return 0;
}