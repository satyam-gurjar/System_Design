#include<iostream>
using namespace std;

class WalkableRobot{
    public:
    virtual void walk() = 0;
    virtual ~WalkableRobot(){}
};

class NormalWalk : public WalkableRobot{
    public:
    void walk() override {
        cout << "Walking normally..."<<endl;
    }
};

class NoWalk : public WalkableRobot {
    public:
    void walk() override {
        cout << "Cannot Walk." << endl;
    }
};

class TalkableRobot {
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot(){}
};

class NormalTalk : public TalkableRobot {
    public:
    void talk() override {
        cout << "Talking Normally..." << endl;
    }
};

class NoTalk : public TalkableRobot {
    public:
    void talk() override {
        cout << "cannot talk." << endl;
    }
};


class FlyableRobot {
    public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
    public:
    void fly() override {
        cout << "Normal fly." << endl;
    }
};

class NoFly : public FlyableRobot {
    public:
    void fly() override {
        cout << "Cannot fly." << endl;
    }
};

class Robot {
    protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

    public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->flyBehavior = f;
        this->walkBehavior = w;
        this->talkBehavior = t;
    }

    void walk(){
        walkBehavior->walk();
    }

    void talk() {
        talkBehavior->talk();
    }

    void fly(){
        flyBehavior->fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot : public Robot {
    public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w,t,f){}

    void projection() override {
        cout << "Displaying friendly companion feature..." << endl;
    }
};

class WorkRobot : public Robot {
    public:
    WorkRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w,t,f){}

    void projection() override {
        cout << "Displaying worker effeciency stats..." << endl;
    }
};

int main() {
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

}

