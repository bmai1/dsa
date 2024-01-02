class BrowserHistory {
public:
    vector<string> pages;
    int page = 0;

    BrowserHistory(string homepage) {
        pages.push_back(homepage);
    }
    
    void visit(string url) {
        ++page;
        pages.resize(page);
        pages.push_back(url);
    }

    string back(int steps) {
        page = max(0, page - steps);
        return pages[page];
    }
    
    string forward(int steps) {
        page = min((int) (pages.size() - 1), page + steps);
        return pages[page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */