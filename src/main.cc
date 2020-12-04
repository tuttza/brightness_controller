#include <gtkmm.h>
#include <iostream>
#include "brightness.h"
#include "slider.h"

int main(int argc, char *argv[])
{
 Brightness brightness = Brightness();

 static const std::string app_id = "org.gtkmm.brightness_controller";
 
 auto app = Gtk::Application::create(argc, argv, app_id);

 Gtk::Window window;

 double d_max_value = static_cast<double>(brightness.max_value);
 double d_current_value = static_cast<double>(brightness.current_value);

 Slider *slider = new Slider(d_current_value, d_max_value);
 slider->set_draw_value();

 window.set_default_size(200, 400);
 window.add(*slider);
 window.show_all_children();

 return app->run(window);
}
