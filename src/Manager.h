#include <TGUI/TGUI.hpp>
#include "Project_lightrays.h"
#include "Project_imageDrawing.h"

class Manager{


public:
	Manager(sf::RenderWindow& _window, tgui::Gui& _gui);
	void closeAll();
	void loop();

private:
	bool isLightraysActive = false;
	bool isImageDrawingActive = false;
	void hideAllGui();

	void startLightrays();
	void startImageDrawing();
	tgui::Gui& gui;
	sf::RenderWindow& window;
	Project_lightrays lightrays;
	Project_imageDrawing image_drawing;
    tgui::Button::Ptr b_lightrays;
	tgui::Button::Ptr b_imageDrawing;


};
