extern crate sfml;

use sfml::graphics::RenderWindow;
use sfml::window::{VideoMode, ContextSettings, Event, style};

mod camera;

fn main() {
   print!("SuperTTD! Version 0.1.0\n");
   // CONSTANTS
   let antialiasing = 0;
   let game_width = 800;
   let game_height = 600;
   let vsync = true;

   print!("Antialiasing: {0} Width/Height: {1}/{2} Vsync: {3}\n", antialiasing, game_width, game_height, vsync);

   let settings = ContextSettings {
       antialiasing_level: antialiasing,
       ..Default::default()
   };

    let _window = RenderWindow::new(VideoMode::new(game_width, game_height, 32),
                                      "SuperTTD",
                                      style::CLOSE,
                                      &settings);
    let mut window = Option::expect(_window, "Window was not defined, this is a bug");
    window.set_vertical_sync_enabled(vsync);

    window.display();

    //
    // Initialize cameras
    //
    camera::new(1, 2, 3, Some(window));

    loop {
        for event in window.events() {
            if event == Event::Closed {
                return;
            }
        }
    }
}
