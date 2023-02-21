#include <bits/stdc++.h>
using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    // ถ้ํานอกขอบเขตก็ไม่ได้ช่องเพิ่ม
    if (grid[r][c] != c1) return 0;
    // ถ้ําไม่ใช่อักขระเดียวกับ c1 แสดงว่ําคนละสีหรือคนละกลุ่มนั่นเอง ดังนั้นช่องไม่เพิ่ม
    int ans = 1; // เพิ่ม 1 ให้ค ําตอบเพรําะว่ําช่อง (r, c) อย่ํางน้อยเป็นสี c1 แล้ว
    grid[r][c] = c2; // เปลี่ยนสีช่อง (r, c) เป็น c2 เพื่อป้องกันระบํายซ้ ํา
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while ()
    {
        /* code */
    }
    

    return 0;
}
