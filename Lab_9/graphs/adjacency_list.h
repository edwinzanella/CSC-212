#pragma once
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
#include <fstream>
#include <string>

class AdjList {
    private:
        std::unordered_map<int, std::list<std::pair<int, int>>> adjList;
        std::vector<int> nodes;

        void dfs(int node, std::unordered_map<int, int>& depth, int current_depth, std::ofstream& dotfile, std::set<std::pair<int, int>>& printedEdges) {
            for (auto& edge : adjList[node]) {
                if (depth.find(edge.first) == depth.end()) {
                    depth[edge.first] = current_depth + 1;
                }

                if (printedEdges.find(std::make_pair(node, edge.first)) == printedEdges.end()) {
                    printedEdges.insert(std::make_pair(node, edge.first));

                    std::string colorStr;
                    int depth_value = depth[edge.first];

                    if (depth_value % 4 == 0) {
                        colorStr = "[color=\"purple\"]";
                    }
                    else if (depth_value % 4 == 1) {
                        colorStr = "[color=\"green\"]";
                    }
                    else if (depth_value % 4 == 2) {
                        colorStr = "[color=\"blue\"]";
                    }
                    else {
                        colorStr = "[color=\"red\"]";
                    }

                    dotfile << "    " << node << " -> " << edge.first << " [label=\"" << edge.second << "\"]" << colorStr << ";" << std::endl;
                }

                if (depth[edge.first] == current_depth + 1) {
                    dfs(edge.first, depth, current_depth + 1, dotfile, printedEdges);
                }
            }
        }

        void outputGraphDepth(std::string ofname) {
            std::unordered_map<int, int> depth;
            std::set<std::pair<int, int>> printedEdges;
            std::ofstream dotfile(ofname);
            dotfile << "digraph G {" << std::endl;
            dotfile << std::endl;

            for (int node : nodes) {
                if (depth.find(node) == depth.end()) {
                    depth[node] = 0;
                    dfs(node, depth, 0, dotfile, printedEdges);
                }
            }

            dotfile << std::endl;
            dotfile << "}" << std::endl;
            dotfile.close();
        }

    public:
        AdjList() {

        }

        void addEdge(int source, int dest, int weight) {
            if (adjList.find(source) == adjList.end()) {
                nodes.push_back(source);
            }
            adjList[source].push_back(std::make_pair(dest, weight));
            if (adjList.find(dest) == adjList.end()) {
                nodes.push_back(dest);
            }
        }

        void printGraph() {
            for (int node : nodes) {
                for (auto& edge : adjList[node]) {
                    std::cout << node << " -> " << edge.first << " : " << edge.second << std::endl;
                }
            }
        }

        void outGraph(std::string ofname, bool color = false, int mode = 0) {
            std::ofstream dotfile(ofname);
            dotfile << "digraph G {" << std::endl;
            dotfile << std::endl;

            for (int node : nodes) {
                int pos = 0;

                for (auto& edge : adjList[node]) {
                    std::string colorStr = "";

                    if (color) {
                        if (mode == 1) {
                            colorStr = (edge.second % 2 == 0) ? "[color=\"blue\"]" : "[color=\"red\"]";
                        } else if (mode == 2) {
                            if (pos % 4 == 0)
                                colorStr = "[color=\"green\"]";
                            else if (pos % 4 == 1)
                                colorStr = "[color=\"blue\"]";
                            else if (pos % 4 == 2)
                                colorStr = "[color=\"red\"]";
                            else
                                colorStr = "[color=\"purple\"]";
                        } else if (mode == 3) {
                            int depth = pos % 4;
                            if (depth == 0)
                                colorStr = "[color=\"green\"]";
                            else if (depth == 1)
                                colorStr = "[color=\"blue\"]";
                            else if (depth == 2)
                                colorStr = "[color=\"red\"]";
                            else
                                colorStr = "[color=\"purple\"]";
                        }
                    }

                    dotfile << "    " << node << " -> " << edge.first << " [label=\"" << edge.second << "\"]" << colorStr << ";" << std::endl;
                    pos++;
                }
            }

            dotfile << std::endl;
            dotfile << "}" << std::endl;
            dotfile.close();
        }

        void problem1(std::string ofname){
            outGraph(ofname);
        }

        void problem2(std::string ofname){
            outGraph(ofname, true, 1);
        }

        void problem3(std::string ofname){
            outGraph(ofname, true, 2);
        }

        void problem4(std::string ofname) {
            outputGraphDepth(ofname);
        }
};