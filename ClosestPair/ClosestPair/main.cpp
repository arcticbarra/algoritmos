//Enrique Barragan Gonzalez A01370878
//Aldo Cervantes Barbosa A01039261
// Best friends in Beagle Town 🐶🐶

#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

struct Point
{
    int x, y;
};

int compareX(const void* b1, const void* b2)
{
    Point *beagle1 = (Point *)b1;
    Point *beagle2 = (Point *)b2;
    return beagle1->x - beagle2->x;
}

int compareY(const void* b1, const void* b2)
{
    Point *beagle1 = (Point *)b1;
    Point *beagle2 = (Point *)b2;
    return beagle1->y - beagle2->y;
}

float distance(Point beagle1, Point beagle2)
{
    return sqrt((beagle1.x - beagle2.x) * (beagle1.x - beagle2.x) + (beagle1.y - beagle2.y) * (beagle1.y - beagle2.y));
}

float min(float x, float y)
{
    return x<y ? x:y;
}


float closestPoints(Point closePoints[], int size, float dist)
{
    float min = dist;
    
    qsort(closePoints, size, sizeof(Point), compareY);
    
    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j < size && (closePoints[j].y - closePoints[i].y) < min; ++j) {
            if (distance(closePoints[i],closePoints[j]) < min) {
                min = distance(closePoints[i], closePoints[j]);
            }
        }
    }
    return min;
}

float divideAndConquer(Point P[], int n)
{
    if (n < 4)
    {
        float min = FLT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (distance(P[i], P[j]) < min) {
                    min = distance(P[i], P[j]);
                }
            }
        }
        return min;
    }
    
    int half = n/2;
    Point halfPoint = P[half];
    
    float distanceLeft = divideAndConquer(P, half);
    float distanceRight = divideAndConquer(P + half, n-half);
    
    float dist = min(distanceLeft, distanceRight);
    
    Point closePoints[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(P[i].x - halfPoint.x) < dist) {
            closePoints[j] = P[i], j++;
        }
    }

    return min(dist, closestPoints(closePoints, j, dist));
}

float bestFriends(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    return divideAndConquer(P, n);
}

int main(int argc, const char * argv[]) {
    
    int n,x,y;
    
    cin >> n;
    Point P[n];
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        P[i].x = x;
        P[i].y = y;
    }
    
    cout << "The distance of best friends are: " << setprecision(2) << fixed <<  bestFriends(P, n) << endl;
    
    return 0;
}
