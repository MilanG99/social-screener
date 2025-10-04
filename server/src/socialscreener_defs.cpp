#include "socialscreener_defs.hpp"


void SocialScreenerState::addTicker(TickerState& ticker) {
    tickers.push_back(ticker);
    tickerIndexMap[ticker.ticker] = tickers.size() - 1;
    tickerIndicesRanked.push_back(tickerIndexMap[ticker.ticker]);
}

void SocialScreenerState::addMention(std::string_view ticker) {
    tickers[tickerIndexMap[ticker]].mentions++;
    tickers[tickerIndexMap[ticker]].mentionsRateEwma.update(1);
}

void SocialScreenerState::updateAllStats() {
    // TODO
}