#include <Application.h>
#include <Window.h>
#include <stdio.h>

class MyApp: public BApplication {
	public:
		MyApp() : BApplication("application/x-vnd.MyApp") {}
		
		void ReadyToRun(){
			
			printf("MyApp is ready to run \n");
			BWindow* window = new BWindow(BRect(100, 100, 400, 300), "My Window",
				B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE);
				
				window->Show();
			}
};

int main() {
	
	BApplication *app1 = new BApplication("application/x-vnd-my_app1");
	
	BWindow *window = new BWindow(BRect(100, 100, 400, 300), "My Window",
						B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE);
						
	window->Show();
	
	app1->Run();
	
	
	
	//delete app1;
	
	return 0;
}
