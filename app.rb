#! /usr/bin/ruby

require 'mittens_ui'

app_options = {
  name: "brightness_controller",
  title: "Brightness Controller",
  height: 150,
  width: 350,
  can_resize: true
}.freeze

class Brightness
  attr_accessor :max_value, :current_value

  def initialize
    @current_path = "/sys/class/backlight/intel_backlight/brightness"
    @current_value = get_current
    @max_path = "/sys/class/backlight/intel_backlight/max_brightness"
    @max_value = get_max
  end

  def set(value)
    File.write(@current_path, value)
  end

  private

  def get_max
    File.open(@max_path, "r") { |f| f.read }.strip
  end

  def get_current
    File.open(@current_path, "r") { |f| f.read }.strip
  end
end

MittensUi::Application.Window(app_options) do |window, layout|
  brightness = Brightness.new

  label_opts = { top: 25 }
  MittensUi::Label("Current Brightness:", layout, label_opts)

  slider_opts = { 
    start_value: 1, 
    stop_value: brightness.max_value, 
    initial_value: brightness.current_value
  }.freeze

  MittensUi::Slider(layout, slider_opts) do |s|
    brightness.set(s.value.to_i.to_s)
  end
end