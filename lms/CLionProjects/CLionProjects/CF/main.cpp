#include <iostream>
#include <vector>
#include <set>

void setNewSeed(unsigned int &seed) {
    seed *= 123456;
    seed %= 987;
    seed += 123;
    seed %= 10000;
}

std::pair<char, unsigned int> getQuery(unsigned int &seed) {
    char op = "im"[seed % 2];
    setNewSeed(seed);
    unsigned int number = seed;
    setNewSeed(seed);
    return {op, number};
}

std::vector<std::pair<char, unsigned int>>
getTaskQueries(unsigned int seed) {
    unsigned int q = seed;
    setNewSeed(seed);
    std::vector<std::pair<char, unsigned int>> queries;
    for (int i = 0; i < q; ++i) {
        queries.push_back(getQuery(seed));
    }
    return queries;
}

int main() {
    unsigned int seed;
    std::cin >> seed;
    std::vector<std::pair<char, unsigned int>> queries = getTaskQueries(seed);
    std::set<unsigned int> nums;
    unsigned long long sum = 0;
    for (auto query : queries){
        if (query.first == 'i'){
            nums.insert(query.second);
        } else{
            if (!nums.empty()){
                sum += std::min(query.second, *nums.begin());
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}