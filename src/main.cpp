#include <TGUI/TGUI.hpp>
#include <iostream>
#include <functional>
#include "Project_lightrays.h"
#include "Project_imageDrawing.h"

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
	tgui::Theme::Ptr theme = tgui::Theme::create("/home/friso/tgui-git/src/TGUI/widgets/Black.txt");

	Project_lightrays lightrays(window);
	Project_imageDrawing image_drawing(window);
    tgui::Button::Ptr button = theme->load("button");
	button->setText("lightrays");
	button->setSize(sf::Vector2f(200, 50));
	button->connect("pressed", buttonPressed, std::ref(gui));
    button->setPosition(400-button->getSize().x/2, 200);

    tgui::Button::Ptr button2 = theme->load("button");
	button2->setText("image drawing");
	button2->setSize(sf::Vector2f(200, 50));
	button2->connect("pressed", buttonPressed2, std::ref(gui));
    button2->setPosition(400-button->getSize().x/2, 300);
    
    gui.add(button, "button");
    gui.add(button2, "button2");

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
						isLightraysStarted = false;
						isImageDrawingStarted = false;
						showAllButtons(gui);
					}
					break;

				// we don't process other types of events
				default:
					break;
			}
            gui.handleEvent(event); // Pass the event to the widgets
        }

        window.clear();
        gui.draw(); // Draw all widgets
		if(isLightraysStarted) lightrays.loop();
		if(isImageDrawingStarted) image_drawing.loop(); 
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

