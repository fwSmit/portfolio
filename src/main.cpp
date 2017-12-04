#include <TGUI/TGUI.hpp>
#include <iostream>
#include <functional>
#include "Project_lightrays.h"
#include "Project_imageDrawing.h"
#include "Manager.h"

using namespace std;

void buttonPressed(tgui::Gui& gui);
void buttonPressed2(tgui::Gui& gui);
void showAllButtons(tgui::Gui& gui);
bool isLightraysStarted = false;
bool isImageDrawingStarted = false;
int main()
{
    sf::RenderWindow window{{800, 600}, "Window"};
    tgui::Gui gui{window}; // Create the gui and attach it to the window

	Manager manager(window, gui);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type){
				// window closed
				case sf::Event::Closed:
					window.close();
					break;

				// key pressed
				case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::Escape){
						manager.closeAll();
					}
					break;

				// we don't process other types of events
				default:
					break;
			}
            gui.handleEvent(event); // Pass the event to the widgets
			manager.handleEvent(event);
			//lightrays.handleEvent(event); 													// TODO Move to manager
        }

        window.clear();
		manager.loop();
        gui.draw(); // Draw all widgets
        window.display();
    }
}

void showAllButtons(tgui::Gui& gui){
	const tgui::Widget::Ptr button = gui.get("button");
	const tgui::Widget::Ptr button2 = gui.get("button2");
	button->show();
	button2->show();
}
void hideAllButtons(tgui::Gui& gui){
	const tgui::Widget::Ptr button = gui.get("button");
	const tgui::Widget::Ptr button2 = gui.get("button2");
	button->hide();
	button2->hide();
}

void buttonPressed(tgui::Gui& gui){
	cout << "button pressed" << endl;
	hideAllButtons(gui);
	isLightraysStarted = true;

}


void buttonPressed2(tgui::Gui& gui){
	cout << "button 2 pressed" << endl;
	hideAllButtons(gui);
	isImageDrawingStarted = true;
}

