#include <bits/stdc++.h>
using namespace std;

#define MXm 1000;

class LogServer {

private:
    int m;
    vector<vector<int>> logs;
    int latestLogTime;

    vector<pair<int, int>> lastHour;
public:
    LogServer(int m) : m(m){
        logs = vector<vector<int>>(MXm + 1);
        latestLogTime = -1;

    }


    void getLogs(int logId, int timestamp){
        if(latestLogTime == -1){    
            logs[logId].push_back(timestamp);
            lastHour.push_back(make_pair(logId, timestamp));
        }

        else{
            if(timestamp >= latestLogTime){
                logs[logId].push_back(timestamp);
                lastHour.push_back(make_pair(logId, timestamp));
            }

        }
        latestLogTime = timestamp;
    }


    string getLogs(){

        string logIDS = "";
        int cnt = 0;
        for(auto log : lastHour){
            if(cnt >= m){
                break;
            }
            if(log.second >= latestLogTime - 3600){
                logdsIDS += to_string(log.first) + ',';
                cnt++;
            }
        }
        logdsIDS.erase(logdsIDS.size() - 1);
        return logIDS;
    }

    int getLogCount(){
        int cnt = 0;
        for(auto log : lastHour){
         
            if(log.second >= latestLogTime - 3600){
                logdsIDS += to_string(log.first) + ',';
                cnt++;
            }
        }
        return cnt;
    }




}
