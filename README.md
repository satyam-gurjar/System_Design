# System_Design
# Day_08_StrategyDesignPattern
/*
Visual Memory Layout
Here's how memory might look (simplified):



[Stack]
robot1 --> (heap CompanionRobot object)
            |
            |--> walkBehavior ---> (NormalWalk object on heap)
            |--> talkBehavior ---> (NormalTalk object on heap)
            |--> flyBehavior  ---> (NoFly object on heap)

Each of these objects has:
    - vptr --> vtable (points to correct override function)
*/

//Robot* robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
 High-Level Explanation
robot1 is a stack variable that points to a CompanionRobot object on the heap.

The CompanionRobot object inherits from Robot, so it contains 3 pointer members: walkBehavior, talkBehavior, flyBehavior.

Each of those pointers points to a separate heap-allocated object: NormalWalk, NormalTalk, and NoFly.

# Memory Diagram (Text-based)
[Stack]
+----------------------------+
| robot1                    | ---> [CompanionRobot on Heap]
+----------------------------+

[Heap]
+-----------------------------+          +--------------------+
| CompanionRobot Object       |          | NormalWalk Object  |
|-----------------------------|          |--------------------|
| vptr -> CompanionRobot vtbl|          | vptr -> NormalWalk vtbl |
| walkBehavior --------------+--------->| walk() override     |
| talkBehavior --------------+          +--------------------+
| flyBehavior  --------------+
|                             |          +--------------------+
+-----------------------------+          | NormalTalk Object  |
                                         |--------------------|
                                         | vptr -> NormalTalk vtbl |
                                         | talk() override     |
                                         +--------------------+

                                         +--------------------+
                                         | NoFly Object       |
                                         |--------------------|
                                         | vptr -> NoFly vtbl |
                                         | fly() override     |
                                         +--------------------+
Summary of Pointers
Pointer     	Points To (Type)	Location
robot1      	CompanionRobot	    Stack → Heap
walkBehavior  	NormalWalk      	Heap → Heap
talkBehavior	NormalTalk	        Heap → Heap
flyBehavior  	NoFly	            Heap → Heap