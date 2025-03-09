#include <iostream>
#include <vector>

void permute(int num, std::vector<std::vector<int> >& permutations, std::vector<int>& current, std::vector<bool>& used) {
    if (current.size() == num) {
        permutations.push_back(current);
        return;
    }

    for (int i = 0; i < num; i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(i + 1);
            permute(num, permutations, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main(int argc, char* argv[]) {
    int num = atoi(argv[1]);
    std::vector<std::vector<int> > permutations;
    std::vector<int> current;
    std::vector<bool> used(num, false);

    permute(num, permutations, current, used);

    for (int i = 0; i < permutations.size(); i++) {
        for (int j = 0; j < permutations[i].size(); j++) {
            std::cout << permutations[i][j] << " ";
        }
        std::cout << '\n';
    }
}