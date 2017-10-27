#include <TGUI/TGUI.hpp>
#include <iostream>
#include <functional>
#include "Project_lightrays.h"

using namespace std;

void buttonPressed(tgui::Gui& gui);
bool isLightraysStarted = false;

int main()
{
    sf::RenderWindow window{{800, 600}, "Window"};
    tgui::Gui gui{window}; // Create the gui and attach it to the window
	tgui::Theme::Ptr theme = tgui::Theme::create("/home/friso/tgui-git/src/TGUI/widgets/Black.txt");

	//	Project* lightrays = (Project) new Project_lightrays(window);
	Project_lightrays lightrays(window);
    tgui::Button::Ptr button = theme->load("button");
	button->setText("start");
	button->setSize(sf::Vector2f(200, 50));
	button->connect("pressed", buttonPressed, std::ref(gui));
    //tgui::Button::Ptr button2 = tgui::Button::create("second");
    button->setPosition(400-button->getSize().x/2, 200);
    
    gui.add(button, "button");
    //gui.add(button2, "button2");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event); // Pass the event to the widgets
        }

        window.clear();
        gui.draw(); // Draw all widgets
		if(isLightraysStarted) lightrays.loop();
        window.display();
    }
}


void buttonPressed(tgui::Gui& gui){
	cout << "button pressed" << endl;
	const tgui::Widget::Ptr button = gui.get("button");
	button->hide();
	isLightraysStarted = true;
}


