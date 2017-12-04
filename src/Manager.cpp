#include "Manager.h"

Manager::Manager(sf::RenderWindow& _window, tgui::Gui& _gui) : window(_window), gui(_gui), lightrays(window, gui), image_drawing(window)
{
	tgui::Theme::Ptr theme = tgui::Theme::create("/home/friso/tgui-git/src/TGUI/widgets/Black.txt");

	lightrays.stop();

    b_lightrays = theme->load("button");
	b_lightrays->setText("lightrays");
	b_lightrays->setSize(sf::Vector2f(200, 50));
	b_lightrays->connect("pressed", &Manager::startLightrays, this);
    b_lightrays->setPosition(400-b_lightrays->getSize().x/2, 200);

    b_imageDrawing = theme->load("button");
	b_imageDrawing->setText("image drawing");
	b_imageDrawing->setSize(sf::Vector2f(200, 50));
	b_imageDrawing->connect("pressed", &Manager::startImageDrawing, this);
    b_imageDrawing->setPosition(400-b_lightrays->getSize().x/2, 300);
    
    gui.add(b_lightrays, "button");
    gui.add(b_imageDrawing, "button2");
}

void Manager::closeAll(){
	isLightraysActive = false;
	isImageDrawingActive = false;
	lightrays.stop();
	image_drawing.stop();
	b_lightrays->show();
	b_imageDrawing->show();
}

void Manager::hideAllGui(){
	b_lightrays->hide();
	b_imageDrawing->hide();
	lightrays.stop(); //don't know if this is needed
}

void Manager::startLightrays(){
	hideAllGui();
	lightrays.start();
	isLightraysActive = true;
}

void Manager::startImageDrawing(){
	hideAllGui();
	isImageDrawingActive = true;
}

void Manager::loop(){
	if(isLightraysActive){
		lightrays.loop();
	}
	if(isImageDrawingActive){
		image_drawing.loop();
	}
}
