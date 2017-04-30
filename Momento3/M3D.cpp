//
//  main.cpp
//  RockyTheBeagle
//
//  Created by Enrique Barragán on 4/8/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minDistance(int dist[], bool shortestPath[], int c)
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < c; v++) {
     if (shortestPath[v] == false && dist[v] <= min) {
         min = dist[v];
         min_index = v;
       }
     }

   return min_index;
}

int dijkstra(vector< vector<int> > graph, int src, int c)
{
     int dist[c];
     bool shortestPath[c];

     for (int i = 0; i < c; i++) {
        dist[i] = INT_MAX, shortestPath[i] = false;
      }

     dist[src] = 0;
     for (int count = 0; count < c-1; count++)
     {
       int u = minDistance(dist, shortestPath,c);
       shortestPath[u] = true;
       for (int v = 0; v < c; v++) {
         if (!shortestPath[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
          }
     }

     int maxDist = 0;
     int ans=0;
     for (int i = 0; i < c; i++) {
       if (dist[i] > maxDist) {
         maxDist=dist[i];
         ans = i;
       }
     }

     return ans+65;
}

int main(int argc, const char * argv[]) {
    // k son letras, c son conexiones
    int t,k,c,cost;
    char x,y;

    cin >> t;
    for (int i = 0 ; i < t; i++) {
        // fill vector
        cin >> k >> c;
        vector< vector<int> > matrix(k, vector<int>(k, 0));
        for (int j = 0; j < c; j++) {
            cin >> x >> y >> cost;
            matrix[x-65][y-65] = cost;
            matrix[y-65][x-65] = cost;
        }
        cout << "Case " << i+1 << ": " << char(dijkstra(matrix,0,k)) << endl;

    }
    return 0;
}
