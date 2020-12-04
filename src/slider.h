#ifndef slider_h_INCLUDED
#define slider_h_INCLUDED

#include <glib.h>
#include <gtkmm/scale.h>
#include <gtkmm/adjustment.h>
#include <iostream>
#include "brightness.h"

/* 
 * ==[ Docs ]==
 * 	% Gtk::Scale: https://developer.gnome.org/gtkmm/stable/classGtk_1_1Scale.html
 * 	% Gtk::Adjustment: https://developer.gnome.org/gtkmm/stable/classGtk_1_1Adjustment.html
 * 	% Glib::RefPtr: https://developer.gnome.org/glibmm/stable/classGlib_1_1RefPtr.html
*/

class Slider : public Gtk::Scale
{

public:
  Slider();
  Slider(double low_value, double high_value);
  virtual ~Slider();

protected:
  void value_updated(Glib::ustring data);

private:
  Glib::RefPtr<Gtk::Adjustment> m_AdjustmentRef;
};

#endif // slider_h_INCLUDED

