//
// SuperTTD: camera 'class'
//
extern crate sfml;

use sfml::graphics::RenderWindow;

///
/// Camera struct. **Use Camera::new instead.**
///
pub struct Camera {
    x: u16,
    y: u16,
    angle: u8,
    window: Option<RenderWindow>
}
///
/// Creates a new camera. Takes three arguments:
///
/// * x: The x of where to draw the tiles of
/// * y: The y of where to draw the tiles of
/// * angle: The angle the camera is at. Can be 1, 2, 3 or 4.
/// * window: The window, or None. If none, drawing logic will do nothing.
///
pub fn new(x: u16, y: u16, angle: u8, window: Option<RenderWindow>) -> Camera {
    println!("{0} {1} {2}", x.to_string(), y.to_string(), angle.to_string());
    Camera { x: x, y: y, angle: angle, window: window }
}
