#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int color;

    Edge(int to, int color) : to(to), color(color) {

    }

    Edge() {
        this->color = 0;
        this->to = 0;
    }
};

struct Graph {
    vector<vector<Edge>> vertexes;

    void addEdge(int from, int to, int color, bool isTwoSided = false) {
        vertexes[from].push_back(Edge(to, color));

        if (isTwoSided) {
            vertexes[to].push_back(Edge(from, color));
        }
    }

    explicit Graph(int size) {
        vertexes.assign(size, vector<Edge>());
    }

    Graph() = default;
};

void bfs(Graph &g, int current, int instruction, vector<int> &instructions, vector<int> &endPositions) {

    if (instruction >= instructions.size()) {
        endPositions.push_back(current);
        return;
    }

    queue<int> q;
    q.push(current);

    while (!q.empty()) {
        bool isNoExit = true;

        for (int i = 0; i < g.vertexes[current].size(); i++) {
            Edge nextVertex = g.vertexes[current][i];

            if (instructions[instruction] == nextVertex.color) {
                isNoExit = false;
                bfs(g, nextVertex.to, instruction + 1, instructions, endPositions);
            }
        }

        if (isNoExit) {
            endPositions.push_back(-1);
            return;
        }
    }
}


int main() {
    int verticesCount, edgesCount, colorsCount;
    cin >> verticesCount >> edgesCount >> colorsCount;

    Graph graph = Graph(verticesCount);

    for (int i = 0; i < edgesCount; ++i) {
        int from, to, color;
        cin >> from >> to >> color;
        from--;
        to--;
        color--;

        graph.addEdge(from, to, color);
    }

    int instructionsCount;
    cin >> instructionsCount;

    vector<int> instructions(instructionsCount);

    for (int i = 0; i < instructionsCount; ++i) {
        cin >> instructions[i];
        instructions[i]--;
    }

    int startVertex;
    cin >> startVertex;
    startVertex--;
    vector<int> endVertices;

    bfs(graph, startVertex, 0, instructions, endVertices);

    string result;

    sort(endVertices.begin(), endVertices.end());

    int isEndedSuccessfully = endVertices.size();
    for (int i = 0; i < endVertices.size(); ++i) {

        if (endVertices[i] == -1) {
            isEndedSuccessfully--;
            continue;
        }

        if (endVertices.size() - isEndedSuccessfully - i != 0) {
            result += " ";
        }

        result += to_string(endVertices[i] + 1);


    }

    if (isEndedSuccessfully > 0) {
        cout << "OK" << endl;
        cout << isEndedSuccessfully << endl;
        cout << result << endl;
    }
    else {
        cout << "Hangs" << endl;
    }
    return 0;
}
