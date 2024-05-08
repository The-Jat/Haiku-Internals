#include <Application.h>
#include <Message.h>
#include <Looper.h>
#include <stdio.h>

#define MESSAGE_TYPE_1 'Msg1'
#define MESSAGE_TYPE_2 'Msg2'

class MyLooper : public BLooper {
public:
    MyLooper(): BLooper("MyLooper") {}
    virtual void MessageReceived(BMessage* message) {
    switch (message->what) {
        case MESSAGE_TYPE_1:
            printf("Received Message Type 1\n");
            break;
        case MESSAGE_TYPE_2:
            printf("Received Message Type 2\n");
            break;
        default:
            BLooper::MessageReceived(message);
            break;
    	}
	}
};

int main() {
    MyLooper *myLooper = new MyLooper();
    
    myLooper->Run();
    
    BMessage msg(MESSAGE_TYPE_1);
    myLooper->PostMessage(&msg);
    BMessage msg2(MESSAGE_TYPE_2);
    myLooper->PostMessage(&msg2);

    
    
    return 0;
}
