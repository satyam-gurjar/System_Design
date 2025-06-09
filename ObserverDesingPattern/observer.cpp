#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class ISubscriber {
    public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

class IChannel {
    public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel(){}
};

class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestvideo;

public:
    Channel(const string& name) {
        this->name = name;
    }

    void subscribe(ISubscriber* subscriber) override {
        if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()){
            subscribers.push_back(subscriber);
        }
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find (subscribers.begin(), subscribers.end(), subscriber);
        if(it != subscribers.end()){
            subscribers.erase(it);
        }
    }

};




