#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

const int INF = INT_MAX; // Vô cùng lớn

int shortestPath(int A, int B, vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> dist(n, INF); // Độ dài ngắn nhất từ A đến các điểm khác
    dist[A] = 0; // Điểm bắt đầu có độ dài ngắn nhất là 0

    // Tính độ dài ngắn nhất từ A đến các điểm khác
    for (int i = A+1; i < n; i++) {
        for (int j = A; j < i; j++) {
            if (graph[j][i] != INF) {
                dist[i] = min(dist[i], dist[j] + graph[j][i]);
            }
        }
    }
    return dist[B];
}

int main() {
    int n = 5; // Số lượng điểm trên đồ thị
    vector<vector<int>> graph(n, vector<int>(n, INF)); // Đồ thị với độ dài các cạnh

    // Khởi tạo đồ thị
    graph[0][1] = 2;
    graph[0][2] = 4;
    graph[1][2] = 1;
    graph[1][3] = 7;
    graph[2][3] = 3;
    graph[2][4] = 5;
    graph[3][4] = 1;

    int A = 0, B = 4; // Điểm bắt đầu và điểm kết thúc
    int dist = shortestPath(A, B, graph); // Tìm đường đi ngắn nhất
    cout << "Shortest path from " << A << " to " << B << " is " << dist << endl;

    return 0;
}