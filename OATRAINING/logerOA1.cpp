#include <bits/stdc++.h>

using namespace std;

class LogServer{
private:
	int m;
	queue<pair<int, int>> logs;
	int latestLogTime;
public:
	LogServer(int m) : m(m), latestLogTime(-1) {}

	void recordLog(int logId, int timestamp){
		if(latestLogTime = -1){
			logs.push(make_pair(logId, timestamp));
		}
		else{
			if(timestamp >= latestLogTime){
				logs.push(make_pair(logId, timestamp));
			}

			while(!logs.empty()){
				pair<int, int> top = logs.front();
				if((top.second > timestamp - 3600)){
					break;
				}
				else{
					logs.pop();
				}
			}
		}
		latestLogTime = timestamp;
	}

	string getLogs(){
		string logsLastHour = "";

		queue<pair<int, int>> tmp = logs;
		int cnt = 0;
		while(!tmp.empty() || cnt < m){
			pair<int, int> top = tmp.front();
			tmp.pop();
			cnt++;

			logsLastHour += top.second + ",";
		}

		if(!logsLastHour.empty()){
			logsLastHour.pop_back();
		}

		return logsLastHour;
	} 


	int getLogCount(){
		return logs.size();
	}
};


int main(){
#ifndef LOCAL
    freopen("input.txt", "r", stdin);     
    freopen("output.txt", "w", stdout);     
#endif

	int m, q;
	cin >> m >> q;
	LogServer logServer(m);



	for(int i = 0; i < q; i++){
		string line; 
		getline(cin, line);
		stringstream ss(line);

	    string command;
	    ss >> command;
	    cout << i << ": "<< command << endl;

	    if(command == "RECORD"){
	    	int logID, timestamp; 
	    	ss >> logID >> timestamp;
	    	logServer.recordLog(logID, timestamp);
	    }
	    else if(command == "GET_LOGS"){
	    	cout << logServer.getLogs() << endl;
	    }
	    else if(command == "COUNT"){
	    	cout << logServer.getLogCount() << endl;
	    }
	}

	return 0;
}