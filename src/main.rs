extern crate sfml;

use sfml::graphics::RenderWindow;
use sfml::window::{VideoMode, ContextSettings, style};

fn main() {
   // CONSTANTS
   let antialiasing = 0;
   let game_width = 800;
   let game_height = 600;
   let vsync = true;

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

    loop {}
}
