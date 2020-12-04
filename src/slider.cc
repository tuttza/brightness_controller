#include "slider.h"

Slider::Slider(double low_value, double max_value)
{
  this->m_AdjustmentRef = Gtk::Adjustment::create(low_value, 1, max_value); 

  set_adjustment(this->m_AdjustmentRef);

  signal_value_changed()
  .connect(
    sigc::bind<-1, 
    Glib::ustring>(sigc::mem_fun(*this, &Slider::value_updated), "value_changed")
  );
}

Slider::~Slider() {}

void Slider::value_updated(Glib::ustring data)
{
  Brightness brightness = Brightness();

  int new_current = static_cast<int>(this->get_value());

  brightness.set_current_value(new_current);
}
