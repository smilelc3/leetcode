//
// Created by smile on 2021/9/22.
//

#include <string>
#include <unordered_map>
#include <utility>

using StartEndStation = std::pair<std::string, std::string>;

struct IdMapVal {
    std::string startStation;
    int startTime;

    IdMapVal() : startTime(0) {}

    IdMapVal(std::string startStation, int t) : startStation(std::move(startStation)), startTime(t) {}
};

struct TripMapVal {
    size_t cnt;
    size_t totTime;

    TripMapVal() : cnt(0), totTime(0) {}
};


class StartEndStationHashFunc {
public:
    size_t operator()(const StartEndStation &key) const {
        return std::hash<std::string>()(key.first) ^ std::hash<std::string>()(key.second);
    }
};


class StartEndStationEqual {
public:
    bool operator()(const StartEndStation &keyA, const StartEndStation &keyB) const {
        return keyA.first == keyB.first and keyA.second == keyB.second;
    }
};


class UndergroundSystem {
public:
    UndergroundSystem() = default;

    void checkIn(int id, const std::string &stationName, int t) {
        id2MsgMap[id] = IdMapVal(stationName, t);
    }

    void checkOut(int id, const std::string &stationName, int t) {
        auto startMsg = id2MsgMap[id];
        trip2MsgMap[{startMsg.startStation, stationName}].cnt++;
        trip2MsgMap[{startMsg.startStation, stationName}].totTime += t - startMsg.startTime;
        id2MsgMap.erase(id);
    }

    double getAverageTime(const std::string &startStation, const std::string &endStation) {
        auto TripMsg = trip2MsgMap[{startStation, endStation}];
        return (double) TripMsg.totTime / (double) TripMsg.cnt;
    }

private:
    std::unordered_map<int, IdMapVal> id2MsgMap;
    std::unordered_map<StartEndStation, TripMapVal, StartEndStationHashFunc, StartEndStationEqual> trip2MsgMap;
};
