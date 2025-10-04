#pragma once

#include <span>
#include <vector>
#include <string_view>


struct EWMA {
    double alpha = 0.3;
    double value = 0.0;
    bool initialized = false;

    void update(double x) {
        if (!initialized) {
            value = x;
            initialized = true;
        } else {
            value = alpha * x + (1 - alpha) * value;
        }
    }
};

struct TickerState {
    std::string_view ticker;
    uint64_t mentions;
    EWMA mentionsRateEwma;
};



struct SocialScreenerState {
    std::span<TickerState> tickers;
    std::unordered_map<std::string_view, size_t> tickerIndexMap;
    std::vector<size_t> tickerIndicesRanked;

    void addTicker(TickerState& ticker);
    void addMention(std::string_view ticker);
    void updateAllStats();
};











