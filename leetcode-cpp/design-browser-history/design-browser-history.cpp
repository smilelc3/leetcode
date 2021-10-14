//
// Created by l30014168 on 2021/10/14.
//

#include <string>
#include <vector>

class BrowserHistory {
private:
    std::vector<std::string> webHistory;
    size_t visIdx;
public:
    explicit BrowserHistory(const std::string &homepage) {
        webHistory.emplace_back(homepage);
        visIdx = 0;
    }

    void visit(const std::string &url) {
        visIdx++;
        webHistory.erase(webHistory.begin()+ visIdx, webHistory.end());
        webHistory.emplace_back(url);
    }

    std::string back(int steps) {
        visIdx = visIdx >= steps ? visIdx - steps : 0;
        return webHistory[visIdx];
    }

    std::string forward(int steps) {
        visIdx = visIdx + steps < webHistory.size() ? visIdx + steps : webHistory.size() - 1;
        return webHistory[visIdx];
    }
};
