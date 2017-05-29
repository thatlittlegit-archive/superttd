//
// SuperTTD: camera 'class'
//
///
/// Creates a new camera. Takes three arguments:
///
/// * x: The x of where to draw the tiles of
/// * y: The y of where to draw the tiles of
/// * angle: The angle the camera is at. Can be 1, 2, 3 or 4.
///
pub fn new(x: u16, y: u16, angle: u8, is_main: bool) {
    println!("{0} {1} {2} {3}", x.to_string(), y.to_string(), angle.to_string(), is_main.to_string());
}
