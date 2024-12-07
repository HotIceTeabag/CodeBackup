/*
문제 해석
문제 설명
우주에 빛나는 별들은 우리에게 영감을 주고 가이드를 제공합니다.
천문학자 Dr. Kobsered는 어두운 하늘에서 빛나는 별들의 대칭성을 연구하다가,
평면 상의 점들로 구성된 별들의 대칭성에 대해 궁금증을 갖게 되었습니다.

주어진 별들의 집합
S와 한 점

S의 대칭성은 주어진 xy 평면에서 모든

문제 입력
첫 번째 줄에 별들의 개수
n이 주어집니다.
별들의 좌표는 서로 다릅니다.
문제 출력
별 집합
𝑆
S의 대칭성을 나타내는 정수 하나를 출력합니다.
문제 핵심
대칭성의 정의:

𝑝
p를 중심으로 대칭성을 이루는 점 쌍의 수를 최대화합니다.
문제 해결 방법:

모든 점 쌍을 검사하여 가능한
𝑝
p를 구하고, 가장 큰 대칭성을 출력합니다.

대칭성 기준: {(x1+x2)/2, (y1+y2)/2}좌표를 만족하는 점 2개를 가짐
pair형 벡터를 순회하며 대칭성 입력->map 순회하며 최대 value 갯수 탐색 -> 가장 높은 value*2를 출력?
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};              //지피티 최고

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    pair<int, int> pir;
    unordered_map<pair<int, int>, int, pair_hash> map;
    int N;                                                  //입력수
    cin >> N;
    vector<pair<int, int>> dots(N);
    pair<int, int> temp;

    for (int i = 0; i < N; i++)cin >> dots[i].first >> dots[i].second;  //점 입력

    int MAX = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[make_pair(dots[i].first + dots[j].first, dots[i].second + dots[j].second)]++;

            MAX = max(MAX, map[temp]);
        }
    }

    cout << MAX*2;

    return 0;
}