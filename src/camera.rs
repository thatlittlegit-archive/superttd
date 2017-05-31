//
// SuperTTD: camera 'class'
//
extern crate sfml;

use sfml::graphics::RenderWindow;

///
/// Camera struct. **Use Camera::new instead.**
///
pub struct Camera<'a> {
    x: u16,
    y: u16,
    angle: u8,
    window: Option<&'a RenderWindow>
}

impl<'a> Camera<'a> {
    ///
    /// Creates a new camera. Takes three arguments:
    ///
    /// * x: The x of where to draw the tiles of
    /// * y: The y of where to draw the tiles of
    /// * angle: The angle the camera is at. Can be 1, 2, 3 or 4.
    /// * window: A pointer to the window, or None. If none, drawing logic will do nothing.
    ///
    pub fn new(x: u16, y: u16, angle: u8, window: Option<&RenderWindow>) -> Camera {
        Camera { x: x, y: y, angle: angle, window: window }
    }
}
